
import java.util.*;

public class Main {
    private static final int[][] DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private static class Point {
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            long xg = sc.nextLong();
            long yg = sc.nextLong();
            long xm = sc.nextLong();
            long ym = sc.nextLong();
            System.out.println(calculateMycelium(xg, yg, xm, ym));
        }
        sc.close();
    }

    private static long calculateMycelium(long xg, long yg, long xm, long ym) {
        Set<Point> grass = new HashSet<>();
        Set<Point> mycelium = new HashSet<>();
        Queue<Point> grassQueue = new LinkedList<>();
        Queue<Point> myceliumQueue = new LinkedList<>();

        Point grassStart = new Point(xg, yg);
        Point myceliumStart = new Point(xm, ym);
        grass.add(grassStart);
        grassQueue.add(grassStart);
        mycelium.add(myceliumStart);
        myceliumQueue.add(myceliumStart);

        int tick = 0;
        boolean spreading = true;
        int idleTicks = 0;

        while (spreading && idleTicks < 100) {
            tick++;
            boolean newGrass = false;
            boolean newMyc = false;

            if (tick % 2 == 0) {
                int grassSize = grassQueue.size();
                for (int i = 0; i < grassSize; i++) {
                    Point p = grassQueue.poll();
                    for (int[] dir : DIRS) {
                        long nx = p.x + dir[0];
                        long ny = p.y + dir[1];
                        Point newP = new Point(nx, ny);
                        if (!grass.contains(newP) && !mycelium.contains(newP)) {
                            grass.add(newP);
                            grassQueue.add(newP);
                            newGrass = true;
                        }
                    }
                }
            }

            if (tick % 7 == 0) {
                int mycSize = myceliumQueue.size();
                for (int i = 0; i < mycSize; i++) {
                    Point p = myceliumQueue.poll();
                    for (int[] dir : DIRS) {
                        long nx = p.x + dir[0];
                        long ny = p.y + dir[1];
                        Point newP = new Point(nx, ny);
                        if (!grass.contains(newP) && !mycelium.contains(newP)) {
                            mycelium.add(newP);
                            myceliumQueue.add(newP);
                            newMyc = true;
                        }
                    }
                }
            }

            if ((tick % 2 == 0) && (tick % 7 == 0)) {
                Iterator<Point> iter = mycelium.iterator();
                while (iter.hasNext()) {
                    Point p = iter.next();
                    if (grass.contains(p)) {
                        iter.remove();
                    }
                }
            }

            spreading = newGrass || newMyc;
            if (!spreading) {
                idleTicks++;
            } else {
                idleTicks = 0;
            }
        }

        return mycelium.size();
    }
}
