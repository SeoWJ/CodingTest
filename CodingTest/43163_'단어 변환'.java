class Solution43163 {
    String[] words;
    String target;
    int answer;

    public boolean canChange(String word, String next){
        int difference = 0;
        for(int i=0; i<word.length(); i++){
            if(word.charAt(i) == next.charAt(i))
                continue;
            else
                difference++;
        }

        if(difference == 1)
            return true;
        else
            return false;
    }
    public void DFS(String currentWord, boolean[] used, int changeCount){
        if(currentWord.equals(target)) {
            answer = answer < changeCount ? answer : changeCount;
            return;
        }

        for(int i=0; i<used.length; i++){
            if(used[i] == false && canChange(currentWord, words[i])){
                boolean[] temp = used.clone();
                temp[i] = true;

                DFS(words[i], temp, changeCount + 1);
            }
        }
    }
    public int solution(String begin, String target, String[] words) {
        this.answer = 0x7FFFFFFF;
        this.words = words;
        this.target = target;

        boolean[] used = new boolean[words.length];

        DFS(begin, used, 0);

        if(answer == 0x7FFFFFFF)
            return 0;
        else
            return answer;
    }
}

class Main43163{
    public static void main(String[] args){
        Solution43163 s = new Solution43163();
        String[] words = {"hot", "dot", "dog", "lot", "log", "cog"};
        s.solution("hit", "cog", words);
    }
}