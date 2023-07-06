import java.util.*;

class BJ01427 {
	public static void main(String[]V) {
		int S = new Scanner(System.in).nextInt(), T[] = new int[(""+S).length()], i = 0;
		for(; i < T.length;) {
			T[i++] = S%10;
			S/=10;
		}
		Arrays.sort(T);
		for(i = T.length-1; i >= 0; i--)
			System.out.print(T[i]);
	}
}