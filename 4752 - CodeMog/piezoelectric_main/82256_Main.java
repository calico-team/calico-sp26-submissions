import java.io.*;

  public class Main {
      public static void main(String[] args) throws Exception {
          FastScanner fs = new FastScanner(System.in);
          StringBuilder sb = new StringBuilder();

          int T = fs.nextInt();
          for (int tc = 0; tc < T; tc++) {
              int L = fs.nextInt();
              int W = fs.nextInt();
              int E = fs.nextInt();
              int R = fs.nextInt();

              int triangle_area = 2 * (L + W);
              int electricityPerLap = triangle_area * R;
              int laps = E / electricityPerLap;

              sb.append(laps).append('\n');
          }

          System.out.print(sb.toString());
      }

      static class FastScanner {
          private final InputStream in;
          private final byte[] buffer = new byte[1 << 16];
          private int ptr = 0, len = 0;

          FastScanner(InputStream is) {
              in = is;
          }

          private int read() throws IOException {
              if (ptr >= len) {
                  len = in.read(buffer);
                  ptr = 0;
                  if (len <= 0) return -1;
              }
              return buffer[ptr++];
          }

          int nextInt() throws IOException {
              int c;
              do {
                  c = read();
              } while (c <= ' ');

              int sign = 1;
              if (c == '-') {
                  sign = -1;
                  c = read();
              }

              int val = 0;
              while (c > ' ') {
                  val = val * 10 + (c - '0');
                  c = read();
              }
              return val * sign;
          }
      }

      static String read_your_input() throws Exception {
          ByteArrayOutputStream baos = new ByteArrayOutputStream();
          byte[] buf = new byte[4096];
          int n;
          while ((n = System.in.read(buf)) != -1) {
              baos.write(buf, 0, n);
          }
          return baos.toString();
      }
  }
