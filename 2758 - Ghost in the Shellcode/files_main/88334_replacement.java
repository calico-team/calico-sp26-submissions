
import java.util.Scanner;

public class replacement {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        String firstLine = scanner.nextLine();
        String secondLine = scanner.nextLine();
        String sentence = "";//final output
        int secondLineLocation = 0;//indedx 
        if (firstLine.equals("")||secondLine.equals("")){
            return;
        }
        for (int i=0;i<firstLine.length();i++){
            String letter = firstLine.substring(i,i+1);
            
            if (secondLineLocation<secondLine.length()&&letter.equals(secondLine.substring(secondLineLocation,secondLineLocation+1))){//check if first line contains letter
                sentence += letter;
                secondLineLocation++;
            }
            else{
                sentence +="#";
            }
        }
        System.out.println(sentence);
        scanner.close();
    }
}
