import java.util.*;
import java.io.*;

public class BigBen
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(sc.readLine());

        while(testcases-- > 0)
        {
            String A = sc.readLine();
            String B = sc.readLine();

            Queue<Character> queue = new LinkedList<>();

            for(char c : B.toCharArray())
            {
                queue.add(c);
            }

            for(char c : A.toCharArray())
            {
                if(queue.size() > 0 && c == queue.peek())
                {
                    System.out.print(c);
                    // count.put(c,count.get(c)-1);
                    queue.remove();
                }
                else
                    System.out.print("#");
            }

            System.out.println();
        }
    }
}
