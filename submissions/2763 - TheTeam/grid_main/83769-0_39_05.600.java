import java.util.*;
import java.io.*;

public class Grid
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(sc.readLine());

        while(testcases-- > 0)
        {
            int N = Integer.parseInt(sc.readLine());

            String[] line = sc.readLine().split(" ");

            int[] arr = new int[N];

            for(int i = 0; i < line.length; i++)
                arr[i] = Integer.parseInt(line[i]);

            solve(N-1, arr, new int[N]);

            System.out.println(min.replaceAll("[\\[\\]\\,]", ""));
        }
    }

    // static TreeMap<Integer, String> table = new TreeMap<>();
    static long minSize = Integer.MAX_VALUE;
    static String min = "";

    public static void solve(int N, int[] arr, int[] b)
    {
        if(N < 0)
        {
            long sum = computeSum(arr, b);
            if(sum < minSize)
            {
                minSize = sum;
                min = Arrays.toString(b);
            }
            
            return;
        }

        for(int num : arr)
        {
            b[N] = num;
            solve(N-1, arr, b);
            // b[N] = 0;
        }

    }

    public static long computeSum(int[] a, int[] b)
    {
        long top = 0;
        long bottom = 0;
        long between = 0;

        for(int i = 1; i < a.length; i++)
        {
            top += Math.abs(a[i]-a[i-1]);
            bottom += Math.abs(b[i]-b[i-1]);
            between += Math.abs(a[i]-b[i]);
        }

        return top+bottom+between;
    } 
}