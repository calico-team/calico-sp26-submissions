package japanIsTurningFootstepsIntoElectricity;
import java.util.*;
import java.io.*;
public class JapanIsTurningFootstepsIntoElectricity {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb=new StringBuilder();
		int testNum =Integer.parseInt(br.readLine());
		for(int i=0; i<testNum; i++) {
			String[]s=br.readLine().split("\\s+");
			int l=Integer.parseInt(s[0]);
			int w=Integer.parseInt(s[1]);
			int e=Integer.parseInt(s[2]);
			int r=Integer.parseInt(s[3]);
			sb.append(e/((l+w)*2*r)).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		br.close();
		bw.close();
	}
	

}
