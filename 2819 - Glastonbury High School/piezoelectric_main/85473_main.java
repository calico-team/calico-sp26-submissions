// package Problem1;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class main {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		ArrayList<Integer> nums = new ArrayList<>();
		int tests = scanner.nextInt();//to get tests
		while(scanner.hasNext()) {

			nums.add(scanner.nextInt());
			//System.out.println(nums);

		}
		//System.out.println(tests);
		for(int i = 0; i<nums.size(); i=i+4) {
		System.out.println(numOfLaps(nums.get(i), nums.get(i+1), nums.get(i+2), nums.get(i+3)));
		}
	}

	public static int numOfLaps(int L, int W, int E, int R) {
		int output = 0;

		int lap = R*(L*2 + W*2);

		while(E>0) {
			output++;
			E=E-lap;
		}

		return output ;
	}

}
