import java.util.*;

class BJ01010 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(); T > 0; T--) {
			int a = S.nextInt(), b = S.nextInt(), i = 0;
			double R = 1;
			for(; i < a;) {
				R=R*b--/++i;
				System.out.println(R);
			}
			System.out.println((int)(R));
		}
	}
}