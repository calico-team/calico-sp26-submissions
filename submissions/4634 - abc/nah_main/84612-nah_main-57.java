
import java.util.Scanner;

public class Main{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N=scanner.nextInt();
    int P=scanner.nextInt();
    int R=scanner.nextInt();
    int K=scanner.nextInt();
    int re=0;
    scanner.nextLine();
    int[] curse = new int[N];
    for(int i=0;i<curse.length;i++){
      if(scanner.hasNext()){
        curse[i]=scanner.nextInt();
      }
    }
    for(int i=0;i<curse.length;i++){
      if(re==K){
        P+=R;
        re=0;
      }
      if(P-curse[i]>=0){
        re++;
        P-=curse[i];
      }
      else{
        P-=curse[i];
        System.out.println("nah i’d lose");
        break;
      }
    }
    if(P>=0)System.out.println("nah i’d win");
  }
}
