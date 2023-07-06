import java.util.*;

class BJ02108 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int T = S.nextInt(), A[] = new int[T], Total = 0, M = 0, C[] = {4001, 4001}, I[] = new int[8001];
		
		for(int i = 0; i < T; i++) {
			A[i] = S.nextInt();
			Total+=A[i];
			I[A[i]+4000]++;
			if(I[A[i]+4000]>M) {
				M=I[A[i]+4000];
				C[1]=4001;
				C[0]=A[i];
			} else if(I[A[i]+4000] == M) {
				if(A[i] < C[0]) {
					C[1] = C[0];
					C[0] = A[i];
				} else if(A[i] > C[0] && A[i] < C[1])
					C[1] = A[i];
			}
		}
		Arrays.sort(A);
		System.out.printf("%d\n%d\n%d\n%d", Math.round(Total*1.0/T), A[T/2], C[1]==4001?C[0]:C[1], Math.abs(A[T-1]-A[0]));
	}
}