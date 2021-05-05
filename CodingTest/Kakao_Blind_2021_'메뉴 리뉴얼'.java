import java.util.*;

class Solution72411 {
    class orderedCountAndCombination{
        int orderedCount;
        List<List<Character>> combinations;

        orderedCountAndCombination(int o){
            this.orderedCount = o;
            combinations = new ArrayList<>();
        }
    }

    List<Character>[] ordersList;
    List<Integer> courseList;
    HashSet<List<Character>> allCombinations;

    public void bruteforce(List<Character> order, List<Character> combination){
        if(courseList.contains(combination.size())){
            List<Character> c = new ArrayList<>();
            c.addAll(combination);
            allCombinations.add(c);
        }

        for(int i=combination.isEmpty() ? 0 : order.indexOf(combination.get(combination.size() - 1)) + 1; i<order.size(); i++){
            combination.add(order.get(i));

            bruteforce(order, combination);

            combination.remove(combination.size() - 1);
        }
    }

    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};

        this.courseList = new ArrayList<>();
        for(int i : course) courseList.add(i);
        allCombinations = new HashSet<>();
        ordersList = new ArrayList[orders.length];

        for(int y=0; y<orders.length; y++){
            ordersList[y] = new ArrayList<>();

            for(int x=0; x<orders[y].length(); x++)
                ordersList[y].add(orders[y].charAt(x));

            Collections.sort(ordersList[y]);
        }

        for(List<Character> order : ordersList) {
            List<Character> combination = new ArrayList<>();

            bruteforce(order, combination);
        }

        HashMap<Integer, orderedCountAndCombination> result = new HashMap<>();
        for(List<Character> l : allCombinations){
            int orderedCount = 0;

            for(List<Character> order : ordersList){
                if(order.containsAll(l))
                    orderedCount++;
            }

            if(orderedCount >= 2) {
                if (!result.containsKey(l.size())) {
                    result.put(l.size(), new orderedCountAndCombination(orderedCount));
                    result.get(l.size()).combinations.add(l);
                } else {
                    if (result.get(l.size()).orderedCount < orderedCount) {
                        result.get(l.size()).orderedCount = orderedCount;
                        result.get(l.size()).combinations.clear();
                        result.get(l.size()).combinations.add(l);
                    } else if (result.get(l.size()).orderedCount == orderedCount)
                        result.get(l.size()).combinations.add(l);
                    else
                        continue;
                }
            }
        }

        List<String> answerList = new ArrayList<>();
        for(Integer i : result.keySet()){
            for(List<Character> l : result.get(i).combinations){
                String temp = "";

                for(char c : l) temp += c;

                answerList.add(temp);
            }
        }

        Collections.sort(answerList);

        answer = answerList.toArray(new String[answerList.size()]);

        return answer;
    }
}

class Main72411{
    public static void main(String[] args){
        Solution72411 s = new Solution72411();
        String[] orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
        int[] course = {2,3,4};
        s.solution(orders, course);
    }
}