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
            for (int a = 0; a < mat.length; a++) {
                for (int b = 0; b < mat[0].length; b++) {
                    while (found == false) {
                        if (a + q < m && b + p < n) {
                            for (int s = 1; s < k; s++){
                                if (mat[a+q][b+p] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                            mat[a+q][b+p] = mat[a][b];
                            a = a+q;
                            b = b+p;
                            
                        } else if (a + q > m && b + p < n) {
                            for (int s = 1; s < k; s++){
                                if (mat[((a+q)-a)-3][b+p] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                            mat[((a+q)-a)-3][b+p] = mat[a][b];
                            a = ((a+q)-a)-3;
                            b = b+p;
                        } else if (a + q < m && b + p > n) {
                            for (int s = 1; s < k; s++){
                                if (mat[a+q][(b+p)-b-2] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                            mat[a+q][(b+p)-b-2] = mat[a][b];
                            a = a+q;
                            b = ((b+p)-b)-2;
                        } else if (a + q > m && b + p > n){
                            for (int s = 1; s < k; s++){
                                if (mat[((a+q)-a)-3][(b+p)-b-2] == s) {
                                    System.out.println(s);
                                    found = true;
                                }
                            }
                            mat[((a+q)-a)-3][b] = mat[a][b];
                            a = ((a+q)-a)-3;
                            mat[a][(b+p)-b-2] = mat[a][b];
                            b = ((b+p)-b)-2;
                            // for (int s = 1; s < k; s++){
                            //     if (mat[a][b] == s) {
                            //         System.out.println(s);
                            //         found = true;
                            //     }
                            // }
                        }
                    }
                }
            }
            

        }

        scan.close();
    }
}
