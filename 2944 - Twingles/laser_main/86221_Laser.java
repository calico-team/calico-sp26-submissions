import java.util.*;
public class Laser {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t  = scanner.nextInt();
        for(int a = 0; a < t; a++) {
            int k = scanner.nextInt();
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int p = scanner.nextInt();
            int q = scanner.nextInt();
            int [][] arr = new int[k][2];
            for(int i = 0; i < k; i++) {
                arr[i][0] = scanner.nextInt();
                arr[i][1] = scanner.nextInt();
            }
            int laserX = arr[0][0];
            int laserY = arr[0][1];
            int prevX  = laserX;
            int prevY = laserY;
            boolean bool = true;
            boolean starting = true;
            while(bool) {
                if(laserX > n-1) {
                    laserX -= (n-1);
                }
                if(laserY > m-1) {
                    laserY -= (m-1);
                }
                for(int i = 0; i < k; i++) {
                    if((arr[i][0] >= prevX && arr[i][0] <= laserX) && (arr[i][1] >= prevY && arr[i][1] <= laserY) && arr[i][1] == laserY && !starting) {
                        System.out.println(i);
                        bool = false;
                        break;
                    }
                    if(prevX > laserX && prevY > laserY) {
                        if((arr[i][0] <= prevX && arr[i][0] >= laserX) && (arr[i][1] <= prevY && arr[i][1] >= laserY) && arr[i][1] == laserY && !starting) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                        if(arr[i][0] >= 0 && arr[i][0] <= laserX && arr[i][1] >= 0 && arr[i][1] <= laserY) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                        if(arr[i][0] <= n-1 && arr[i][0] >= prevX && arr[i][1] <= m-1 &&  arr[i][1] >= prevY) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                    }
                    if(prevX > laserX) {
                        if((arr[i][0] <= prevX && arr[i][0] >= laserX) && (arr[i][1] >= prevY && arr[i][1] <= laserY) && arr[i][1] == laserY && !starting) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                        if(arr[i][0] >= 0 && arr[i][0] <= laserX &&  arr[i][1] >= prevY && arr[i][1] <= laserY) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                        if(arr[i][0] >= prevX && arr[i][1] >= prevY) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                        double slope = q/p;
                        double y2 = slope*(n-1) - slope*prevX + prevY;
                        if(arr[i][1] >= prevY && arr[i][1] <= y2 && arr[i][0] >= prevX) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                    }
                    if(prevY > laserY) {
                        if((arr[i][0] >= prevX && arr[i][0] <= laserX) && (arr[i][1] <= prevY && arr[i][1] >= laserY) && arr[i][1] == laserY && !starting) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                        if(arr[i][0] >= prevX && arr[i][0] <= laserX && arr[i][1] >= 0 && arr[i][1] <= laserY) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                        double slope = q/p;
                        double x2 = ((m-1) - prevY + slope*prevX)/slope;
                        if(arr[i][1] >= prevY && arr[i][0] >= prevX && arr[i][0] <= x2) {
                            System.out.println(i);
                            bool = false;
                            break;
                        }
                    }
                    starting = false;
                }
                prevX = laserX;
                prevY = laserY;
                laserX += q;
                laserY += p;
            }

        }

    }
}
