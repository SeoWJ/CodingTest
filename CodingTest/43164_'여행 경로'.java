import java.util.*;

class Solution43164 {
    String[][] tickets;
    List<String> route;

    boolean stringCompare(String s1, String s2){
        for(int i=0; i<s1.length(); i++){
            if(s1.charAt(i) < s2.charAt(i))
                return true;
            else if(s1.charAt(i) > s2.charAt(i))
                return false;
        }

        return true;
    }

    void DFS(List<String> route, boolean[] ticketUsed){
        if(route.size() == tickets.length + 1){
            if(this.route.isEmpty()){
                this.route.addAll(route);
            }
            else{
                for(int i=0; i<route.size(); i++){
                    if(this.route.get(i).equals(route.get(i)))
                        continue;
                    else{
                        if(stringCompare(route.get(i), this.route.get(i)) == true){
                            this.route.clear();
                            this.route.addAll(route);
                        }
                        else
                            return;
                    }
                }
            }
            return;
        }

        String currentAirport = route.get(route.size() - 1);

        for(int i=0; i<tickets.length; i++){
            if(tickets[i][0].equals(currentAirport) && ticketUsed[i] == false){
                route.add(tickets[i][1]);
                ticketUsed[i] = true;

                DFS(route, ticketUsed);

                ticketUsed[i] = false;
                route.remove(route.size() - 1);
            }
        }
    }

    public String[] solution(String[][] tickets) {
        String[] answer = {};
        this.tickets = tickets;
        this.route = new ArrayList<String>();

        for(int i=0; i<tickets.length; i++){
            if(tickets[i][0].equals("ICN")){
                List<String> route = new ArrayList<String>();
                boolean[] ticketUsed = new boolean[tickets.length];

                route.add(tickets[i][0]);
                route.add(tickets[i][1]);
                ticketUsed[i] = true;

                DFS(route, ticketUsed);
            }
        }

        answer = this.route.toArray(new String[this.route.size()]);

        return answer;
    }
}

class Main43164{
    public static void main(String[] args){
        Solution43164 s = new Solution43164();
        String[][] tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
        s.solution(tickets);
    }
}