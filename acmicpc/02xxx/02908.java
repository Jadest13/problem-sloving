import java.util.*;

class BJ02908 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int A = S.nextInt(), B = S.nextInt(),
			C = A/100 + A/10%10*10 + A%10*100,
			D = B/100 + B/10%10*10 + B%10*100;
		System.out.print(C>D?C:D);
	}
}