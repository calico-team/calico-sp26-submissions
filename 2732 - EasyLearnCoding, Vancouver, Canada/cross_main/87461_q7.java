import java.io.*;
import java.util.*;


public class q7 {


    static class LayoutConfig {
        final int modBase = 5;
        final int rowFactor = 1;
        final int colFactor = 2;

        public int calculateCell(int r, int c) {
            return (r * rowFactor + c * colFactor) % modBase;
        }
    }

    private static final LayoutConfig currentConfig = new LayoutConfig();

    public static void main(String[] args) throws Exception {
        SimpleByteReader inputSource = new SimpleByteReader(System.in);
        StringBuilder outputBuffer = new StringBuilder();

        int remainingTasks = inputSource.readInt();
        while (remainingTasks-- > 0) {
            executeMatrixGeneration(inputSource, outputBuffer);
        }

        System.out.print(outputBuffer);
    }

    private static void executeMatrixGeneration(SimpleByteReader reader, StringBuilder sb) throws IOException {
        int height = reader.readInt();
        int width = reader.readInt();

        int[][] patternData = assemblePattern(height, width);
        formatOutput(patternData, sb);
    }


    private static int[][] assemblePattern(int h, int w) {
        int[][] matrix = new int[h][w];
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                matrix[y][x] = currentConfig.calculateCell(y, x);
            }
        }
        return matrix;
    }

    private static void formatOutput(int[][] data, StringBuilder sb) {
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                sb.append(data[i][j]);
                if (j < data[i].length - 1) {
                    sb.append(' ');
                }
            }
            sb.append('\n');
        }
    }

//fix the code here
    // edit: done
    static class SimpleByteReader {
        private final InputStream input;
        private final byte[] dataBuffer = new byte[65536];
        private int bufferPointer = 0, bytesInPool = 0;

        public SimpleByteReader(InputStream is) {
            this.input = is;
        }

        private int getNextByte() throws IOException {
            if (bufferPointer >= bytesInPool) {
                bytesInPool = input.read(dataBuffer);
                bufferPointer = 0;
                if (bytesInPool <= 0) return -1;
            }
            return dataBuffer[bufferPointer++];
        }

        public int readInt() throws IOException {
            int code = getNextByte();
            while (code != -1 && code <= 32) {
                code = getNextByte();
            }

            int direction = 1;
            if (code == '-') {
                direction = -1;
                code = getNextByte();
            }

            int value = 0;
            while (code > 32) {
                value = value * 10 + (code - '0');
                code = getNextByte();
            }
            return value * direction;
        }
    }
}