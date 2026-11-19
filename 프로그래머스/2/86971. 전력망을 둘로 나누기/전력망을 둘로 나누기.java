import java.util.List;
import java.util.ArrayList;

class Solution {
    public int solution(int n, int[][] wires) {
        int diff = Integer.MAX_VALUE;
        int count = 0;
        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0;i<=n;i++){
            graph.add(new ArrayList<>());
        }
        
        for(int [] wire : wires){
            int a = wire[0];
            int b = wire[1];
            
            // 서로 이웃으로 연결
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        for(int [] wire : wires){
            boolean[] visited = new boolean[n+1];
            int a = wire[0];
            int b = wire[1];
            count = dfs(a,graph,visited,a,b);
            int otherCount = n - count;
            int currentDiff = Math.abs(count-otherCount);
            diff = Math.min(diff,currentDiff);
        }
        return diff;
    }
    
    public int dfs(int node, List<List<Integer>> graph, boolean[] visited, int cutA, int cutB){
        visited[node] = true;
        int count = 1;
        
        for(int next: graph.get(node)){
            if((node == cutA && next == cutB) || (node == cutB && next == cutA)){
                continue;
            }
            if(visited[next])
                continue;
            count += dfs(next,graph,visited,cutA,cutB);
        }
        return count;
    }
}
