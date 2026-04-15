import java.io.*;
import java.util.ArrayList;

class Solution {
    /**
     * Return the total number of tiles mycelium will ever occupy.
     *
     * XG: x-coordinate of grass starting position
     * YG: y-coordinate of grass starting position
     * XM: x-coordinate of mycelium starting position
     * YM: y-coordinate of mycelium starting position
     */
    static final int mid = 25000;
    static int solve(int XG, int YG, int XM, int YM) {
        boolean[][]arr = new boolean[50000][50000];
        ArrayList<int[]>g= new ArrayList<>(), m= new ArrayList<>();
        int mycCount = 1;
        XG += mid;
        YG += mid;
        XM += mid;
        YM += mid;
        arr[YG][XG] = true;
        arr[YM][XM] = true;
        g.add(new int[]{YG,XG});
        m.add(new int[]{YM,XM});
        boolean go = true;
        int c = 1;
        while(go) {
            if(c % 2 == 0){
                int size = g.size();
                ArrayList<int[]> g2 = new ArrayList<>();
                for (int i = 0; i < size; i++) {
                    int[] curr = g.get(i);
                    int xD = XM - curr[1];
                    int yD = YM - curr[0];
                    int X_G = curr[1];
                    int Y_G = curr[0];

                    if(arr[Y_G + 1][X_G] == false){
                        arr[Y_G + 1][X_G] = true;
                        g2.add(new int[]{Y_G + 1, X_G});
                    }
                    if(arr[Y_G - 1][X_G] == false){
                        arr[Y_G - 1][X_G] = true;
                        g2.add(new int[]{Y_G - 1, X_G});
                    }
                    if(arr[Y_G][X_G + 1] == false){
                        arr[Y_G][X_G + 1] = true;
                        g2.add(new int[]{Y_G, X_G + 1});
                    }
                    if(arr[Y_G][X_G - 1] == false){
                        arr[Y_G][X_G - 1] = true;
                        g2.add(new int[]{Y_G, X_G - 1});
                    }
                }
                g = g2;
            }
            if(c % 7 ==0)  {
                boolean added = false;
                int size = m.size();
                ArrayList<int[]> m2 = new ArrayList<>();
                for (int i = 0; i < size; i++) {
                    int[] curr = m.get(i);
                    int X_G = curr[1];
                    int Y_G = curr[0];

                    if(arr[Y_G + 1][X_G] == false){
                        arr[Y_G + 1][X_G] = true;
                        added = true;
                        m2.add(new int[]{Y_G + 1, X_G});
                        mycCount++;
                    }
                    if(arr[Y_G - 1][X_G] == false){
                        arr[Y_G - 1][X_G] = true;
                        added = true;
                        m2.add(new int[]{Y_G - 1, X_G});
                        mycCount++;
                    }
                    if(arr[Y_G][X_G + 1] == false){
                        arr[Y_G][X_G + 1] = true;
                        added = true;
                        m2.add(new int[]{Y_G, X_G + 1});
                        mycCount++;
                    }
                    if(arr[Y_G][X_G - 1] == false){
                        arr[Y_G][X_G - 1] = true;
                        added = true;
                        m2.add(new int[]{Y_G, X_G - 1});
                        mycCount++;
                    }
                }
                m = m2;
                if(!added) return mycCount;
            }
            if(c > 10000000) return -1;
            c++;
        }
        return -1;
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String[] temp = in.readLine().split(" ");
            int XG = Integer.parseInt(temp[0]), YG = Integer.parseInt(temp[1]);
            int XM = Integer.parseInt(temp[2]), YM = Integer.parseInt(temp[3]);
            out.println(solve(XG, YG, XM, YM));
        }
        out.flush();
    }
}
