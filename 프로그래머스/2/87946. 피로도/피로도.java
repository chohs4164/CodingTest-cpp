class Solution {
    private int answer = 0;
    public int solution(int k, int[][] dungeons) {
        boolean[] used = new boolean[dungeons.length];
        search(k,dungeons,used,0);
        return answer;
    }
    private void search(int k, int[][] dungeons, boolean[] used, int count){
        for(int i=0;i<dungeons.length;i++){
            if(used[i])
                continue;
            if(k>=dungeons[i][0]){
                used[i] = true;
                search(k-dungeons[i][1],dungeons,used,count+1);
                used[i] = false;
            }
        }
        if(answer<count)
            answer=count;
    }
} 