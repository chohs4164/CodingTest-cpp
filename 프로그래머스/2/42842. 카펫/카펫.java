class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        // 노란색 격자의 가로 수
        int i = 0;
        
        // 노란색 격자의 세로 수
        int j = 0;
        
        for(i=1;i*i<=yellow;i++){
            if(yellow % i==0){
                j = yellow / i;
            // 약수 짝 구함!
            
            if((i+j) * 2 + 4 == brown){
                if(i>j) {
                    answer[0] = i+2;
                    answer[1] = j+2;
                    }
                else {
                    answer[0] = j+2;
                    answer[1] = i+2;
                    }
                }
            }
        }
        return answer;
    }
}