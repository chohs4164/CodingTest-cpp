import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

class Solution {
    // 1. 가능한 숫자 조합을 저장할 Set (멤버 변수로 선언)
    Set<Integer> numberSet = new HashSet<>();

    public int solution(String numbers) {
        // 만든 조합인지 아닌지 판단용
        boolean[] visited = new boolean[numbers.length()];

        // 3. 가능한 조합 생성
        generateCombinations(numbers, "", visited);

        // 4. 소수 개수 세기
        int count = 0;
        for (int num : numberSet) {
            if (isPrime(num)) {
                count++;
            }
        }
        return count;
    }

    // 메서드들을 main이나 다른 메서드 내부가 아닌 클래스 바깥 레벨로 이동
    private void generateCombinations(String numbers, String current, boolean[] visited) {
        if (!current.isEmpty()) {
            numberSet.add(Integer.parseInt(current));
        }

        for (int i = 0; i < numbers.length(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                generateCombinations(numbers, current + numbers.charAt(i), visited);
                visited[i] = false;
            }
        }
    }

    private boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}