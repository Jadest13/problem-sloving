import java.util.*;

class BJ02748 {
	public static void main(String[]Z) {
		long T = new Scanner(System.in).nextInt(), x = 0, y = 1, s = 0, i = 2;
		for(; i++ <= T;) {
			s = y;
			y = y + x;
			x = s;
		}
		System.out.print(T==1?1:y);
	}
}