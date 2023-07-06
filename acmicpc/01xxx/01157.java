import java.util.*;

class BJ01157 {
	public static void main(String[]V) {
		String S = new Scanner(System.in).next().toUpperCase();
		char R = 0;
		int[]T = new int[26];
		int M = 0;
		for(int i = 0; i < S.length(); i++) {
			int a = ++T[S.charAt(i)-65];
			if(a==M)
				R = 63;
			else if(a>M) {
				M = a;
				R = S.charAt(i);
			}
		}
		System.out.print(R);
	}
}