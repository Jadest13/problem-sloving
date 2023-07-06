import java.util.*;

class BJ01932 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt(), i, j, A[][] = new int[N+1][N+1];

		for(i = 0; i++ < N;)
			for(j = 0; j++ < i;)
				A[i][j] = M(A[i-1][j-1], A[i-1][j]) + S.nextInt();
		
		Arrays.sort(A[N]);
		System.out.print(A[N][N]);
	}
	static int M(int a, int b) {return a>=b?a:b;}
}