import java.util.*;

class Solution42839 {
    List<Integer> numbersListOriginal;
    List<Integer> answerList;
    boolean[] erathosthenes;
    int answer;

    public void bruteForce(String number, List<Integer> numbersList){
        if(!number.equals("") && erathosthenes[Integer.parseInt(number)] == true) {
            answerList.add(Integer.parseInt(number));
        }

        for(int i=0; i<numbersList.size(); i++){
            List<Integer> temp = new ArrayList<>();
            temp.addAll(numbersList);
            String numberNext = number;

            numberNext += temp.get(i);
            temp.remove(i);

            bruteForce(numberNext, temp);
        }
    }

    public void erathosthenesSeive(){
        erathosthenes[0] = erathosthenes[1] = false;
        for(int i=2; i<10000001; i++)
            erathosthenes[i] = true;

        for(int i=2; i<=Math.sqrt(10000000); i++){
            for(int j = i*2; j<10000001; j+=i){
                erathosthenes[j] = false;
            }
        }
    }

    public int solution(String numbers) {
        answer = 0;
        numbersListOriginal = new ArrayList<Integer>();
        answerList = new ArrayList<Integer>();
        erathosthenes = new boolean[10000001];

        erathosthenesSeive();

        for(int i=0; i<numbers.length(); i++){
            numbersListOriginal.add(numbers.charAt(i) - '0');
        }

        List<Integer> numbersList = new ArrayList<>();
        numbersList.addAll(numbersListOriginal);

        bruteForce("", numbersList);

        HashSet<Integer> hashSet = new HashSet<>(answerList);

        answer = hashSet.size();

        return answer;
    }
}

class Main42839{
    public static void main(String args[]){
        Solution42839 s = new Solution42839();
        System.out.println(s.solution("123"));

    }
}