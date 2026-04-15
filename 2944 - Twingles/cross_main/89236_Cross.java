import java.util.Scanner;
public class Cross {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int a = 0; a < t; a++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int [][] arr = new int[n][m];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(i == 0) {
                        arr[i][j] = 0;
                    } else if(j == 0){
                        arr[i][j] = 1;
                    } else if(i == n-1){
                        arr[i][j] = 3;
                    } else if(j == m-1){
                        arr[i][j] = 4;
                    } else {
                        arr[i][j] = -1;
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(arr[i][j] == -1) {
                        boolean zero = true;
                        boolean one = true;
                        boolean two = true;
                        boolean three = true;
                        boolean four = true;
                        if(arr[i-1][j] == 0) {
                            zero = false;
                        } else if(arr[i-1][j] == 1) {
                            one = false;
                        } else if(arr[i-1][j] == 2) {
                            two = false;
                        } else if(arr[i-1][j] == 3) {
                            three = false;
                        } else  if(arr[i-1][j] == 4) {
                            four = false;
                        }


                        if(arr[i+1][j] == 0) {
                            zero = false;
                        } else if(arr[i+1][j] == 1) {
                            one = false;
                        } else if(arr[i+1][j] == 2) {
                            two = false;
                        } else if(arr[i+1][j] == 3) {
                            three = false;
                        } else  if(arr[i+1][j] == 4) {
                            four = false;
                        }

                        if(arr[i][j-1] == 0) {
                            zero = false;
                        } else if(arr[i][j-1] == 1) {
                            one = false;
                        } else if(arr[i][j-1] == 2) {
                            two = false;
                        } else if(arr[i][j-1] == 3) {
                            three = false;
                        } else  if(arr[i][j-1] == 4) {
                            four = false;
                        }

                        if(arr[i][j+1] == 0) {
                            zero = false;
                        } else if(arr[i][j+1] == 1) {
                            one = false;
                        } else if(arr[i][j+1] == 2) {
                            two = false;
                        } else if(arr[i][j+1] == 3) {
                            three = false;
                        } else  if(arr[i][j+1] == 4) {
                            four = false;
                        }

                        if(one) {
                            arr[i][j] = 1;
                        } else if(two) {
                            arr[i][j] = 2;
                        } else if(three) {
                            arr[i][j] = 3;
                        } else if(four) {
                            arr[i][j] = 4;
                        } else if(zero) {
                            arr[i][j] = 0;
                        }
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(j != m-1) {
                        System.out.print(arr[i][j] + " ");
                    } else {
                        System.out.print(arr[i][j]);
                    }
                }
                System.out.println();
            }
        }
    }

}
