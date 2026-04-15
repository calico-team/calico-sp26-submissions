import java.util.Scanner;
public class problem3{
	public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        input.nextLine();
        for (int t = 0; t < T; t++) {
            String A = input.nextLine();
            String B = input.nextLine();
            System.out.println(replace(A, B));
        }
        input.close();
    }

    private static String replace(String A, String B) {
        int i = 0, j = 0;
        StringBuilder result = new StringBuilder();
        while (i < A.length()) {
            if (j < B.length() && A.charAt(i) == B.charAt(j)) {
                result.append(A.charAt(i));
                j++;
            } else {
                result.append('#');
            }
            i++;
        }
        return result.toString();
    }
}