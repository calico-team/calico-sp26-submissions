 import java.io.*;

  public class Main {
      public static void main(String[] args) throws Exception {
          FastScanner fs = new FastScanner(System.in);
          StringBuilder out = new StringBuilder();

          int T = fs.nextInt();
          while (T-- > 0) {
              int N = fs.nextInt();
              long P = fs.nextLong();
              long R = fs.nextLong();
              int K = fs.nextInt();

              long dylan_power = P;
              long charges = 0;
              boolean ok = true;
              int defeated = 0;

              for (int i = 0; i < N; i++) {
                  long e = fs.nextLong();

                  if (ok) {
                      if (dylan_power < e) {
                          if (R > 0 && charges > 0) {
                              long need = e - dylan_power;
                              long use = (need + R - 1) / R;
                              if (use > charges) use = charges;
                              dylan_power += use * R;
                              charges -= use;
                          }
                      }

                      if (dylan_power < e) {
                          ok = false;
                      } else {
                          dylan_power -= e;
                          defeated++;
                          if (defeated % K == 0) charges++;
                      }
                  }
              }

              out.append(ok ? "nah i'd win" : "nah i'd lose").append('\n');
          }

          System.out.print(out.toString());
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
              do c = read(); while (c <= ' ' && c != -1);
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

          long nextLong() throws IOException {
              int c;
              do c = read(); while (c <= ' ' && c != -1);
              int sign = 1;
              if (c == '-') {
                  sign = -1;
                  c = read();
              }
              long val = 0;
              while (c > ' ') {
                  val = val * 10 + (c - '0');
                  c = read();
              }
              return sign == 1 ? val : -val;
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