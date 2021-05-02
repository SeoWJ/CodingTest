import java.util.*;

class Solution42892 {
    class Node{
        int nodeNumber;
        int x, y;

        Node(){
            this.nodeNumber = -1;
            this.x = this.y = -1;
        }
        Node(int nodeNumber, int x, int y){
            this.nodeNumber = nodeNumber;
            this.x = x;
            this.y = y;
        }
        boolean isNull(){
            return this.nodeNumber == -1 ? true : false;
        }
        void setNode(int nodeNumber, int x, int y){
            this.nodeNumber = nodeNumber;
            this.x = x;
            this.y = y;
        }
    }
    class BinarySearchTree{
        Node[] tree;

        BinarySearchTree(int height){
            int size = 1;

            while(height > 0){
                size *= 2;
                height--;
            }

            tree = new Node[size];
        }

        public int findNode(int[] node){
            int currentNode = 1;

            while(!(tree[currentNode] == null)){
                if(node[0] < tree[currentNode].x)
                    currentNode *= 2;
                else
                    currentNode = currentNode * 2 + 1;
            }

            return currentNode;
        }

        public void insertNode(int[][] nodeinfo){
            for(int i=0; i<nodeinfo.length; i++)
                insertNode(nodeinfo[i]);
        }

        public void insertNode(int[] node){
            if(tree[1] == null)
                tree[1] = new Node(node[2], node[0], node[1]);
            else
                tree[findNode(node)] = new Node(node[2], node[0], node[1]);
        }

        public void preorderTraverse(List<Integer> visited, int currentNode){
            visited.add(tree[currentNode].nodeNumber);

            if(tree[currentNode * 2] != null)
                preorderTraverse(visited, currentNode * 2);
            if(tree[currentNode * 2 + 1] != null)
                preorderTraverse(visited, currentNode * 2 + 1);
        }

        public void postorderTraverse(List<Integer> visited, int currentNode){
            if(tree[currentNode * 2] != null)
                postorderTraverse(visited, currentNode * 2);
            if(tree[currentNode * 2 + 1] != null)
                postorderTraverse(visited, currentNode * 2 + 1);

            visited.add(tree[currentNode].nodeNumber);
        }
    }
    public int[][] solution(int[][] nodeinfo) {
        int[][] answer = {};
        List<Integer> preorderResult = new ArrayList<Integer>();
        List<Integer> postorderResult = new ArrayList<Integer>();

        for(int i=0; i<nodeinfo.length; i++){
            int x = nodeinfo[i][0];
            int y = nodeinfo[i][1];

            nodeinfo[i] = new int[3];

            nodeinfo[i][0] = x;
            nodeinfo[i][1] = y;
            nodeinfo[i][2] = i + 1;
        }

        Arrays.sort(nodeinfo, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2){
                if(o1[1] != o2[1])
                    return o2[1] - o1[1];
                else
                    return o1[0] - o2[0];
            }
        });

        BinarySearchTree binarySearchTree = new BinarySearchTree(nodeinfo[0][1]);
        binarySearchTree.insertNode(nodeinfo);
        binarySearchTree.preorderTraverse(preorderResult, 1);
        binarySearchTree.postorderTraverse(postorderResult, 1);

        answer = new int[2][nodeinfo.length];

        for(int i=0; i<nodeinfo.length; i++)
            answer[0][i] = preorderResult.get(i);
        for(int i=0; i<nodeinfo.length; i++)
            answer[1][i] = postorderResult.get(i);

        return answer;
    }
}

class Main42892{
    public static void main(String[] args){
        Solution42892 s = new Solution42892();
        int[][] nodeinfo = {
                {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}
        };
        s.solution(nodeinfo);
    }
}