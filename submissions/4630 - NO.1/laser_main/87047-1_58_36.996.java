
import java.util.*;
import java.io.*;

public class Solution {
    
    public static int solve(int K, int N, int M, int P, int Q, int[][] asteroids) {
        int x0 = asteroids[0][0];
        int y0 = asteroids[0][1];
        
       
        long invQ = modInverse(Q, N);
        long invP = modInverse(P, M);
        
        long minT = Long.MAX_VALUE;
        int result = -1;
        
       
        for (int i = 1; i < K; i++) {
            int x = asteroids[i][0];
            int y = asteroids[i][1];
            
            
            long tModN = ((x - x0 + N) % N) * invQ % N;
           
            long tModM = ((y - y0 + M) % M) * invP % M;
            
           
            long t = findCommonT(tModN, tModM, N, M);
            
            if (t > 0 && t < minT) {
                minT = t;
                result = i;
            }
        }
        
        return result;
    }
    
    private static long findCommonT(long a, long b, long n, long m) {
        long gcd = gcd(n, m);
        
       
        if ((a - b) % gcd != 0) {
            return Long.MAX_VALUE;
        }
        
  
        long lcm = n / gcd * m;
        
      
        long diff = ((b - a) % m + m) % m;
        long nModM = n % m;
        
        
        long k = (diff * modInverse(nModM / gcd, m / gcd)) % (m / gcd);
        
        
        long t = a + n * k;
        if (t == 0) {
            t += lcm; // Skip t=0 (the starting position)
        }
        
        return t;
    }
    
    private static long modInverse(long a, long m) {
        long inv = powMod(a, m-2, m);
        return inv;
    }
    
    private static long powMod(long a, long b, long m) {
        long result = 1;
        a %= m;
        while (b > 0) {
            if ((b & 1) == 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }
    
    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        for (int testCase = 1; testCase <= T; testCase++) {
            String[] parts = br.readLine().split(" ");
            int K = Integer.parseInt(parts[0]);
            int N = Integer.parseInt(parts[1]);
            int M = Integer.parseInt(parts[2]);
            int P = Integer.parseInt(parts[3]);
            int Q = Integer.parseInt(parts[4]);
            
            int[][] asteroids = new int[K][2];
            for (int i = 0; i < K; i++) {
                parts = br.readLine().split(" ");
                asteroids[i][0] = Integer.parseInt(parts[0]);
                asteroids[i][1] = Integer.parseInt(parts[1]);
            }
            
            int result = solve(K, N, M, P, Q, asteroids);
            System.out.println(result);
        }
    }
}