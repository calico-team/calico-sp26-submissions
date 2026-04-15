import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

class filesSolution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        String original = A;
        String goal = B;
        String[] array= new String[goal.length()];
        
        String tempLetter="";
        boolean foundmatch = false;
        String result ="";
        for (int i=0; i<goal.length(); i++ ) {

            tempLetter=goal.substring(i,i+1);
             array[i]=tempLetter;
             
        }
        
        int k =0;  //track for each letter of goal
            for (int j=0; j<original.length(); j++){ //loop for checking each letter in original
                
                if (k < goal.length() && original.substring(j, j+1).equals(array[k])) { //if they are equal then found match move to next one
                    result = result + original.substring(j, j+1);
                    k++;
                 }
                 else{
                     result= result+"#" ;
                 }
                 
            }
            
        
        //(array[k].equals(original.substring(j, j+1))
        //original.substring(j, j+1).equals(array[k])
       //original.substring(0, j) +
       //+original.substring(j+1)
        
        // YOUR CODE HERE
        return result;
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

/*  split string b into letters done
find first instace of that letter in string a
 only keep first one
replace all other ones with #
 go to next letter
*/