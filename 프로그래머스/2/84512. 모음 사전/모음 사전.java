class Solution {
    private String target;
    private int count = 0;
    private int answer = 0;
    char[] list = {'A','E','I','O','U'};
    
        public int solution(String word){
        target = word;    
        count = 0; 
        answer = 0;
        dfs("");
        return answer;
    }
    public void dfs(String prefix){
        // 정답을 찾은 경우
        if(prefix.equals(target))
            answer = count;
        // 5글자가 안되는 경우
        if(prefix.length() < 5){
            for(int i = 0 ; i< list.length ; i++){
                count++;
                dfs(prefix+list[i]);
            }
        }
         // 5글자인 경우
        return;
    }
}