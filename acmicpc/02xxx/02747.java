import java.util.*;

class BJ02747 {
	public static void main(String[]Z) {
		int T = new Scanner(System.in).nextInt(), x = 0, y = 1, s = 0, i = 2;
		for(; i++ <= T;) {
			s = y;
			y = y + x;
			x = s;
		}
		System.out.print(T==1?1:y);
	}
}