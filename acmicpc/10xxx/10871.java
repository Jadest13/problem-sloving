import java.util.*;

class BJ10871 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int a = S.nextInt(), b = S.nextInt();
		for(int i = 0; i < a; i++) {
			int c = S.nextInt();
			System.out.print(c<b?c+" ":"");
		}
	}
}