package theBigBenFiles;
import java.util.*;
import java.io.*;
public class TheBigBenFiles {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb=new StringBuilder();
		int testNum =Integer.parseInt(br.readLine());
		for(int i=0; i<testNum; i++) {
			String a=br.readLine();
			String b=br.readLine();
			String result="";
			int k=0;
			for(int j=0; j<a.length(); j++) {
				if(a.substring(j,j+1).equals(b.substring(k,k+1))) {
					result=result+b.substring(k,k+1);
					k++;
					if(k>=b.length()) {
						break;
					}
				}
				else {
					result=result+"#";
				}
			}
			while(a.length()>result.length()) {
				result=result+"#";
			}
			sb.append(result).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		br.close();
		bw.close();
	}

}
