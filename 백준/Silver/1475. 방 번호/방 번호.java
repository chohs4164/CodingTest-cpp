import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] counts = new int[9];
        int answer = 0;
        String stringInput = br.readLine();
        int intInput = Integer.parseInt(stringInput);
        int number = 0;
        for (int i = 0; i < stringInput.length(); i++) {
            number = intInput % 10;
            if(number == 9)
                counts[6]++;
            else
                counts[number]++;
            intInput /= 10;
        }
        counts[6] = (counts[6] + 1) / 2;
        for (int i = 0; i < 9; i++) {
            answer = Math.max(answer, counts[i]);
        }
        System.out.println(answer);
    }
}