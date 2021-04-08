import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class QueueNode_16928{
    int diceCount;
    int currentPosition;

    QueueNode_16928(int diceCount, int currentPosition){
        this.diceCount = diceCount;
        this.currentPosition = currentPosition;
    }
}
class B16928{
    protected int N, M;
    protected int[] gameBoard;
    protected boolean[] visit;

    B16928() throws Exception{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        gameBoard = new int[101];
        visit = new boolean[101];

        for(int i=0; i<101; i++) { gameBoard[i] = i; visit[i] = false; }

        for(int i=0; i<N; i++){
            st = new StringTokenizer(bf.readLine());

            int start = Integer.parseInt(st.nextToken());
            int destination = Integer.parseInt(st.nextToken());

            gameBoard[start] = destination;
        }

        for(int i=0; i<M; i++){
            st = new StringTokenizer(bf.readLine());

            int start = Integer.parseInt(st.nextToken());
            int destination = Integer.parseInt(st.nextToken());

            gameBoard[start] = destination;
        }
    }

    public void solution() {
        int answer = 0x7FFFFFFF;

        Queue<QueueNode_16928> Q = new LinkedList<>();
        Q.add(new QueueNode_16928(0, 1));
        visit[1] = true;

        while(!Q.isEmpty()){
            int diceCount = Q.peek().diceCount;
            int currentPosition = Q.peek().currentPosition;

            Q.poll();

            if(currentPosition == 100)
                answer = answer < diceCount ? answer : diceCount;

            for(int i=1; i <= 6 && currentPosition + i <= 100; i++) {
                if(visit[currentPosition + i] == false){
                    Q.add(new QueueNode_16928(diceCount + 1, gameBoard[currentPosition + i]));
                    visit[currentPosition + i] = true;
                }
            }
        }

        System.out.println(answer);
    }
}

class Main16928{
    public static void main(String[] args) throws Exception{
        B16928 b = new B16928();
        b.solution();
    }
}