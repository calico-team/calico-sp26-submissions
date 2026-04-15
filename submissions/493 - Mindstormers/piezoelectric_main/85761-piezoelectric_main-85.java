import java.util.*;

class prob1 {

    public static int electric_amount(int length, int width, int e_amount, int e_genrated) {

        int perameter = 2 * (length + width);
        int total_required_e = perameter * e_genrated;
        int laps = e_amount / total_required_e;
        return laps;

    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            for (int i = 0; i < t; i++) {

                int length = sc.nextInt();

                int width = sc.nextInt();
                int e_amount = sc.nextInt();
                int e_genrated = sc.nextInt();

                System.out.println(electric_amount(length, width, e_amount, e_genrated));

            }
        }
    }
}