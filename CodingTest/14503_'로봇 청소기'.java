import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class B14503{
    int N, M;
    int robotX, robotY, robotDirection;
    int[][] map;
    int answer;

    final int NORTH = 0;
    final int EAST = 1;
    final int SOUTH = 2;
    final int WEST = 3;

    B14503() throws Exception{
        answer = 0;

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N + 2][M + 2];

        for(int y=0; y<N+2; y++) Arrays.fill(map[y], 1);

        st = new StringTokenizer(bf.readLine());

        robotY = Integer.parseInt(st.nextToken()) + 1;
        robotX = Integer.parseInt(st.nextToken()) + 1;
        robotDirection = Integer.parseInt(st.nextToken());

        for(int y=1; y<=N; y++){
            st = new StringTokenizer(bf.readLine());

            for(int x=1; x<=M; x++)
                map[y][x] = Integer.parseInt(st.nextToken());
        }
    }

    public void DFS(int x, int y, int direction, int turnCount){
        if(map[y][x] == 0){
            map[y][x] = 2;
            answer++;
        }

        if(turnCount == 4){
            if(direction == NORTH && map[y + 1][x] == 2)
                DFS(x, y+1, NORTH, 0);
            else if(direction == WEST && map[y][x + 1] == 2)
                DFS(x+1, y, NORTH, 0);
            else if(direction == SOUTH && map[y - 1][x] == 2)
                DFS(x, y-1, NORTH, 0);
            else if(direction == EAST && map[y][x - 1] == 2)
                DFS(x-1, y, NORTH, 0);

            else if(direction == NORTH && map[y + 1][x] == 1)
                return;
            else if(direction == WEST && map[y][x + 1] == 1)
                return;
            else if(direction == SOUTH && map[y - 1][x] == 1)
                return;
            else if(direction == EAST && map[y][x - 1] == 1)
                return;
        }
        else {
            if (direction == NORTH && map[y][x - 1] == 0)
                DFS(x - 1, y, WEST, 0);
            else if (direction == WEST && map[y + 1][x] == 0)
                DFS(x, y + 1, SOUTH, 0);
            else if (direction == SOUTH && map[y][x + 1] == 0)
                DFS(x + 1, y, EAST, 0);
            else if (direction == EAST && map[y - 1][x] == 0)
                DFS(x, y - 1, NORTH, 0);
            else
                DFS(x, y, (direction - 1 >= 0 ? direction - 1 : WEST), turnCount + 1);
        }
    }

    public void solution(){
        DFS(robotX, robotY, robotDirection, 0);

        System.out.println(answer);
    }
}

class Main_14503{
    public static void main(String[] args) throws Exception{
        B14503 b = new B14503();
        b.solution();
    }
}