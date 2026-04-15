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
            List<String> factory = buildValidFactory(P, A, B);
            System.out.println(factory.size() + " " + factory.get(0).length());
            for (String row : factory) {
                System.out.println(row);
            }
        }
        br.close();
    }

    private static List<String> buildValidFactory(long P, int A, int B) {
        List<StringBuilder> grid = new ArrayList<>();
        int rows = 1;
        int cols = 1;
        grid.add(new StringBuilder(">"));
        for (int i = 0; i < A; i++) {
            
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, '>');
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, '>'）；
            rows++;
            StringBuilder newRow = new StringBuilder();
            for (int j = 0; j < cols; j++) newRow.append('.');
            newRow.setCharAt(cols - 1, 'v'); 
            grid.add(newRow);
            grid.get(0).append('>');
            grid.get(1).append('>');
            cols++;
        }

       
        for (int i = 0; i < B; i++) {
           
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, '>');

            
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, 'S');

            for (int r = 1; r <= 2; r++) {
                if (rows <= r) {
                    StringBuilder newRow = new StringBuilder();
                    for (int j = 0; j < cols; j++) newRow.append('.');
                    newRow.setCharAt(cols - 1, 'v');
                    grid.add(newRow);
                    rows++;
                } else {
                    grid.get(r).setCharAt(cols - 1, 'v');
                }
            }

           
            for (int r = 0; r < 3; r++) grid.get(r).append('>');
            cols++;
        }
        int totalPaths = (int) (P);
        int maxRows = rows;
        cols++;
        for (StringBuilder row : grid) row.append('.');
        for (int r = 0; r < maxRows; r++) {
            if (r < totalPaths){
                grid.get(r).setCharAt(cols - 1, 'v');
            } else {
                
                grid.get(r).setCharAt(cols - 1, 'X');
            }
        } 
	for (StringBuilder row : grid) {
            while (row.length() < cols) row.append('.');
        }

        
        validateFactory(grid, A, B, P)
        List<String> res = new ArrayList<>();
        for (StringBuilder row : grid) res.add(row.toString());
        return res;
    }

  
    private static void validateFactory(List<StringBuilder> grid, int A, int B, long P) {
        int rows = grid.size();
        int cols = grid.get(0).length();
      
        if (rows * cols > 2000) throw new RuntimeException("Grid size exceeds 2000");
        
        char start = grid.get(0).charAt(0);
        if (start != '>' && start != '<' && start != '^' && start != 'v')
            throw new RuntimeException("Start tile is not a conveyor");
       
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid.get(i).charAt(j) == 'S') {
                    
                    if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
                        throw new RuntimeException("Splitter adjacent to boundary");
                    
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            if (grid.get(ni).charAt(nj) == 'S')
                                throw new RuntimeException("Splitter adjacent to another splitter");
                        }
                    }
                }
            }
        }
    }
}