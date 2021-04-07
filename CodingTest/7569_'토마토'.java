import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Coordinate7569{
    int x, y, z;

    Coordinate7569(int x, int y, int z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class B7569{
    protected int[][][] tomatoBox;
    protected int M, N, H;

    B7569() throws Exception{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        tomatoBox = new int[H + 2][N + 2][M + 2];

        for(int z=0; z<H+2; z++){
            for(int y=0; y<N+2; y++){
                for(int x=0; x<M+2; x++){
                    tomatoBox[z][y][x] = -1;
                }
            }
        }

        for(int z = H; z >= 1; z--) {
            for (int y = 1; y <= N; y++) {
                st = new StringTokenizer(bf.readLine());

                for (int x = 1; x <= M; x++)
                    tomatoBox[z][y][x] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public boolean isZeroExist(){
        boolean result = false;

        for(int z=1; z<=H; z++){
            for(int y=1; y<=N; y++){
                for(int x=1; x<=M; x++){
                    if(tomatoBox[z][y][x] == 0){
                        result = true;
                        break;
                    }
                }
                if(result == true) break;
            }
            if(result == true) break;
        }

        return result;
    }

    public int BFS(){
        int day = 0;
        Queue<Coordinate7569> q = new LinkedList<Coordinate7569>();

        if(!isZeroExist()) return 0;

        for(int z=1; z<=H; z++){
            for(int y=1; y<=N; y++){
                for(int x=1; x<=M; x++){
                    if(tomatoBox[z][y][x] == 1){
                        Coordinate7569 startPoint = new Coordinate7569(x,y,z);
                        q.add(startPoint);
                    }
                }
            }
        }

        while(true){
            int todayTomato = q.size();

            if(todayTomato == 0) break;
            else {
                if(!isZeroExist()) break;

                day++;

                for(int i=0; i<todayTomato; i++) {
                    int x = q.peek().x;
                    int y = q.peek().y;
                    int z = q.peek().z;

                    q.poll();

                    if (tomatoBox[z + 1][y][x] == 0) {
                        tomatoBox[z + 1][y][x] = 1;
                        q.add(new Coordinate7569(x, y, z + 1));
                    }
                    if (tomatoBox[z - 1][y][x] == 0) {
                        tomatoBox[z - 1][y][x] = 1;
                        q.add(new Coordinate7569(x, y, z - 1));
                    }
                    if (tomatoBox[z][y + 1][x] == 0) {
                        tomatoBox[z][y + 1][x] = 1;
                        q.add(new Coordinate7569(x, y + 1, z));
                    }
                    if (tomatoBox[z][y - 1][x] == 0) {
                        tomatoBox[z][y - 1][x] = 1;
                        q.add(new Coordinate7569(x, y - 1, z));
                    }
                    if (tomatoBox[z][y][x + 1] == 0) {
                        tomatoBox[z][y][x + 1] = 1;
                        q.add(new Coordinate7569(x + 1, y, z));
                    }
                    if (tomatoBox[z][y][x - 1] == 0) {
                        tomatoBox[z][y][x - 1] = 1;
                        q.add(new Coordinate7569(x - 1, y, z));
                    }
                }
            }
        }

        return day;
    }

    public void solution(){
        int answer = BFS();

        if(isZeroExist()) answer = -1;

        System.out.println(answer);
    }
}

class Main7569 {
    public static void main(String[] args) throws Exception{
        B7569 b = new B7569();
        b.solution();
    }
}