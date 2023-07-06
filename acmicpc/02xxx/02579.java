import java.util.*;

class BJ02579 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt()+3, A[] = new int[N], D[] = new int[N], i = 3;
		for(; i < N; i++) {
			A[i] = S.nextInt();
			D[i] = M(D[i-2]+A[i], D[i-3]+A[i-1]+A[i]);
		}
		System.out.println(D[N-1]);
	}
	
	static int M(int a, int b) {return a>b?a:b;}
}