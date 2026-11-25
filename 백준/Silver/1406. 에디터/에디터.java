import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        Stack<Character> stack1 = new Stack<>();
        Stack<Character> stack2 = new Stack<>();

        String firstInput = br.readLine();
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < firstInput.length(); i++) {
            stack1.push(firstInput.charAt(i));
        }
        for (int i = 0; i < M; i++) {
            String line = br.readLine();
            char command = line.charAt(0);
            switch (command) {
                case 'L':
                    if(!stack1.isEmpty())
                        stack2.push(stack1.pop());
                    break;
                case 'D':
                    if(!stack2.isEmpty())
                        stack1.push(stack2.pop());
                    break;
                case 'B':
                    if (!stack1.isEmpty())
                        stack1.pop();
                    break;
                case 'P':
                    char ch = line.charAt(2);
                    stack1.push(ch);
                    break;
            }
        }
        while(!stack1.empty())
            sb.append(stack1.pop());
        sb.reverse();
        while(!stack2.empty())
            sb.append(stack2.pop());
        sb.reverse();
        System.out.println(sb.reverse());
    }
}