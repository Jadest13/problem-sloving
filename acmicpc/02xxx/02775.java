import java.util.*;

class BJ02775 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(), i = 0; i < T; i++) {
			int k = S.nextInt(), n = S.nextInt();
			int A[][] = new int[k+1][n+1];
			for(int j = 0; j <= n; j++)
				A[0][j]=j;
			for(int j = 1; j <= k; j++) {
				for(int m = 1; m <= n; m++) {
					A[j][m] = A[j-1][m]+A[j][m-1];
				}
			}
			System.out.print(A[k][n]);
		}
	}
}