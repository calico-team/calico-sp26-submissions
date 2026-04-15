import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class JoshContext041212 {
    static Fraction[][] memo;
    static String[] grid;
    static int N, M;

    static class Fraction {
        BigInteger p, q;

        Fraction(BigInteger p, BigInteger q) {
            BigInteger gcd = p.gcd(q);
            this.p = p.divide(gcd);
            this.q = q.divide(gcd);

            if (this.q.compareTo(BigInteger.ZERO) < 0) {
                this.p = this.p.negate();
                this.q = this.q.negate();
            }
        }

        Fraction add(Fraction o) {
            BigInteger num = p.multiply(o.q).add(o.p.multiply(q));
            BigInteger den = q.multiply(o.q);
            return new Fraction(num, den);
        }

        Fraction multiply(Fraction o) {
            return new Fraction(p.multiply(o.p), q.multiply(o.q));
        }
    }

    static boolean isConveyor(char c) {
        return c == 'v' || c == '^' || c == '<' || c == '>';
    }

    static Fraction dfs(int r, int c) {
        if (r < 0 || r >= N || c < 0 || c >= M) {
            return new Fraction(BigInteger.ONE, BigInteger.ONE);
        }

        if (memo[r][c] != null) {
            return memo[r][c];
        }

        char ch = grid[r].charAt(c);
        Fraction res = new Fraction(BigInteger.ZERO, BigInteger.ONE);

        if (ch == 'x' || ch == 'X') {
            res = new Fraction(BigInteger.ZERO, BigInteger.ONE);
        } else if (ch == 'v') {
            res = dfs(r + 1, c);
        } else if (ch == '^') {
            res = dfs(r - 1, c);
        } else if (ch == '<') {
            res = dfs(r, c - 1);
        } else if (ch == '>') {
            res = dfs(r, c + 1);
        } else if (ch == 'S') {
            Fraction sum = new Fraction(BigInteger.ZERO, BigInteger.ONE);
            int validCount = 0;

            if (r - 1 >= 0) {
                char nCh = grid[r - 1].charAt(c);
                if (nCh == 'x' || nCh == 'X' || (isConveyor(nCh) && nCh != 'v')) {
                    sum = sum.add(dfs(r - 1, c));
                    validCount++;
                }
            }
            if (r + 1 < N) {
                char nCh = grid[r + 1].charAt(c);
                if (nCh == 'x' || nCh == 'X' || (isConveyor(nCh) && nCh != '^')) {
                    sum = sum.add(dfs(r + 1, c));
                    validCount++;
                }
            }
            if (c - 1 >= 0) {
                char nCh = grid[r].charAt(c - 1);
                if (nCh == 'x' || nCh == 'X' || (isConveyor(nCh) && nCh != '>')) {
                    sum = sum.add(dfs(r, c - 1));
                    validCount++;
                }
            }
            if (c + 1 < M) {
                char nCh = grid[r].charAt(c + 1);
                if (nCh == 'x' || nCh == 'X' || (isConveyor(nCh) && nCh != '<')) {
                    sum = sum.add(dfs(r, c + 1));
                    validCount++;
                }
            }

            Fraction multiplier = new Fraction(BigInteger.ONE, BigInteger.valueOf(validCount));
            res = sum.multiply(multiplier);
        }

        memo[r][c] = res;
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;

        int T = Integer.parseInt(line.trim());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            grid = new String[N];
            for (int i = 0; i < N; i++) {
                grid[i] = br.readLine();
            }

            memo = new Fraction[N][M];
            Fraction ans = dfs(0, 0);
            System.out.println(ans.p + " " + ans.q);
        }
    }
}