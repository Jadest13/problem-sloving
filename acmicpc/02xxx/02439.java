import java.util.Scanner;

class BJ02439 {
	public static void main(String[]V) {
		for(int a = new Scanner(System.in).nextInt(), i = 1; i <= a; i++, System.out.println()) {
			for(int j = a; j > 0; j--)
				System.out.print(j>i?" ":"*");
		}
	}
}
