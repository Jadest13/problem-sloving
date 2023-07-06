import java.util.*;

class BJ11051 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt(), K = S.nextInt(), A[][] = new int[1001][1001];
		A[1][1] = 1;
		A[1][0] = 1;
		for(int i = 2; i <= N; i++) {
			A[i][0] = 1;
			for(int j = 1; j <= K; j++) {
				A[i][j] = (A[i-1][j-1] + A[i-1][j])%10007;
				if(A[i][j] == 0)
					break;
			}
		}
		/*for(int i = 1; i <= N; i++) {
			for(int j = 0; j <= K; j++)  {
				if(A[i][j] == 0)
					break;
				System.out.print(A[i][j]+" ");
			}
			System.out.println();
		}*/
		System.out.println(A[N][K]);
	}
}