package UKCC;

import java.util.Scanner;

public class Main {

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int a = sc.nextInt();

            for (int i = 0; i < a; i++) {
                int n = sc.nextInt();
                sc.nextLine();

                String[] s1 = new String[n];
                for (int j = 0; j < n; j++) {
                    s1[j] = sc.nextLine();
                }

                String[] s2 = new String[n];
                for (int j = 0; j < n; j++) {
                    s2[j] = sc.nextLine();
                }

                long max = 0;
                long min = 0;

                for (int j = 0; j < n; j++) {
                    int c1 = 0;
                    for (char ch : s1[j].toCharArray()) {
                        if (ch == '#') c1++;
                    }

                    int c2 = 0;
                    for (char ch : s2[j].toCharArray()) {
                        if (ch == '#') c2++;
                    }

                    max += (long) c1 * c2;
                    min += Math.max(c1, c2);
                }

                System.out.println(max + " " + min);
            }

        }
    }

