import java.util.*;

class BJ10989 {
	public static void main(String[]V) throws Exception {
		Scanner S = new Scanner(System.in);
		int T = S.nextInt(), A[] = new int[T], i = 0;
		for(; i < T;)
			A[i++] = S.nextInt();
		Arrays.sort(A);
		StringBuffer B = new StringBuffer();
		for(i = 0; i < T;)
			B.append(A[i++]+"\n");
		System.out.print(B);
	}
}