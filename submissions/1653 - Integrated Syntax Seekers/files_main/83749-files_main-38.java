import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
       
        
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            String A = scanner.next();
            String B = scanner.next();
            
            StringBuilder result = new StringBuilder();
            int Index = 0;
            
            for (int j = 0; j < A.length(); j++) {
                char aVal = A.charAt(j);

                if (Index < B.length() && aVal == B.charAt(Index)) {
                    result.append(aVal);
                    Index++;
                } else { 
                    result.append('#');
                }
            }
            
            System.out.println(result.toString());
        }
        scanner.close();
    }
}
