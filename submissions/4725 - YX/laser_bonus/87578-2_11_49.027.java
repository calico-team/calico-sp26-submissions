package UKCC;

import java.util.Scanner;

public class Main {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            int T = sc.nextInt();
            while (T > 0) {
                T--;

                int K = sc.nextInt();
                int N = sc.nextInt();
                int M = sc.nextInt();
                int P = sc.nextInt();
                int Q = sc.nextInt();

                int[] X = new int[K];
                int[] Y = new int[K];
                for (int i = 0; i < K; i++) {
                    X[i] = sc.nextInt();
                    Y[i] = sc.nextInt();
                }

                long minT = Long.MAX_VALUE;
                int ans = 0;
                long x0 = X[0];
                long y0 = Y[0];

                for (int i = 0; i < K; i++) {
                    long dx = (X[i] - x0) % N;
                    long dy = (Y[i] - y0) % M;
                    if (dx < 0) dx += N;
                    if (dy < 0) dy += M;


                    long tx = -1;
                    long step = Q;
                    long mod = N;
                    long target = dx;
                    target = (target % mod + mod) % mod;

                    long a = step, b = mod, c = target;
                    long g = a, tmpB = b;
                    while (tmpB != 0) {
                        long tmp = tmpB;
                        tmpB = g % tmpB;
                        g = tmp;
                    }

                    if (c % g == 0) {
                        long a1 = a / g;
                        long b1 = b / g;
                        long c1 = c / g;

                        long lastX = 1, lastY = 0;
                        long currX = 0, currY = 1;
                        long aa = a1, bb = b1;
                        while (bb != 0) {
                            long qVal = aa / bb;
                            long temp = aa;
                            aa = bb;
                            bb = temp % bb;

                            long t = currX;
                            currX = lastX - qVal * currX;
                            lastX = t;

                            t = currY;
                            currY = lastY - qVal * currY;
                            lastY = t;
                        }
                        long inv = (lastX % b1 + b1) % b1;
                        tx = (c1 * inv) % b1;
                    }
                    if (tx == -1) continue;


                    long ty = -1;
                    step = P;
                    mod = M;
                    target = dy;
                    target = (target % mod + mod) % mod;

                    a = step;
                    b = mod;
                    c = target;
                    g = a;
                    tmpB = b;
                    while (tmpB != 0) {
                        long tmp = tmpB;
                        tmpB = g % tmpB;
                        g = tmp;
                    }

                    if (c % g == 0) {
                        long a1 = a / g;
                        long b1 = b / g;
                        long c1 = c / g;

                        long lastX = 1, lastY = 0;
                        long currX = 0, currY = 1;
                        long aa = a1, bb = b1;
                        while (bb != 0) {
                            long qVal = aa / bb;
                            long temp = aa;
                            aa = bb;
                            bb = temp % bb;

                            long t = currX;
                            currX = lastX - qVal * currX;
                            lastX = t;

                            t = currY;
                            currY = lastY - qVal * currY;
                            lastY = t;
                        }
                        long inv = (lastX % b1 + b1) % b1;
                        ty = (c1 * inv) % b1;
                    }
                    if (ty == -1) continue;


                    a = Q;
                    b = N;
                    g = a;
                    tmpB = b;
                    while (tmpB != 0) {
                        long tmp = tmpB;
                        tmpB = g % tmpB;
                        g = tmp;
                    }
                    long periodX = N / g;


                    a = P;
                    b = M;
                    g = a;
                    tmpB = b;
                    while (tmpB != 0) {
                        long tmp = tmpB;
                        tmpB = g % tmpB;
                        g = tmp;
                    }
                    long periodY = M / g;


                    long a1 = tx, m1 = periodX;
                    long a2 = ty, m2 = periodY;
                    long ttt = -1;

                    a = m1;
                    b = m2;
                    g = a;
                    tmpB = b;
                    while (tmpB != 0) {
                        long tmp = tmpB;
                        tmpB = g % tmpB;
                        g = tmp;
                    }

                    long diff = a2 - a1;
                    if (diff % g == 0) {
                        long lcm = m1 / g * m2;
                        long m1g = m1 / g;
                        long m2g = m2 / g;
                        diff /= g;

                        long lastX = 1, lastY = 0;
                        long currX = 0, currY = 1;
                        long aa = m1g, bb = m2g;
                        while (bb != 0) {
                            long qVal = aa / bb;
                            long temp = aa;
                            aa = bb;
                            bb = temp % bb;

                            long t = currX;
                            currX = lastX - qVal * currX;
                            lastX = t;

                            t = currY;
                            currY = lastY - qVal * currY;
                            lastY = t;
                        }
                        long inv = (lastX % m2g + m2g) % m2g;
                        long k = (diff * inv) % m2g;
                        if (k < 0) k += m2g;

                        ttt = a1 + k * m1;
                        ttt = (ttt % lcm + lcm) % lcm;
                    }

                    if (ttt == -1) continue;
                    if (ttt == 0) ttt = periodX / g * periodY;

                    if (ttt > 0 && ttt < minT) {
                        minT = ttt;
                        ans = i;
                    }
                }

                System.out.println(ans);
            }

        }
    }

