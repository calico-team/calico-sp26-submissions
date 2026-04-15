import java.util.*;
public class calico_2 {
    public static void main (String[] args) {
        Scanner scan = new Scanner (System.in);
        boolean found = false;
        int test = scan.nextInt();
        int count = 1;
        for (int i = 0; i < test; i++) {
            int k = scan.nextInt();
            int n = scan.nextInt();
            int m = scan.nextInt();
            int p = scan.nextInt();
            int q = scan.nextInt();
            int [][] mat = new int [n][m];
            int coordx = scan.nextInt();
            int coordy = scan.nextInt();
            mat[coordx][coordy] = 0;
            for (int j = 0; j < k-1; j++) {
                int cx = scan.nextInt();
                int cy = scan.nextInt();
                mat[cx][cy] = count;
                count++;
            }
            while (found == false) {
                for (int a = 0; a < mat.length; a++) {
                    for (int b = 0; b < mat[0].length; b++) {
                        if (a + q < m && b + p < n) {
                            mat[a+q][b+p] = mat[a][b];
                            a = a+q;
                            b = b+p;
                            for (int s = 1; s < k; s++){
                                if (mat[a][b] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                        } else if (a + q > m && b + p < n) {
                            mat[((a+q)-a)-3][b+p] = mat[a][b];
                            a = ((a+q)-a)-3;
                            b = b+p;
                            for (int s = 1; s < k; s++){
                                if (mat[a][b] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                        } else if (a + q < m && b + p > n) {
                            mat[a+q][(b+p)-b-2] = mat[a][b];
                            a = a+q;
                            b = ((b+p)-b)-2;
                            for (int s = 1; s < k; s++){
                                if (mat[a][b] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                        } else if (a + q > m && b + p > n){
                            mat[((a+q)-a)-3][b+p] = mat[a][b];
                            a = ((a+q)-a)-3;
                            b = b+p;
                            mat[a+q][(b+p)-b-2] = mat[a][b];
                            a = a+q;
                            b = ((b+p)-b)-2;
                            for (int s = 1; s < k; s++){
                                if (mat[a][b] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
            

        }

        scan.close();
    }
}
