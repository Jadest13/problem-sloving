import java.util.*;

class BJ11050 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt(), K = S.nextInt(), a = 1, b = 1, i = 0;
		for(; i < K;) {
			a *= N-i++;
			b *= i;
		}
		System.out.print(a/b);
	}
}