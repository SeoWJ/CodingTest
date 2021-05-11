import java.util.*;

class Solution77486 {
    class Node{
        String name;
        String supervisor;
        int profit;

        Node(String name, String supervisor){
            this.name = name;
            this.supervisor = supervisor;
            profit = 0;
        }
    }

    HashMap<String, Node> tree;

    public void sell(String seller, int profit){
        Node sellerNode = tree.get(seller);

        if(!sellerNode.supervisor.equals("")){
            sellerNode.profit += profit - (profit / 10);
            sell(sellerNode.supervisor, profit / 10);
        }
        else
            sellerNode.profit += profit;
    }

    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = {};
        tree = new HashMap<>();

        tree.put("center", new Node("center", ""));

        for(int i=0; i<referral.length; i++) {
            tree.put(enroll[i], new Node(enroll[i], !referral[i].equals("-") ? referral[i] : "center"));
        }

        for(int i=0; i<seller.length; i++)
            sell(seller[i], amount[i] * 100);

        answer = new int[enroll.length];
        for(int i=0; i<answer.length; i++)
            answer[i] = tree.get(enroll[i]).profit;

        return answer;
    }
}

class Main77486{
    public static void main(String[] args){
        String[] enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
        String[] referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
        String[] seller = {"young", "john", "tod", "emily", "mary"};
        int[] amount = {12, 4, 2, 5, 10};

        Solution77486 s = new Solution77486();
        s.solution(enroll, referral, seller, amount);
    }
}