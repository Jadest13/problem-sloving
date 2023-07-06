import java.math.*;
import java.util.*;

class BJ02407 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int n = S.nextInt(), m = S.nextInt(), i = 0;
		BigInteger R = BigInteger.ONE;
		for(; i < m;)
			R = R.multiply(BigInteger.valueOf(n-i)).divide(BigInteger.valueOf(++i));
		System.out.println(R);
	}
}