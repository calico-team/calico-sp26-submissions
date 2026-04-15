import java.util.Scanner;


public class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int T =scanner.nextInt();

        for(int p =1;p<=T ;p++){
            int length = scanner.nextInt();
            int top =0;
            int[]table= new int[length];

            //放
            for(int i =0;i < table.length; i++) {
                table[i] = scanner.nextInt();
            }

            // 计算top
            for(int b=0;b<table.length-1;b++){
                top+=Math.abs(table[b]-table[b+1]);
            }

            int occurTime = 0;
            int occurMax = 0;
            int mostO = table[0];
            for(int m=0;m<table.length;m++){
                occurTime=0;
                for(int n=m+1;n<table.length;n++){
                    if(table[m]==table[n]){
                        occurTime++;
                    }
                }
                if(occurTime>occurMax) {
                    occurMax = occurTime;
                    mostO=table[m];
                }
            }

            //众数的情况
            int between=0;
            for(int a=0;a<table.length;a++){
                between+=Math.abs(table[a]-mostO);
            }
            int manySituation = between+top;

            //相等的情况
            int sameSituation = 2*top;

            if(manySituation<sameSituation){
                for(int y = 0;y<table.length;y++){
                    System.out.print(mostO+" ");
                }
            }else if(sameSituation<= manySituation){
                for(int o=0; o<table.length;o++){
                    System.out.print(table[o]+" ");
                }
            }

        }
    }
}