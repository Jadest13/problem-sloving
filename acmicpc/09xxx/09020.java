import java.util.*;

class BJ09020 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(), i = 0; i < T; i++) {
			int a = S.nextInt(), A[] = new int[a+1], R = 0, j = 2, k;
			Arrays.fill(A, 0);
			A[1]=1;
			for(; j <= a; j++)
				for(k = 2; j*k <= a; k++)
					A[j*k] = 1;
			for(j = 1; j <= a/2; j++)
				if(A[j]!=1&&A[a-j]!=1) {
					R=j;
				}
			System.out.println(R+" "+(a-R));
		}
	}
}