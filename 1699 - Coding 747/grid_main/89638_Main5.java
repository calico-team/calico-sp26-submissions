import java.io.*;
import java.util.*;

public class Main5 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String firstLine = reader.readLine();
        if (firstLine == null) return;
        
        int testCases = Integer.parseInt(firstLine.trim());

        while (testCases-- > 0) {
            int elementCount = Integer.parseInt(reader.readLine());
            int[] rawData = new int[elementCount];
            
            StringTokenizer st = new StringTokenizer(reader.readLine());
            for (int i = 0; i < elementCount; i++) {
                rawData[i] = Integer.parseInt(st.nextToken());
            }

            long[][] constraintBounds = new long[elementCount][2];
            constraintBounds[0][0] = rawData[0];
            constraintBounds[0][1] = rawData[0];

            for (int i = 1; i < elementCount; i++) {
                long lowerLimit = constraintBounds[i - 1][0];
                long upperLimit = constraintBounds[i - 1][1];
                int currentVal = rawData[i];

                if (currentVal < lowerLimit) {
                    constraintBounds[i][0] = currentVal;
                    constraintBounds[i][1] = lowerLimit;
                } else if (currentVal > upperLimit) {
                    constraintBounds[i][0] = upperLimit;
                    constraintBounds[i][1] = currentVal;
                } else {
                    constraintBounds[i][0] = currentVal;
                    constraintBounds[i][1] = currentVal;
                }
            }

            long[] optimizedSequence = new long[elementCount];
            optimizedSequence[elementCount - 1] = constraintBounds[elementCount - 1][0];

            for (int i = elementCount - 2; i >= 0; i--) {
                long minBound = constraintBounds[i][0];
                long maxBound = constraintBounds[i][1];
                long nextDecidedVal = optimizedSequence[i + 1];

                if (nextDecidedVal < minBound) {
                    optimizedSequence[i] = minBound;
                } else if (nextDecidedVal > maxBound) {
                    optimizedSequence[i] = maxBound;
                } else {
                    optimizedSequence[i] = nextDecidedVal;
                }
            }

            StringBuilder resultBuffer = new StringBuilder();
            for (int i = 0; i < elementCount; i++) {
                resultBuffer.append(optimizedSequence[i]);
                if (i < elementCount - 1) resultBuffer.append(" ");
            }
            writer.write(resultBuffer.toString());
            writer.newLine();
        }
        writer.flush();
    }
}