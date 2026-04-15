import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();

        for (int i = 0; i < a; i++) {
            int b = sc.nextInt();
            int c = sc.nextInt();
            int d = sc.nextInt();
            int e = sc.nextInt();


            int[] f = new int[1000];
            int len = 0;
            while (sc.hasNextInt()) {
                f[len++] = sc.nextInt();
                if (sc.hasNextLine() && sc.nextLine().isEmpty()) break;
                if (!sc.hasNextInt()) break;
            }

            int count = 0;
            boolean win = true;

            for (int j = 0; j < len; j++) {
                int dam = f[j];
                c = c - dam;

                if (c >= 0) {
                    count++;
                } else {
                    System.out.println("nah i'd lose");
                    win = false;
                    break;
                }

                if (count == e) {
                    c += d;
                    count = 0;
                }
            }

            if (win && c >= 0) {
                System.out.println("nah i'd win");
            }
        }
    }
}