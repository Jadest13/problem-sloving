import java.util.*;

class BJ01463 {
	public static void main(String[]Z) {
		int N = new Scanner(System.in).nextInt(), D[] = new int[N+1], i = 1;
		D[1] = 0;
		for(; i++ < N;) {
			D[i] = D[i-1]+1;
			D[i] = i%2==0?Math.min(D[i],D[i/2]+1):D[i];
			D[i] = i%3==0?Math.min(D[i],D[i/3]+1):D[i];
		}
		System.out.print(D[N]);
	}
}