import java.util.*;

class Solution42842 {
    public int[] solution(int brown, int yellow) {
        int[] answer = {};
        Integer[] k;

        for(int yellowHeight = 1; yellowHeight <= yellow; yellowHeight++){
            if(yellow % yellowHeight == 0){
                int yellowWidth = yellow / yellowHeight;

                int brownWidth = yellowWidth + 2;
                int brownHeight = yellowHeight;

                if(brownWidth * 2 + brownHeight * 2 == brown){
                    List<Integer> l = new ArrayList<>();
                    l.add(brownWidth);
                    l.add(brownHeight + 2);

                    answer = new int[l.size()];
                    answer[0] = l.get(0);
                    answer[1] = l.get(1);
                    k = l.toArray(new Integer[l.size()]);

                    break;
                }
            }
        }

        return answer;
    }
}