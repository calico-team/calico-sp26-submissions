import java.io.*;
import java.util.StringTokenizer;

public class Japan {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());
		int t = Integer.parseInt(st.nextToken());

        for(int i = 0; i<t; i++){
            st = new StringTokenizer(r.readLine());
            int L = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());

            int PE = (2*L+2*W)*R;

            int ans = E/PE;

            pw.println(ans);
        }
		pw.close();
	}
}
