import java.util.*;

class BJ01966 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(); T > 0; T--) {
			int N = S.nextInt(), M = S.nextInt(),
				i = 0, j, k, s, r, R = 0,
				A[] = new int[N], C[] = new int[N];
			for(; i < N; i++) {
				A[i] = S.nextInt();
				C[i] = i;
			}
			for(i = 0; i < N;) {
				for(j = i; j < N; j++) {
					if(A[i] < A[j]) {
						s = A[i];
						r = C[i];
						for(k= i+1; k < N; k++) {
							A[k-1] = A[k];
							C[k-1] = C[k];
						}
						A[k-1] = s;
						C[k-1] = r;
						break;
					}
				}
				if(j == N)
					i++;
			}
			for(i = 0; i < N; i++)
				if(C[i] == M) R = i+1;
			System.out.println(R);
		}
	}
}