import java.util.*;
import java.io.*;

public class Japan
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(sc.readLine());

        while(testcases-- > 0)
        {
            String[] params = sc.readLine().split(" ");

            // int T = Integer.parseInt(params[0]);
            int L = Integer.parseInt(params[0]);
            int W = Integer.parseInt(params[1]);
            int E = Integer.parseInt(params[2]);
            int R = Integer.parseInt(params[3]);

            int perimeter = L*2+W*2;
            int energyGenerated = perimeter*R;

            System.out.println(E/energyGenerated);
        }
    }
}