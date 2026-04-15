import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class q5 {

    public static void main(String[] args) throws IOException {
        CoreInput sc = new CoreInput();
        StringBuilder res = new StringBuilder();

        String firstLine = sc.next();
        if (firstLine == null) return;

        int totalTestCases = Integer.parseInt(firstLine);

        while (totalTestCases-- > 0) {
            int n = sc.nextInt();
            long[] initialHeights = new long[n];
            for (int i = 0; i < n; i++) {
                initialHeights[i] = sc.nextLong();
            }

            long[] lowerBound = new long[n];
            long[] upperBound = new long[n];


            lowerBound[0] = upperBound[0] = initialHeights[0];


            for (int i = 1; i < n; i++) {
                long h = initialHeights[i];
                long prevMin = lowerBound[i - 1];
                long prevMax = upperBound[i - 1];

                if (h < prevMin) {
                    lowerBound[i] = h;
                    upperBound[i] = prevMin;
                } else if (h > prevMax) {
                    lowerBound[i] = prevMax;
                    upperBound[i] = h;
                } else {
                    lowerBound[i] = h;
                    upperBound[i] = h;
                }
            }

            long[] finalSequence = new long[n];
            finalSequence[n - 1] = lowerBound[n - 1];


            int currentIndex = n - 2;
            while (currentIndex >= 0) {
                long target = finalSequence[currentIndex + 1];
                finalSequence[currentIndex] = clampValue(target, lowerBound[currentIndex], upperBound[currentIndex]);
                currentIndex--;
            }


            for (int i = 0; i < n; i++) {
                res.append(finalSequence[i]);
                if (i != n - 1) {
                    res.append(' ');
                }
            }
            res.append("\n");
        }
        System.out.print(res.toString());
    }


    private static long clampValue(long val, long min, long max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }


    static class CoreInput {
        private final BufferedReader br;
        private StringTokenizer st;

        public CoreInput() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String s = br.readLine();
                    if (s == null) return null;
                    st = new StringTokenizer(s);
                } catch (IOException e) {
                    return null;
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}