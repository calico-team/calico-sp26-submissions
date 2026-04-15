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

        Point grassStart = new Point(xg, yg);
        Point myceliumStart = new Point(xm, ym);
        grass.add(grassStart);
        mycelium.add(myceliumStart);

        Map<Point, Integer> grassTime = new HashMap<>();
        Map<Point, Integer> mycTime = new HashMap<>();
        grassTime.put(grassStart, 0);
        mycTime.put(myceliumStart, 0);

        Queue<Point> grassQueue = new LinkedList<>();
        Queue<Point> mycQueue = new LinkedList<>();
        grassQueue.add(grassStart);
        mycQueue.add(myceliumStart);

        int maxTick = 1000;
        for (int tick = 1; tick <= maxTick; tick++) {
            if (tick % 2 == 0) {
                int size = grassQueue.size();
                for (int i = 0; i < size; i++) {
                    Point p = grassQueue.poll();
                    for (int[] dir : DIRS) {
                        long nx = p.x + dir[0];
                        long ny = p.y + dir[1];
                        Point newP = new Point(nx, ny);
                        if (!grass.contains(newP) && !mycelium.contains(newP)) {
                            grass.add(newP);
                            grassTime.put(newP, tick);
                            grassQueue.add(newP);
                        }
                    }
                }
            }

            if (tick % 7 == 0) {
                int size = mycQueue.size();
                for (int i = 0; i < size; i++) {
                    Point p = mycQueue.poll();
                    for (int[] dir : DIRS) {
                        long nx = p.x + dir[0];
                        long ny = p.y + dir[1];
                        Point newP = new Point(nx, ny);
                        if (!grass.contains(newP) && !mycelium.contains(newP)) {
                            mycelium.add(newP);
                            mycTime.put(newP, tick);
                            mycQueue.add(newP);
                        }
                    }
                }
            }

            if (tick % 2 == 0 && tick % 7 == 0) {
                Iterator<Point> iter = mycelium.iterator();
                while (iter.hasNext()) {
                    Point p = iter.next();
                    if (grassTime.containsKey(p) && grassTime.get(p) == tick) {
                        iter.remove();
                        mycTime.remove(p);
                    }
                }
            }
        }

        mycelium.removeAll(grass);
        return mycelium.size();
    }
}