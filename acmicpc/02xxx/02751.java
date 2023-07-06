import java.util.*;

class BJ02751 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int T = S.nextInt(), A[] = new int[T], i = 0;
		for(; i < T;)
			A[i++]=S.nextInt();
		Arrays.sort(A);
		for(i = 0; i < T;)
			System.out.println(A[i++]);
	}
}