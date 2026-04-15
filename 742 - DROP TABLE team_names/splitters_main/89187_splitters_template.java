import java.io.*;
import java.util.*;

class splitters_template {
    public static int total = 1, collected = 0;
    public static char[][] grid;

    enum Dir {
        UP, RIGHT, DOWN, LEFT
    }

    static long[] solve(int N, int M, String[] factory) throws Exception {

        grid = new char[N][M]; 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                grid[i][j] = factory[i].charAt(j); 

        if (grid[0][0] == 'X') return new long[]{0, 1};

        

        return func(0, 0, null);
    }

    static long[] func(int x, int y, Dir dir) throws Exception {

        if(dir != null) {
            total++;
            switch (dir) {
                case UP    -> y--;
                case DOWN  -> y++;
                case RIGHT -> x++;
                case LEFT  -> x--;
            }

        }

        while (true) {

            if (isArrow(grid[y][x])) { 
                int[] next = move(x, y);
                x = next[0];
                y = next[1];
            }

            
            if (x >= grid[0].length || x < 0 || y >= grid.length || y < 0) {
                collected++;
                return new long[]{1, 1};
            }

            if (grid[y][x] == 'X') return new long[]{0, 1};
            

            if (grid[y][x] == 'S') {  
                  List<Dir> dirs = getValidDirs(x, y);
                    int N = dirs.size();
                    int sumNum = 0, sumDen = 1;

                    for (Dir d : dirs) {
                        long[] branch = func(x, y, d);
                        int tempNum = (int)(sumNum * branch[1] + branch[0] * sumDen),
                            tempDen = (int)(sumDen * branch[1]);
                        int gcd = gcd(Math.abs(tempNum), tempDen);
                        sumNum = tempNum / gcd;
                        sumDen = tempDen / gcd;
                    }
                    
                    int finalDen = sumDen * N;
                    int gcd = gcd(Math.abs(sumNum), finalDen);
                    return new long[]{sumNum/gcd, finalDen/gcd};
            }
        }
        
    }

    static List<Dir> getValidDirs(int x, int y) {
        List<Dir> returned = new ArrayList<>();
        if ((x + 1 < grid[0].length) && (grid[y][x+1] == 'X' || arrowExcept(grid[y][x+1], '<'))) returned.add(Dir.RIGHT); 
        if ((x - 1 >= 0)             && (grid[y][x-1] == 'X' || arrowExcept(grid[y][x-1], '>'))) returned.add(Dir.LEFT);  
        if ((y + 1 < grid.length)    && (grid[y+1][x] == 'X' || arrowExcept(grid[y+1][x], '^'))) returned.add(Dir.DOWN);    
        if ((y - 1 >= 0)             && (grid[y-1][x] == 'X' || arrowExcept(grid[y-1][x], 'v'))) returned.add(Dir.UP);  
        return returned;
    }

    static boolean arrowExcept(char c, char exception) {
        if (c == exception) return false;
        return c == '^' || c == '>' || c == 'v' || c == '<';
    }

    static boolean isArrow(char c) {
        return c == '^' || c == '>' || c == 'v' || c == '<';
    }

    static int[] move(int x, int y) throws Exception {
        return switch (grid[y][x]) {
            case '^' -> new int[]{x,     y - 1};
            case 'v' -> new int[]{x,     y + 1};
            case '<' -> new int[]{x - 1, y    };
            case '>' -> new int[]{x + 1, y    };
            default  -> throw new Exception();
        };
    }

    static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int T = Integer.parseInt(br.readLine().trim());
        for (int t = 0; t < T; t++) {
            total = 1; collected = 0; grid = null;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            String[] factory = new String[N];
            for (int i = 0; i < N; i++) factory[i] = br.readLine();
            long[] ans = solve(N, M, factory);
            pw.println(ans[0] + " " + ans[1]);
            pw.flush();
        }
    }
}