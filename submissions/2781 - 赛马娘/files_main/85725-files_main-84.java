import java.io.*;
import java.util.ArrayList;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     *
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        char[] achars = A.toCharArray();
        char[] bchars = B.toCharArray();
        int blength = bchars.length;
        int alength = achars.length;
        ArrayList<Integer> foundindexes = new ArrayList<Integer>();
        for(int i = 0; i<blength;i++){
            char temp = bchars[i];
            int found = -1;
            for (int z = 0; z < achars.length; z++) {

                if (achars[z] == temp&& foundindexes.indexOf(z)==-1&&(foundindexes.size()==0||z>foundindexes.get(foundindexes.size()-1))) {
                    found = z;
                    foundindexes.add(found);
                    break;
                }
            }
        }
        for(int i = 0; i<alength; i++){

            boolean x = true;
            for(int z = 0; z<foundindexes.size();z++){
                if(foundindexes.get(z)==i){
                    x=false;
                    break;
                }
            }
            if(x){
                achars[i]='#';
            }




        }



        return String.valueOf(achars);
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String A = in.readLine();
            String B = in.readLine();
            out.println(solve(A, B));
        }
        out.flush();
    }
}
