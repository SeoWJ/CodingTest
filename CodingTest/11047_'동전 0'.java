import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class B11047{
    protected int N, K;
    protected int[] coins;

    B11047() throws Exception{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        coins = new int[N];

        for(int i=0; i<N; i++){
            coins[i] = Integer.parseInt(bf.readLine());
        }
    }

    public void solution(){
        int answer = 0;

        for(int i=N-1; i>=0; i--){
            if(K >= coins[i]){
                answer += (K / coins[i]);
                K %= coins[i];
            }

            if(K <= 0)
                break;
        }

        System.out.println(answer);
    }
}

class Main11047{
    public static void main(String[] args) throws Exception{
        B11047 b = new B11047();
        b.solution();
    }
}