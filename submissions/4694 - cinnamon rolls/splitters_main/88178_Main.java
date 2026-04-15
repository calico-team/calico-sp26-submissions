import java.util.*;
import java.math.BigInteger;

public class Main {
    static int N, M;
    static char[][] grid;
    static Fraction[][] memo;

    static class Fraction {
        BigInteger p, q;
        Fraction(BigInteger p, BigInteger q) {
            BigInteger gcd = p.gcd(q);
            this.p = p.divide(gcd);
            this.q = q.divide(gcd);
        }
        static Fraction ZERO = new Fraction(BigInteger.ZERO, BigInteger.ONE);
        static Fraction ONE = new Fraction(BigInteger.ONE, BigInteger.ONE);

        Fraction add(Fraction other) {
            BigInteger newP = this.p.multiply(other.q).add(other.p.multiply(this.q));
            BigInteger newQ = this.q.multiply(other.q);
            return new Fraction(newP, newQ);
        }

        Fraction divide(int n) {
            return new Fraction(this.p, this.q.multiply(BigInteger.valueOf(n)));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int T = sc.nextInt();
        while (T-- > 0) {
            N = sc.nextInt();
            M = sc.nextInt();
            grid = new char[N][M];
            memo = new Fraction[N][M];
            for (int i = 0; i < N; i++) {
                grid[i] = sc.next().toLowerCase().toCharArray();
            }

            Fraction result = solve(0, 0);
            System.out.println(result.p + " " + result.q);
        }
    }

    static Fraction solve(int r, int c) {
        if (r < 0 || r >= N || c < 0 || c >= M) return Fraction.ONE;
        if (grid[r][c] == 'x') return Fraction.ZERO;
        if (memo[r][c] != null) return memo[r][c];

        Fraction res = Fraction.ZERO;
        char tile = grid[r][c];

        if (tile == 's') {
            List<Fraction> validNeighbors = new ArrayList<>();
            int[] dr = {-1, 1, 0, 0};
            int[] dc = {0, 0, -1, 1};
            char[] backChars = {'v', '^', '>', '<'};

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                char nextTile = grid[nr][nc];

                if (nextTile == 'x' || (nextTile != '.' && nextTile != 's' && nextTile != backChars[i])) {
                    validNeighbors.add(solve(nr, nc));
                }
            }

            Fraction sum = Fraction.ZERO;
            for (Fraction f : validNeighbors) sum = sum.add(f);
            res = sum.divide(validNeighbors.size());
        } else if (tile == '>') {
            res = solve(r, c + 1);
        } else if (tile == '<') {
            res = solve(r, c - 1);
        } else if (tile == 'v') {
            res = solve(r + 1, c);
        } else if (tile == '^') {
            res = solve(r - 1, c);
        } else {
            res = Fraction.ZERO;
        }

        return memo[r][c] = res;
    }
}