package UKCC;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            sc.nextLine();
            char[][] a = new char[n][m];
            for (int i = 0; i < n; i++) {
                String s = sc.nextLine();
                for (int j = 0; j < m; j++) {
                    a[i][j] = s.charAt(j);
                }
            }
            long[][] b = new long[n][m];
            long[][] c = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b[i][j] = 0;
                    c[i][j] = 1;
                }
            }
            b[0][0] = 1;

            long d = 0;
            long e = 1;
            boolean f;
            do {
                f = false;
                long[][] g = new long[n][m];
                long[][] h = new long[n][m];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        g[i][j] = b[i][j];
                        h[i][j] = c[i][j];
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (b[i][j] == 0) {
                            continue;
                        }
                        char ch = a[i][j];
                        if (ch == '.') {
                            continue;
                        }
                        if (ch == 'X') {
                            continue;
                        }

                        long p = b[i][j];
                        long q = c[i][j];

                        g[i][j] = 0;
                        h[i][j] = 1;
                        f = true;

                        if (ch == '<') {
                            int ni = i;
                            int nj = j - 1;
                            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                                long nd = d * q + p * e;
                                long ne = e * q;
                                long x = nd;
                                long y = ne;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                d = nd / x;
                                e = ne / x;
                            } else if (a[ni][nj] == 'X') {
                            } else {
                                long nz = g[ni][nj] * q + p * h[ni][nj];
                                long nm = h[ni][nj] * q;
                                long x = nz;
                                long y = nm;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                g[ni][nj] = nz / x;
                                h[ni][nj] = nm / x;
                            }
                        } else if (ch == '>') {
                            int ni = i;
                            int nj = j + 1;
                            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                                long nd = d * q + p * e;
                                long ne = e * q;
                                long x = nd;
                                long y = ne;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                d = nd / x;
                                e = ne / x;
                            } else if (a[ni][nj] == 'X') {
                            } else {
                                long nz = g[ni][nj] * q + p * h[ni][nj];
                                long nm = h[ni][nj] * q;
                                long x = nz;
                                long y = nm;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                g[ni][nj] = nz / x;
                                h[ni][nj] = nm / x;
                            }
                        } else if (ch == '^') {
                            int ni = i - 1;
                            int nj = j;
                            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                                long nd = d * q + p * e;
                                long ne = e * q;
                                long x = nd;
                                long y = ne;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                d = nd / x;
                                e = ne / x;
                            } else if (a[ni][nj] == 'X') {
                            } else {
                                long nz = g[ni][nj] * q + p * h[ni][nj];
                                long nm = h[ni][nj] * q;
                                long x = nz;
                                long y = nm;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                g[ni][nj] = nz / x;
                                h[ni][nj] = nm / x;
                            }
                        } else if (ch == 'v') {
                            int ni = i + 1;
                            int nj = j;
                            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                                long nd = d * q + p * e;
                                long ne = e * q;
                                long x = nd;
                                long y = ne;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                d = nd / x;
                                e = ne / x;
                            } else if (a[ni][nj] == 'X') {
                            } else {
                                long nz = g[ni][nj] * q + p * h[ni][nj];
                                long nm = h[ni][nj] * q;
                                long x = nz;
                                long y = nm;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                g[ni][nj] = nz / x;
                                h[ni][nj] = nm / x;
                            }
                        } else if (ch == 'S') {
                            int cnt = 0;
                            boolean u = false;
                            boolean dw = false;
                            boolean l = false;
                            boolean r = false;

                            if (i > 0) {
                                char cc = a[i-1][j];
                                if (cc == 'X') {
                                    u = true;
                                    cnt++;
                                } else if (cc != '.') {
                                    if (cc != 'v') {
                                        u = true;
                                        cnt++;
                                    }
                                }
                            }
                            if (i < n-1) {
                                char cc = a[i+1][j];
                                if (cc == 'X') {
                                    dw = true;
                                    cnt++;
                                } else if (cc != '.') {
                                    if (cc != '^') {
                                        dw = true;
                                        cnt++;
                                    }
                                }
                            }
                            if (j > 0) {
                                char cc = a[i][j-1];
                                if (cc == 'X') {
                                    l = true;
                                    cnt++;
                                } else if (cc != '.') {
                                    if (cc != '>') {
                                        l = true;
                                        cnt++;
                                    }
                                }
                            }
                            if (j < m-1) {
                                char cc = a[i][j+1];
                                if (cc == 'X') {
                                    r = true;
                                    cnt++;
                                } else if (cc != '.') {
                                    if (cc != '<') {
                                        r = true;
                                        cnt++;
                                    }
                                }
                            }

                            if (cnt > 0) {
                                long sz = p;
                                long sm = q * cnt;
                                long x = sz;
                                long y = sm;
                                while (y != 0) {
                                    long temp = y;
                                    y = x % y;
                                    x = temp;
                                }
                                sz = sz / x;
                                sm = sm / x;

                                if (u) {
                                    if (a[i-1][j] != 'X') {
                                        long nz = g[i-1][j] * sm + sz * h[i-1][j];
                                        long nm = h[i-1][j] * sm;
                                        x = nz;
                                        y = nm;
                                        while (y != 0) {
                                            long temp = y;
                                            y = x % y;
                                            x = temp;
                                        }
                                        g[i-1][j] = nz / x;
                                        h[i-1][j] = nm / x;
                                    }
                                }
                                if (dw) {
                                    if (a[i+1][j] != 'X') {
                                        long nz = g[i+1][j] * sm + sz * h[i+1][j];
                                        long nm = h[i+1][j] * sm;
                                        x = nz;
                                        y = nm;
                                        while (y != 0) {
                                            long temp = y;
                                            y = x % y;
                                            x = temp;
                                        }
                                        g[i+1][j] = nz / x;
                                        h[i+1][j] = nm / x;
                                    }
                                }
                                if (l) {
                                    if (a[i][j-1] != 'X') {
                                        long nz = g[i][j-1] * sm + sz * h[i][j-1];
                                        long nm = h[i][j-1] * sm;
                                        x = nz;
                                        y = nm;
                                        while (y != 0) {
                                            long temp = y;
                                            y = x % y;
                                            x = temp;
                                        }
                                        g[i][j-1] = nz / x;
                                        h[i][j-1] = nm / x;
                                    }
                                }
                                if (r) {
                                    if (a[i][j+1] != 'X') {
                                        long nz = g[i][j+1] * sm + sz * h[i][j+1];
                                        long nm = h[i][j+1] * sm;
                                        x = nz;
                                        y = nm;
                                        while (y != 0) {
                                            long temp = y;
                                            y = x % y;
                                            x = temp;
                                        }
                                        g[i][j+1] = nz / x;
                                        h[i][j+1] = nm / x;
                                    }
                                }
                            }
                        }
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        b[i][j] = g[i][j];
                        c[i][j] = h[i][j];
                    }
                }

            } while (f);

            long x = d;
            long y = e;
            while (y != 0) {
                long temp = y;
                y = x % y;
                x = temp;
            }
            if (d == 0) {
                System.out.println("0 1");
            } else {
                System.out.println((d / x) + " " + (e / x));
            }
        }
    }
}