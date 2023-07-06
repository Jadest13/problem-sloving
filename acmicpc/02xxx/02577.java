import java.util.*;

class BJ02577 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int A[] = new int[10], a = S.nextInt() * S.nextInt() * S.nextInt();
		for(; a > 0; a /= 10)
			A[a%10]++;
		for(int i = 0; i < 10; i++)
			System.out.println(A[i]);
	}
}