import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class lecture_template {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);
        in.resetSyntax();
        in.wordChars('!', '~');
        in.whitespaceChars(0, ' ');

        in.nextToken();
        int T = Integer.parseInt(in.sval);
        for (int t = 0; t < T; t++) {
            in.nextToken();
            int M = Integer.parseInt(in.sval);
            in.nextToken();
            int N = Integer.parseInt(in.sval);
            in.nextToken();
            int K = Integer.parseInt(in.sval);
            String[] GRID = new String[M];
            for (int i = 0; i < M; i++) {
                in.nextToken();
                GRID[i] = in.sval;
            }
            List<int[]> result = solve(M, N, K, GRID);
            for (int[] p : result) {
                pw.println(p[0] + " " + p[1]);
            }
        }
        pw.flush();
    }

    /**
     * M: number of rows in the lecture hall N: number of columns in the lecture hall K: number of friends who need
     * seats GRID: array of M strings of length N; '#' is a blocked seat, '-' is an empty seat
     * <p>
     * Return a list of K int[2] {row, col} for the chosen seats.
     */
    static List<int[]> solve(int M, int N, int K, String[] GRID) {
        List<Seat> seats = new ArrayList<>();
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (GRID[r].charAt(c) == '-') {
                    seats.add(new Seat(r, c));
                }
            }
        }

        seats.sort(Comparator.comparingInt(a -> a.u));

        int lo = 0, hi = M + N;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (can(seats, K, mid)) hi = mid;
            else lo = mid + 1;
        }

        return build(seats, K, lo);
    }

    static boolean can(List<Seat> seats, int K, int d) {
        int n = seats.size();
        int right = 0;

        for (int left = 0; left < n; left++) {
            while (right < n && seats.get(right).u - seats.get(left).u <= d) {
                right++;
            }

            int len = right - left;
            if (len < K) continue;

            ArrayList<Seat> cand = new ArrayList<>(len);
            for (int i = left; i < right; i++) cand.add(seats.get(i));
            cand.sort(Comparator.comparingInt(a -> a.v));

            for (int i = 0; i + K - 1 < cand.size(); i++) {
                if (cand.get(i + K - 1).v - cand.get(i).v <= d) {
                    return true;
                }
            }
        }
        return false;
    }

    static List<int[]> build(List<Seat> seats, int K, int d) {
        int n = seats.size();
        int right = 0;

        for (int left = 0; left < n; left++) {
            while (right < n && seats.get(right).u - seats.get(left).u <= d) {
                right++;
            }

            int len = right - left;
            if (len < K) continue;

            ArrayList<Seat> cand = new ArrayList<>(len);
            for (int i = left; i < right; i++) cand.add(seats.get(i));
            cand.sort(Comparator.comparingInt(a -> a.v));

            for (int i = 0; i + K - 1 < cand.size(); i++) {
                if (cand.get(i + K - 1).v - cand.get(i).v <= d) {
                    List<int[]> ans = new ArrayList<>();
                    for (int j = i; j < i + K; j++) {
                        Seat s = cand.get(j);
                        ans.add(new int[]{s.r, s.c});
                    }
                    return ans;
                }
            }
        }

        return new ArrayList<>();
    }

    static class Seat {

        int r, c, u, v;

        Seat(int r, int c) {
            this.r = r;
            this.c = c;
            this.u = r + c;
            this.v = r - c;
        }

    }

}
