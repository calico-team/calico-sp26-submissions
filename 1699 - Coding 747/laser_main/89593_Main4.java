import java.util.*;
import java.io.*;

public class Main4 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        StringTokenizer st;

        String line = reader.readLine();
        if (line == null) return;
        
        int scenarioCount = Integer.parseInt(line.trim());

        while (scenarioCount-- > 0) {
            st = new StringTokenizer(reader.readLine());
            int pointCount = Integer.parseInt(st.nextToken());
            long width = Long.parseLong(st.nextToken());
            long height = Long.parseLong(st.nextToken());
            long stepX = Long.parseLong(st.nextToken());
            long stepY = Long.parseLong(st.nextToken());

            long[] coordX = new long[pointCount];
            long[] coordY = new long[pointCount];

            for (int i = 0; i < pointCount; i++) {
                st = new StringTokenizer(reader.readLine());
                coordX[i] = Long.parseLong(st.nextToken());
                coordY[i] = Long.parseLong(st.nextToken());
            }

            long basePointX = coordX[0];
            long basePointY = coordY[0];
            long fastestTime = -1;
            int optimalIndex = -1;

            for (int i = 0; i < pointCount; i++) {
                long offsetX = (coordX[i] - basePointX + width) % width;
                long offsetY = (coordY[i] - basePointY + height) % height;

                long[] solX = solveLinearCongruence(stepY, width, offsetX);
                if (solX == null) continue;

                long[] solY = solveLinearCongruence(stepX, height, offsetY);
                if (solY == null) continue;

                long timeResult = mergeCongruences(solX[0], solX[1], solY[0], solY[1]);

                if (timeResult != -1) {
                    if (fastestTime == -1 || timeResult < fastestTime) {
                        fastestTime = timeResult;
                        optimalIndex = i;
                    }
                }
            }
            writer.println(optimalIndex);
        }
        writer.flush();
        writer.close();
    }

    private static long[] extendedGcd(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] result = extendedGcd(b, a % b);
        long gcd = result[0];
        long x = result[2];
        long y = result[1] - (a / b) * result[2];
        return new long[]{gcd, x, y};
    }

    private static long[] solveLinearCongruence(long a, long m, long b) {
        long[] egcd = extendedGcd(a, m);
        long gcd = egcd[0];
        long invX = egcd[1];

        if (b % gcd != 0) return null;

        long modBase = m / gcd;
        long rem = ((b / gcd) * (invX % modBase + modBase)) % modBase;
        return new long[]{rem, modBase};
    }

    private static long mergeCongruences(long r1, long m1, long r2, long m2) {
        long delta = r2 - r1;
        long[] egcd = extendedGcd(m1, m2);
        long gcd = egcd[0];
        long invM1 = egcd[1];

        if (delta % gcd != 0) return -1;

        long modLCM = m2 / gcd;
        long multiplier = ((delta / gcd) % modLCM * (invM1 % modLCM) + modLCM) % modLCM;
        
        long result = r1 + multiplier * m1;
        long totalPeriod = m1 * modLCM;
        
        return (result == 0) ? totalPeriod : result;
    }
}