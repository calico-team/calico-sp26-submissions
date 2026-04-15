public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            int P = sc.nextInt();
            int A = sc.nextInt();
            int B = sc.nextInt();
            
            int r = 2;
            int c = A + B + 10;
            char[][] g = new char[r][c];
            
            for (int i=0; i<r; i++)
                for (int j=0; j<c; j++)
                    g[i][j] = '.';
            
            g[0][0] = '>';
            int p = 1;
            
            for (int i=0; i<A; i++) {
                g[0][p] = 'S';
                g[0][p+1] = '>';
                g[1][p] = 'X';
                p++;
            }
            
            for (int i=0; i<B; i++) {
                g[0][p] = 'S';
                g[0][p+1] = '>';
                g[1][p] = 'X';
                p++;
            }
            
            g[0][p] = 'E';
            
            System.out.println(r + " " + c);
            for (char[] row : g)
                System.out.println(new String(row));
        }
    }
}