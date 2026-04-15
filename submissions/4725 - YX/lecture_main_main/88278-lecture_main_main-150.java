package UKCC;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();
            while (T-- > 0) {
                int N = sc.nextInt();
                int M = sc.nextInt();
                int K = sc.nextInt();
                sc.nextLine();

                List<int[]> seats = new ArrayList<>();
                for (int i = 0; i < N; i++) {
                    String line = sc.nextLine();
                    for (int j = 0; j < M; j++) {
                        if (line.charAt(j) == '-') {
                            seats.add(new int[]{i, j});
                        }
                    }
                }


                int low = 0, high = N + M;
                int bestD = N + M;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    boolean ok = false;
                    for (int i = 0; i < seats.size(); i++) {
                        List<int[]> chosen = new ArrayList<>();
                        chosen.add(seats.get(i));
                        for (int j = i + 1; j < seats.size(); j++) {
                            int[] p = seats.get(j);
                            boolean add = true;
                            for (int[] c : chosen) {
                                int dist = Math.abs(p[0] - c[0]) + Math.abs(p[1] - c[1]);
                                if (dist > mid) {
                                    add = false;
                                    break;
                                }
                            }
                            if (add) {
                                chosen.add(p);
                                if (chosen.size() == K) {
                                    ok = true;
                                    break;
                                }
                            }
                        }
                        if (ok) break;
                    }
                    if (ok) {
                        bestD = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }

                List<int[]> ans = new ArrayList<>();
                for (int i = 0; i < seats.size(); i++) {
                    if (ans.size() == K) break;
                    int[] p = seats.get(i);
                    boolean ok = true;
                    for (int[] c : ans) {
                        int dist = Math.abs(p[0] - c[0]) + Math.abs(p[1] - c[1]);
                        if (dist > bestD) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ans.add(p);
                    }
                }

                for (int[] seat : ans) {
                    System.out.println(seat[0] + " " + seat[1]);
                }
            }

        }
    }

