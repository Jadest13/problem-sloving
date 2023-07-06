import java.util.*;

class BJ01929 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int M = S.nextInt(), N = S.nextInt(), A[] = new int[N+1];
		Arrays.fill(A, 0);
		A[1]=1;
		for(int i = 2; i <= N; i++)
			for(int j = 2; i*j <= N; j++)
				A[i*j] = 1;
		for(int i = M; i <= N; i++)
			if(A[i]!=1) System.out.println(i);
	}
}