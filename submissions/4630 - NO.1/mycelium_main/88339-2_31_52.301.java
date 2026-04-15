import java.util.*;
import java.io.*;

public class problem8 {
	    static class Point {
	        long x, y;
	        Point(long x, long y) {
	            this.x = x;
	            this.y = y;
	        }
	        @Override
	        public boolean equals(Object o) {
	            if (this == o) return true;
	            if (o == null || getClass() != o.getClass()) return false;
	            Point point = (Point) o;
	            return x == point.x && y == point.y;
	        }
	        @Override
	        public int hashCode() {
	            return Objects.hash(x, y);
	        }
	    }

	    
	    private static long manhattan(long x1, long y1, long x2, long y2) {
	        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
	    }

	    public static void main(String[] args) throws IOException {
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        int T = Integer.parseInt(br.readLine());
	        
	        int[][] dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

	        while (T-- > 0) {
	            StringTokenizer st = new StringTokenizer(br.readLine());
	            long xg = Long.parseLong(st.nextToken());
	            long yg = Long.parseLong(st.nextToken());
	            long xm = Long.parseLong(st.nextToken());
	            long ym = Long.parseLong(st.nextToken());

	            Queue<Point> queue = new LinkedList<>();
	            Set<Point> visited = new HashSet<>();
	            Point start = new Point(xm, ym);
	            queue.add(start);
	            visited.add(start);
	            long myceliumCount = 0;

	            while (!queue.isEmpty()) {
	                Point curr = queue.poll();
	                long dM = manhattan(curr.x, curr.y, xm, ym);
	                long dG = manhattan(curr.x, curr.y, xg, yg);

	    
	                if (7 * dM < 2 * dG) {
	                    myceliumCount++;
	                 
	                    for (int[] dir : dirs) {
	                        long nx = curr.x + dir[0];
	                        long ny = curr.y + dir[1];
	                        Point next = new Point(nx, ny);
	                        if (!visited.contains(next)) {
	                            visited.add(next);
	                            queue.add(next);
	                        }
	                    }
	                }
	            }

	            System.out.println(myceliumCount);
	        }
	        br.close();
	    }
	}
