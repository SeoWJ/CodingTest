class Solution43165 {
    int answer;
    int[] numbers;
    int target;

    public void DFS(int index, int currentResult){
        if(index == numbers.length){
            if(currentResult == target)
                answer++;

            return;
        }

        DFS(index + 1, currentResult + numbers[index]);
        DFS(index + 1, currentResult - numbers[index]);
    }

    public int solution(int[] numbers, int target) {
        answer = 0;
        this.numbers = numbers;
        this.target = target;

        DFS(0, 0);

        return answer;
    }
}

class Main43165{
    public static void main(String[] args){
        Solution43165 s = new Solution43165();
        int[] a = {1,1,1,1,1};
        s.solution(a, 3);
    }
}