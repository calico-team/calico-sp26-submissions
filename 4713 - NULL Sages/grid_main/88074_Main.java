import java.util.Scanner;
import java.util.ArrayList;


public class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int time = scanner.nextInt();
        int num = scanner.nextInt();
        int [][] table = new int [2][num];

        //top 值
        int top= 0;
        //bottom值
        int bottom =0;
        //between值
        int between  =0;
        //比较的值
        int minisum =(int)Math.pow(10,9);
        int sum = 0;
        //出现次数
        int occurTime=0;
        int maxOccur = 0;
        int occurVal = 0;

        ArrayList<Integer> firstLine = new ArrayList<Integer>();
        //大循环
        while(time-->0){
            //把input加入2d的第一行
            for(int i = 0;i < num ; i++){
                table[0][i]= scanner.nextInt();
            }
            //求top
            for(int a =0; a < table[0].length-1; a++){
                top+= Math.abs(table[0][a]-table[0][a+1]);
            }
            occurTime=0;
            //找众数
            for(int ab=0;ab < table[0].length; ab++ ){
                for(int ba= ab+1;ab < table[0].length;ba++){
                    if(table[0][ab]==table[0][ba]) {
                        occurTime++;
                    }
                    if(occurTime>maxOccur){
                        maxOccur = occurTime;
                        occurVal = table[0][ab];
                    }


                }
            }

            //try 众数
            for(int m = 0;m <table[0].length;m++){
                between+=Math.abs(table[m][0]-occurVal);
            }
            //众数和
            int mostSum = between+top;


            //try same
            int sameSum = 2*top;

            if(mostSum < sameSum){
                for(int b=0 ;b<table[0].length;b++){
                    System.out.print(occurVal+" ");
                }
            }else if(mostSum>sameSum){
                for(int v=0;v<table[0].length;v++){
                    System.out.print(table[0][v]+" ");
                }
            }






        }
    }
}