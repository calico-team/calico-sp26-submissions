import java.io.*;
import java.util.*;

class Solution {
    /**
     * Find an array B of N integers representing the filled-in second row,
     * chosen to minimize the sum of absolute differences of adjacent
     * numbers on the grid.
     * 
     * N: the number of columns in the 2 x N grid
     * A: array of N integers giving the first row of the grid
     */
    static int[] solve(int N, int[] A) {
        class Block {
            PriorityQueue<Long> left = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Long> right = new PriorityQueue<>();

            void add(long x) {
                if (left.isEmpty() || x <= left.peek()) {
                    left.add(x);
                } else {
                    right.add(x);
                }
                balance();
            }

            void balance() {
                if (left.size() > right.size() + 1) {
                    right.add(left.poll());
                } else if (right.size() > left.size()) {
                    left.add(right.poll());
                }
            }

            long median() {
                return left.peek();
            }

            void merge(Block other) {
                for (long x : other.left) add(x);
                for (long x : other.right) add(x);
            }

            int size() {
                return left.size() + right.size();
            }
        }

        Stack<Block> stack = new Stack<>();

        for (int i = 0; i < N; i++) {
            long val = (long) A[i] - i;

            Block curr = new Block();
            curr.add(val);
            stack.push(curr);

            while (stack.size() >= 2) {
                Block b2 = stack.pop();
                Block b1 = stack.pop();

                if (b1.median() > b2.median()) {
                    b1.merge(b2);
                    stack.push(b1);
                } else {
                    stack.push(b1);
                    stack.push(b2);
                    break;
                }
            }
        }

        long[] y = new long[N];
        int idx = N - 1;

        while (!stack.isEmpty()) {
            Block b = stack.pop();
            long m = b.median();
            int sz = b.size();

            for (int i = 0; i < sz; i++) {
                y[idx--] = m;
            }
        }

        int[] B = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = (int)(y[i] + i);
        }

        return B;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);

        in.nextToken(); int T = (int) in.nval;
        for (int t = 0; t < T; t++) {
            in.nextToken(); int N = (int) in.nval;
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                in.nextToken();
                A[i] = (int) in.nval;
            }
            int[] result = solve(N, A);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                if (i > 0) sb.append(' ');
                sb.append(result[i]);
            }
            pw.println(sb);
        }
        pw.flush();
    }
}
