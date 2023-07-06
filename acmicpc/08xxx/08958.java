import java.util.*;

class BJ08958 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(), i = 0; i < T; i++) {
			String B = S.next();
			int R = 0;
			for(int j = 0, a = 0; j < B.length(); j++) {
				if(B.charAt(j)=='O')
					R += ++a;
				else
					a = 0;
			}
			System.out.println(R);
		}
	}
}