import java.util.*;
import java.io.*;

public class gridfill
{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- >0){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] A = new int[n];
            int[] B = new int[n];
            int maxNum = -1;
            for(int i = 0;i<n;i++){
                A[i] = Integer.parseInt(st.nextToken());
                B[i] = A[i];
                maxNum = Math.max(B[i], maxNum);
            }
            for(int i = 0;i<n;i++){
                if(i == 0 || i == n-1) continue;
                int curError = Integer.MAX_VALUE;
                int curVal = -1;
                for(int j = B[i];j<=maxNum;j++){
                    int localError = Math.abs(B[i-1]-j) + Math.abs(A[i]-j) + Math.abs(B[i+1]-j);
                    if(localError < curError) {
                        curError = localError;
                        curVal = j;
                    }
                }
                for(int j = B[i];j>0;j--){
                    int localError = Math.abs(B[i-1]-j) + Math.abs(A[i]-j) + Math.abs(B[i+1]-j);
                    if(localError < curError) {
                        curError = localError;
                        curVal = j;
                    }
                }
                B[i] = curVal;
            }
            for(int i = 0;i<n;i++){
                System.out.print(B[i] + " ");
            }
            System.out.println();
		}
	}
}
