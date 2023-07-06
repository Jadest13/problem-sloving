import java.util.*;

class BJ02749 {
	public static void main(String[]Z) {
		
		int x = 0, y = 1, s = 0, t = 1500000, T = 1000000;
		long N = new Scanner(System.in).nextLong(), i = N%t;
		for(; i-- > 1;) {
			s = y%T;
			y = (y+x)%T;
			x = s%T;
		}
		System.out.print(N==1?1:y);
	}
}