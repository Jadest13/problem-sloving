import java.util.*;

class BJ02750 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int T = S.nextInt(), A[] = new int[T];
		for(int i = 0; i < T; i++)
			A[i]=S.nextInt();
		Arrays.sort(A);
		for(int i = 0; i < T; i++)
			System.out.println(A[i]);
	}
}