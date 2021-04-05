import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class B1421{
    public int N, C, W;
    int[] trees;
    int answer;

    B1421() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        trees = new int[N];

        for(int i=0; i<N; i++)
            trees[i] = Integer.parseInt(br.readLine());
    }
    int max(int[] trees){
        int result = 0;

        for(int t : trees)
            result = result > t ? result : t;

        return result;
    }
    int bruteForce(){
        int longestTree = max(trees);
        int maxProfit = 0;

        for(int cutStandard = 1; cutStandard <= longestTree; cutStandard++){
            int profit = 0;
            int cuttedTreeCount = 0;
            int cutCount = 0;

            for(int tree : trees){
                if(tree % cutStandard == 0){
                    if((tree / cutStandard - 1) * C >= (tree / cutStandard) * W)
                        continue;
                    else {
                        cutCount += (tree / cutStandard - 1);
                        cuttedTreeCount += (tree / cutStandard);
                    }
                }
                else{
                    if((tree / cutStandard) * C >= (tree / cutStandard) * W)
                        continue;
                    else{
                        cutCount += (tree / cutStandard);
                        cuttedTreeCount += (tree / cutStandard);
                    }
                }
            }

            profit = cuttedTreeCount * W - cutCount * C;

            maxProfit = maxProfit > profit ? maxProfit : profit;
        }

        return maxProfit;
    }
    void solution(){
        System.out.println(bruteForce());
    }
}

class Main1421{
    public static void main(String[] args) throws Exception{
        B1421 b = new B1421();
        b.solution();
    }
}