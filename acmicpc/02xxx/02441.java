import java.util.Scanner;

class BJ02441 {
	public static void main(String[]V) {
		for(int a = new Scanner(System.in).nextInt(), i = 0; i < a; i++, System.out.println())
			for(int j = 0; j < a; j++)
				System.out.print(j>=i?"*":" ");
	}
}