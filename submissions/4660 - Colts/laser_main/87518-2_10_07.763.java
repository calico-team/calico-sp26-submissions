

import java.util.*;

public class Main {

public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
int t = sc.nextInt();

while (t > 0) {

int k =sc.nextInt();
int n= sc.nextInt();
int m=sc.nextInt();
int p =sc.nextInt();
int q= sc.nextInt();

int[] x = new int[k];
int[] y = new int[k];

for (int i =0; i < k; i++) {
x[i]=sc.nextInt();
y[i]=sc.nextInt();
}

int lazarbeam_x= x[0];
int lazarbeam_y =y[0];

boolean found = false;

while (!found) {

lazarbeam_x=(lazarbeam_x + q) % n;
lazarbeam_y=(lazarbeam_y + p) % m;

for (int i = 0; i < k; i++) {
if (x[i] == lazarbeam_x && y[i] == lazarbeam_y) {
System.out.println(i);
found = true;
break;
}
    }

   }

t--;
 }
}
}