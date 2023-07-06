import java.util.*;

class BJ01110 {
	public static void main(String[]V) {
		int a = new Scanner(System.in).nextInt(), b = 0, c = a, C = 0;
		while(a != c || C == 0) {
			c = c%10*10 + (c/10 + c%10) %10;
			C++;
		}
		System.out.print(C);
	}
}