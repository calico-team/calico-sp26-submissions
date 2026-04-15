package gridFill;
import java.util.*;
import java.io.*;
public class GridFill {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb=new StringBuilder();
		int testNum =Integer.parseInt(br.readLine());
		for(int i=0; i<testNum; i++) {
			int length=Integer.parseInt(br.readLine());
			String[]a=br.readLine().split("\\s+");
			int []an=new int[length];
			for(int j=0; j<a.length; j++) {
				an[j]=Integer.parseInt(a[j]);
			}
			int most=an[0];
			int mostCount=0;
			for(int j=0; j<length; j++) {
				int count=0;
				for(int k=j; k<length; k++) {
					if(an[j]==an[k]) {
						count++;
					}
				}
				if(count>mostCount) {
					mostCount=count;
					most=an[j];
				}
			}
			for(int j=0;j<length; j++) {
				sb.append(most).append(" ");
			}
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		br.close();
		bw.close();
	}

}
