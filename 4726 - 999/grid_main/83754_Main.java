import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++)
        {

            int n=sc.nextInt();
            long[] arr=new long[n];
            for(int j=0;j<n;j++)
            {
                arr[j]=sc.nextLong();
            }
            long[] ans=new long[n];
            for(int j=0;j<n;j++){
                if(j==0 || j==n-1){
                    ans[j]=arr[j];
                }else if(arr[j]==ans[j-1]){
                    ans[j]=arr[j];
                }else{
                    if(arr[j+1]>=arr[j] && arr[j+1]>=ans[j-1]){
                        ans[j]=Math.max(ans[j-1],arr[j]);
                    }else if(arr[j+1]>=arr[j] && arr[j+1]<=ans[j-1] || arr[j+1]<=arr[j] && arr[j+1]>=ans[j-1]){
                        ans[j]=arr[j+1];
                    }else{
                        ans[j]=Math.min(ans[j-1],arr[j]);
                    }
                }
            }
            for(int j=0;j<n-1;j++){
                System.out.print(ans[j]+" ");
            }
            System.out.print(ans[n-1]);
        }
    }
}