import java.util.*;

class BJ10039 {
	public static void main(String[]V) {
		int R = 0, i = 0;
		Scanner S = new Scanner(System.in);
		for(; i < 5; i++) {
			int a = S.nextInt();
			R += a<40?40:a;
		}
		System.out.print(R/5);
	}
}
