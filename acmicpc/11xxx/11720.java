import java.util.*;

class BJ11720 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int R = 0, A = S.nextInt();
		String B = S.next();
		for(int i = 0; i < A; i++)
			R += Integer.valueOf(B.substring(i, i+1));
		System.out.print(R);
	}
}