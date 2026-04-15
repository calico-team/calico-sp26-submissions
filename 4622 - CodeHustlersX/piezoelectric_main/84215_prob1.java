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
        System.out.println("please enter length");
        int length = sc.nextInt();
        System.out.println("please enter width");
        int width = sc.nextInt();
        System.out.println("please enter electricity amount required  by one lap");
        int e_amount = sc.nextInt();
        System.out.println("please enter electricity amount genrated by one lap");
        int e_genrated = sc.nextInt();

        System.out.println(electric_amount(length, width, e_amount, e_genrated));

    }
}