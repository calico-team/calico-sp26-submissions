import java.util.*;
import java.io.*;


	
	public class problem8 {
	    public static void main(String[] args) throws IOException {
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        int T = Integer.parseInt(br.readLine());
	        while (T-- > 0) {
	            StringTokenizer st = new StringTokenizer(br.readLine());
	            long P = Long.parseLong(st.nextToken());
	            int A = Integer.parseInt(st.nextToken());
	            int B = Integer.parseInt(st.nextToken());

	            List<String> grid = buildFactory(P, A, B);
	            System.out.println(grid.size() + " " + grid.get(0).length());
	            for (String row : grid) {
	                System.out.println(row);
	            }
	        }
	        br.close();
	    }

	    private static List<String> buildFactory(long P, int A, int B) {
	        List<StringBuilder> grid = new ArrayList<>();
	        int rows = 1;
	        int cols = 1;
	        grid.add(new StringBuilder(">")); 

	        
	        for (int i = 0; i < A; i++) {
	            	            cols++;
	            for (StringBuilder row : grid) {
	                row.append('.');
	            }
	            grid.get(0).setCharAt(cols - 1, '>');

	            
	            cols++;
	            for (StringBuilder row : grid) {
	                row.append('.');
	            }
	            grid.get(0).setCharAt(cols - 1, 'S');

	            rows++;
	            StringBuilder newRow = new StringBuilder();
	            for (int j = 0; j < cols; j++) {
	                newRow.append('.');
	            }
	            newRow.setCharAt(cols - 2, 'v'); 
	            grid.add(newRow);

	            
	            grid.get(0).append('>');
	            grid.get(1).append('>');
	            cols++;
	        }

	        for (int i = 0; i < B; i++) {
	            cols++;
	            for (StringBuilder row : grid) {
	                row.append('.');
	            }
	            grid.get(0).setCharAt(cols - 1, '>');

	            
	            cols++;
	            for (StringBuilder row : grid) {
	                row.append('.');
	            }
	            grid.get(0).setCharAt(cols - 1, 'S');

	            
	            for (int r = 1; r <= 2; r++) {
	                if (rows <= r) {
	                    StringBuilder newRow = new StringBuilder();
	                    for (int j = 0; j < cols; j++) {
	                        newRow.append('.');
	                    }
	                    newRow.setCharAt(cols - 2, 'v');
	                    grid.add(newRow);
	                    rows++;
	                } else {
	                    grid.get(r).setCharAt(cols - 2, 'v');
	                }
	            }

	            
	            for (int r = 0; r < 3; r++) {
	                grid.get(r).append('>');
	            }
	            cols++;
	        }

	     
	        int totalPaths = (int) (P);
	        int currentRow = 0;
	        for (int r = 0; r < rows; r++) {
	            if (r < totalPaths) {
	                grid.get(r).append('v');
	            } else {
	        
	                grid.get(r).append('X');
	            }
	            cols++;
	        }

	        for (StringBuilder row : grid) {
	            while (row.length() < cols) {
	                row.append('.');
	            }
	        }

	        List<String> res = new ArrayList<>();
	        for (StringBuilder row : grid) {
	            res.add(row.toString());
	        }
	        return res;
	    }
	} 