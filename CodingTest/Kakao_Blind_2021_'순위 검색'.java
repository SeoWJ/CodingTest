import java.util.*;

class Solution72412 {
    HashMap<String, Integer> define;
    List<List<List<List<List<Integer>>>>> database;

    public int find(List<Integer> databaseIndex, int targetScore){
        List<Integer> list = database.get(databaseIndex.get(0)).get(databaseIndex.get(1)).get(databaseIndex.get(2)).get(databaseIndex.get(3));
        if(list.size() <= 3){

            int start = 0;
            for(int i=0; i<list.size(); i++){
                if(list.get(i) < targetScore)
                    start++;
                else
                    break;
            }

            return list.size() - start;
        }
        else {
            int left = 0, right = list.size() - 1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if(targetScore <= list.get(mid) && (mid == 0 || list.get(mid - 1) < targetScore))
                    return list.size() - mid;
                else{
                    if(list.get(mid) < targetScore)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }

        return 0;
    }

    public int getResult(List<Integer> databaseIndex, String[] query, int queryIndex){
        if(queryIndex == 4){
            return find(databaseIndex, Integer.parseInt(query[queryIndex]));
        }
        if(define.get(query[queryIndex]) == -1){
            int result = 0;
            if(queryIndex == 0){
                for(int i=0; i<3; i++){
                    databaseIndex.add(i);
                    result += getResult(databaseIndex, query, queryIndex + 1);
                    databaseIndex.remove(databaseIndex.size() - 1);
                }
            }
            else{
                for(int i=0; i<2; i++){
                    databaseIndex.add(i);
                    result += getResult(databaseIndex, query, queryIndex + 1);
                    databaseIndex.remove(databaseIndex.size() - 1);
                }
            }
            return result;
        }
        else if(define.get(query[queryIndex]) == 0){
            databaseIndex.add(0);
            int result = getResult(databaseIndex, query, queryIndex + 1);
            databaseIndex.remove(databaseIndex.size() - 1);

            return result;
        }
        else if(define.get(query[queryIndex]) == 1){
            databaseIndex.add(1);
            int result = getResult(databaseIndex, query, queryIndex + 1);
            databaseIndex.remove(databaseIndex.size() - 1);

            return result;
        }
        else if(define.get(query[queryIndex]) == 2){
            databaseIndex.add(2);
            int result = getResult(databaseIndex, query, queryIndex + 1);
            databaseIndex.remove(databaseIndex.size() - 1);

            return result;
        }

        return 0;
    }

    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];

        define = new HashMap<>();
        define.put("-", -1);
        define.put("cpp", 0);
        define.put("java", 1);
        define.put("python", 2);
        define.put("backend", 0);
        define.put("frontend", 1);
        define.put("junior", 0);
        define.put("senior", 1);
        define.put("chicken", 0);
        define.put("pizza", 1);

        String[][] infoes = new String[info.length][];
        String[][] queries = new String[query.length][];

        for(int i=0; i<info.length; i++)
            infoes[i] = info[i].split(" ");

        for(int i=0; i<query.length; i++){
            String[] temp = query[i].split(" ");
            List<String> l = Arrays.asList(temp);
            List<String> ll = new ArrayList<>();
            for(String s : l){
                if(!s.equals("and")) ll.add(s);
            }
            queries[i] = ll.toArray(new String[ll.size()]);
        }

        database = new ArrayList<>();
        for(int i=0; i<3; i++)
            database.add(new ArrayList<>());
        for(int i=0; i<3; i++){
            for(int j=0; j<2; j++)
                database.get(i).add(new ArrayList<>());
        }
        for(int i=0; i<3; i++) {
            for (int j = 0; j < 2; j++){
                for(int k=0; k<2; k++)
                    database.get(i).get(j).add(new ArrayList<>());
            }
        }
        for(int i=0; i<3; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for(int l=0; l<2; l++)
                        database.get(i).get(j).get(k).add(new ArrayList<>());
                }
            }
        }

        for(String[] data : infoes){
            database.get(define.get(data[0])).get(define.get(data[1])).get(define.get(data[2])).get(define.get(data[3])).add(Integer.parseInt(data[4]));
        }

        for(int i=0; i<3; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for(int l=0; l<2; l++)
                        Collections.sort(database.get(i).get(j).get(k).get(l));
                }
            }
        }

        List<Integer> answerList = new ArrayList<>();
        for(String[] q : queries){
            answerList.add(getResult(new ArrayList<>(), q, 0));
        }

        answer = new int[answerList.size()];
        for(int i=0; i<answerList.size(); i++) answer[i] = answerList.get(i);

        return answer;
    }
}

class Main72412{
    public static void main(String[] args){
        Solution72412 s = new Solution72412();
        String[] info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
        String[] query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
        s.solution(info, query);
    }
}