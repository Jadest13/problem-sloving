import java.util.*;

class BJ10817 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int[] a = {S.nextInt(), S.nextInt(), S.nextInt()};
		Arrays.sort(a);
		System.out.print(a[1]);
	}
}