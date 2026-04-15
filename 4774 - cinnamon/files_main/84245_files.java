import java.util.*;
import java.io.*;

public class files {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        input.nextLine();
        while (t > 0) {
            char[] a = input.nextLine().toCharArray();
            char[] b = input.nextLine().toCharArray();
            int count = 0;
            for (int i = 0; i < a.length; i++) {
                if (a[i] == b[count]) {
                    count++;
                    if (count == b.length) {
                        count--;
                        b[count] = '0';
                    }
                } else {
                    a[i] = '#';
                }
            }
            System.out.println(a);
            t--;
        }
    }
}