import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class B11286{
    protected int N;
    protected BufferedReader bf;
    protected Hashtable<Integer, Deque<Integer>> hashtable;
    protected PriorityQueue<Integer> pq;

    B11286() throws Exception{
        bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());

        hashtable = new Hashtable<>();
        pq = new PriorityQueue<>();
    }

    public int ABS(int num){
        return num > 0 ? num : num * -1;
    }

    public void solution() throws Exception{
        for(int i=0; i<N; i++) {
            int query = Integer.parseInt(bf.readLine());

            if(query == 0){
                if(pq.isEmpty())
                    System.out.println(0);
                else{
                    int key = pq.poll();

                    System.out.println(hashtable.get(key).getFirst());
                    hashtable.get(key).removeFirst();
                }
            }
            else{
                int key = ABS(query);

                if(!hashtable.containsKey(key))


                if(query > 0)
                    hashtable.get(key).addLast(query);
                else
                    hashtable.get(key).addFirst(query);

                pq.add(key);
            }
        }
    }
}

class Main11286{
    public static void main(String[] args) throws Exception{
        B11286 b = new B11286();
        b.solution();
    }
}