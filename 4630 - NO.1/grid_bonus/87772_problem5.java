import java.util.*;
import java.io.*;

public class problem5 {
    
    public static int[] solve(int N, int[] A) {
        int[] B = new int[N];
        
        if (N == 1) {
            B[0] = A[0];
            return B;
        }
        
       
        for (int i = 0; i < N; i++) {
            List<Integer> candidates = new ArrayList<>();
            candidates.add(A[i]);
            if (i > 0) candidates.add(A[i-1]);
            if (i < N-1) candidates.add(A[i+1]);
            
            Collections.sort(candidates);
       
            B[i] = candidates.get(candidates.size() / 2);
        }
        
       
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                
                if (Math.abs(B[0] - A[0]) + Math.abs(B[0] - B[1]) > 
                    Math.abs(A[1] - A[0]) + Math.abs(A[1] - B[1])) {
                    B[0] = A[1];
                }
            } else if (i == N-1) {
                if (Math.abs(B[N-1] - A[N-1]) + Math.abs(B[N-1] - B[N-2]) > 
                    Math.abs(A[N-2] - A[N-1]) + Math.abs(A[N-2] - B[N-2])) {
                    B[N-1] = A[N-2];
                }
            } else {
                
                int[] candidates = {A[i-1], A[i], A[i+1]};
                int best = B[i];
                long bestCost = Math.abs(B[i] - A[i]) + 
                               Math.abs(B[i] - B[i-1]) + 
                               Math.abs(B[i] - B[i+1]);
                
                for (int cand : candidates) {
                    long cost = Math.abs(cand - A[i]) + 
                               Math.abs(cand - B[i-1]) + 
                               Math.abs(cand - B[i+1]);
                    if (cost < bestCost) {
                        bestCost = cost;
                        best = cand;
                    }
                }
                B[i] = best;
            }
        }
        
        return B;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        for (int testCase = 1; testCase <= T; testCase++) {
            int N = Integer.parseInt(br.readLine());
            int[] A = new int[N];
            String[] parts = br.readLine().split(" ");
            for (int i = 0; i < N; i++) {
                A[i] = Integer.parseInt(parts[i]);
            }
            
            int[] B = solve(N, A);
            
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                if (i > 0) sb.append(" ");
                sb.append(B[i]);
            }
            System.out.println(sb.toString());
        }
    }
}
