import java.io.*;
import java.util.*;
public class D {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            HashMap<Point, Integer> points = new HashMap<>();
            Point pos = new Point(0, 0);
            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken()); int y = Integer.parseInt(st.nextToken());
                if(i==0) pos = new Point(x, y);
                points.put(new Point(x, y),i);
            }
             do {
                pos = new Point((pos.x + q) % n, (pos.y + p) % m);
                if(points.containsKey(pos)) {
                    bw.write(points.get(pos)+"\n");
                    break;
                }
            } while (!points.containsKey(pos));
        }
        bw.flush();
    }

}
class Point {
    int x;
    int y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Point points = (Point) o;
        return x == points.x && y == points.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}