import java.util.*;
import java.io.*;

public class nah
{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- >0){
		    String s = br.readLine();
		    StringTokenizer st = new StringTokenizer(s);
		    int n = Integer.parseInt(st.nextToken());
		    int[] curses = new int[n];
		    int p = Integer.parseInt(st.nextToken());
		    int r = Integer.parseInt(st.nextToken());
		    int k = Integer.parseInt(st.nextToken());
		    String q = br.readLine();
		    st = new StringTokenizer(q);
		    for(int i = 0;i<n;i++){
		        curses[i] = Integer.parseInt(st.nextToken());
		    }
		    int count = 0;
		    boolean defeated = false;
		    int i = 0;
		    int lastk = 0;
		    while(i<n){
		        p -= curses[i];
		        if(p < 0){
		            defeated = true;
		            break;
		        }
		        if(i + 1 < n){
		            count++;
		            if(p < curses[i+1]){
    		            if(count >= k){
    		                p += r;
    		                count = 0;
    		            }
		            } else if(count >=k){
		                p += r;
		                count = 0;
		            }
		        }
		        i++;
		    }
		    if(defeated) System.out.println("nah i'd lose");
		    else System.out.println("nah i'd win");
		}
	}
}
