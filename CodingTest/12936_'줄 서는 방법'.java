import java.util.*;

class Solution12936 {
    List<Integer> answerList;
    List<Integer> restPeople;

    public long factorial(int num){
        return num <= 1 ? 1 : num * factorial(num - 1);
    }

    public void DFS(int n, long k){
        long standard = factorial(n - 1);

        int q = (int)(k / standard);
        int r = (int)(k % standard);

        answerList.add(restPeople.get(q));
        restPeople.remove(q);
        k -= q * standard;

        if(n - 1 == 0)
            return;
        else
            DFS(n - 1, k);
    }

    public int[] solution(int n, long k) {
        int[] answer = {};
        answerList = new ArrayList<Integer>();
        restPeople = new ArrayList<Integer>();

        for(int i=1; i<=n; i++)
            restPeople.add(i);

        DFS(n, k - 1);

        answer = new int[answerList.size()];

        for(int i=0; i<answerList.size(); i++)
            answer[i] = answerList.get(i);

        return answer;
    }
}

class Main12936{
    public static void main(String[] args){
        Solution12936 s = new Solution12936();
        s.solution(3, 5);
    }
}