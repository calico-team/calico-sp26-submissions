import java.io.*;
import java.util.StringTokenizer;
import java.lang.*;

public class BigBen {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());
		int t = Integer.parseInt(st.nextToken());

        for(int i = 0; i<t; i++){
            st = new StringTokenizer(r.readLine());
            String A = st.nextToken();
            st = new StringTokenizer(r.readLine());
            String B = st.nextToken();

            int currB = 0;

            StringBuilder newA = new StringBuilder(A);

            for(int x = 0; x<A.length(); x++){
                if(currB < B.length()){
                    if(A.charAt(x) == B.charAt(currB)){
                        currB++;
                    }else{
                        newA.setCharAt(x, '#');
                    }
                }else{
                    newA.setCharAt(x, '#');
                }
            }

            A = newA.toString();
            pw.println(A);
        }

		pw.close();
	}
}
