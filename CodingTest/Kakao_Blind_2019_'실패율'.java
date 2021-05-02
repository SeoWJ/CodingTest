import java.util.*;

class Solution42889 {
    class StageInfo implements Comparable<StageInfo>{
        int stageNumber;
        int uncleared;
        int reached;

        StageInfo(int stageNumber){
            this.stageNumber = stageNumber;
            uncleared = 0;
            reached = 0;
        }

        public double failureRate(){
            if(reached == 0)
                return 0;
            else
                return (double)uncleared / (double)reached;
        }

        @Override
        public int compareTo(StageInfo o){
            if(o.failureRate() - this.failureRate() > 0)
                return 1;
            else if(o.failureRate() - this.failureRate() < 0)
                return -1;
            else
                return this.stageNumber - o.stageNumber;
        }
    }

    public int[] solution(int N, int[] stages) {
        int[] answer = {};

        List<StageInfo> stageInfoList = new ArrayList<>();
        for(int i=1; i<=N; i++)
            stageInfoList.add(new StageInfo(i));

        for(int i=0; i<stages.length; i++){
            for(int j=1; j<stages[i]; j++)
                stageInfoList.get(j-1).reached++;

            if(stages[i] <= N) {
                stageInfoList.get(stages[i] - 1).reached++;
                stageInfoList.get(stages[i] - 1).uncleared++;
            }
        }

        Collections.sort(stageInfoList);

        answer = new int[N];

        for(int i=0; i<stageInfoList.size(); i++)
            answer[i] = stageInfoList.get(i).stageNumber;

        return answer;
    }
}