import java.util.*;

class Solution42890 {
    String[][] relation;
    List<List<Integer>> candidateKeyList;

    public boolean check(List<Integer> list){
        HashMap<String, Integer> hashMap = new HashMap<>();

        for(int y=0; y<relation.length; y++){
            String key = "";

            for(int i=0; i<list.size(); i++)
                key += relation[y][list.get(i)];

            if(hashMap.containsKey(key))
                return false;
            else
                hashMap.put(key, 1);
        }

        return true;
    }

    public void bruteforce(List<Integer> list){
        if(check(list)) {
            List<Integer> temp = new ArrayList<>();
            temp.addAll(list);
            candidateKeyList.add(temp);
        }

        int startIndex = list.get(list.size() - 1);

        for(int index = startIndex + 1; index < relation[0].length; index++){
            list.add(index);

            bruteforce(list);

            list.remove(list.size() - 1);
        }
    }

    public int solution(String[][] relation) {
        int answer = 0;
        this.relation = relation;
        candidateKeyList = new ArrayList<>();

        for(int x=0; x<relation[0].length; x++) {
            List<Integer> list = new ArrayList<>();
            list.add(x);
            bruteforce(list);
        }

        Collections.sort(candidateKeyList, new Comparator<List<Integer>>(){
            @Override
            public int compare(List<Integer> o1, List<Integer> o2){
                return o2.size() - o1.size();
            }
        });

        boolean[] valid = new boolean[candidateKeyList.size()];
        Arrays.fill(valid, true);
        for(int i=0; i<candidateKeyList.size(); i++){
            for(int j=i+1; j<candidateKeyList.size(); j++){
                if(candidateKeyList.get(i).containsAll(candidateKeyList.get(j))) {
                    valid[i] = false;
                    break;
                }
            }
        }

        for(boolean b : valid){
            if(b) answer++;
        }

        return answer;
    }
}

class Main42890{
    public static void main(String[] args){
        Solution42890 s = new Solution42890();
        String[][] relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
        s.solution(relation);
    }
}