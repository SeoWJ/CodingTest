import java.util.*;

class Solution77485 {
    int[][] matrix;

    public int rotate(int[] query){
        int startY = query[0] - 1;
        int startX = query[1] - 1;
        int endY = query[2] - 1;
        int endX = query[3] - 1;

        List<Integer[]> changeList = new ArrayList<>();
        List<Integer> contentsList = new ArrayList<>();

        for(int x=startX; x<=endX; x++){
            Integer[] coordinate = {x, startY};
            changeList.add(coordinate);
            contentsList.add(matrix[startY][x]);
        }

        for(int y=startY + 1; y<=endY; y++){
            Integer[] coordinate = {endX, y};
            changeList.add(coordinate);
            contentsList.add(matrix[y][endX]);
        }

        for(int x=endX - 1; x>=startX; x--){
            Integer[] coordinate = {x, endY};
            changeList.add(coordinate);
            contentsList.add(matrix[endY][x]);
        }

        for(int y=endY - 1; y>startY; y--){
            Integer[] coordinate = {startX, y};
            changeList.add(coordinate);
            contentsList.add(matrix[y][startX]);
        }

        int minimum = 0x7FFFFFFF;
        for(int i=1; i<changeList.size(); i++){
            int x = changeList.get(i)[0];
            int y = changeList.get(i)[1];

            matrix[y][x] = contentsList.get(i-1);
            minimum = minimum < contentsList.get(i-1) ? minimum : contentsList.get(i-1);
        }
        matrix[changeList.get(0)[1]][changeList.get(0)[0]] = contentsList.get(contentsList.size() - 1);
        minimum = minimum < contentsList.get(contentsList.size() - 1) ? minimum : contentsList.get(contentsList.size() - 1);

        return minimum;
    }

    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = {};
        matrix = new int[rows][columns];
        List<Integer> answerList = new ArrayList<>();

        int num = 1;
        for(int y=0; y<rows; y++){
            for(int x=0; x<columns; x++){
                matrix[y][x] = num++;
            }
        }

        for(int[] query : queries)
            answerList.add(rotate(query));

        answer = new int[answerList.size()];
        for(int i=0; i<answerList.size(); i++) answer[i] = answerList.get(i);

        return answer;
    }
}

class Main77485{
    public static void main(String[] args){
        Solution77485 s = new Solution77485();
        int[][] queries = {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}};
        s.solution(3,3,queries);
    }
}