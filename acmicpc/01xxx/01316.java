import java.util.*;

class BJ01316 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int R = 0;
		for(int N = S.nextInt(), i = 0; i < N; i++) {
			String T = S.next();
			int[] I = new int[26];
			int P = 0;
			I[T.charAt(0)-97]++;
			for(int j = 1; j < T.length(); j++) {
				if(T.charAt(j) != T.charAt(j-1))
					++I[T.charAt(j)-97];
				if(I[T.charAt(j)-97]>1)
					P=1;
			}
			if(P == 0)
				R++;
		}
		System.out.print(R);
	}
}