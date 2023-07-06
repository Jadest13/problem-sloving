import java.util.*;

class BJ02675 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(), i = 0; i < T; i++) {
			int A = S.nextInt();
			String B = S.next();
			for(int k = 0; k < B.length(); k++)
				for(int j = 0; j < A; j++)
					System.out.print(B.charAt(k));
			System.out.println();
		}
	}
}