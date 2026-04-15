import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Using BufferedReader for fast I/O required for N = 10^5
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null || line.isEmpty()) return;

        int T = Integer.parseInt(line.trim());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            // Read N (number of floors) [cite: 210]
            String nLine = br.readLine();
            if (nLine == null || nLine.isEmpty()) break;
            int N = Integer.parseInt(nLine.trim());

            // Read the entire top row A [cite: 211]
            String rowA = br.readLine();
            if (rowA == null) break;

            // The optimal strategy is setting the bottom row 'b' equal to 'A'.
            // This results in a vertical difference of 0.
            // We can directly append the input string to our output buffer.
            sb.append(rowA).append('\n');

            // Periodically flush the StringBuilder to manage memory with large outputs
            if (sb.length() > 1000000) {
                System.out.print(sb);
                sb.setLength(0);
            }
        }
        // Final output flush
        System.out.print(sb);
    }
}