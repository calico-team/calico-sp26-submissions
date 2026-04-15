
import java.util.Scanner;


class Main {
    public static void main(String[] args){
        Scanner Stanley = new Scanner(System.in);
        int tests=Stanley.nextInt();
        for(int i = 0; i < tests; i++) {
            int l=Stanley.nextInt(), w=Stanley.nextInt(), e=Stanley.nextInt(), r=Stanley.nextInt();
            int perimeter = 2*l + 2*w;
            int ePerLap = perimeter*r;


            int laps = e / ePerLap; 
            System.out.println(laps);
            





        }
    }
}