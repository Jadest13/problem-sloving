import java.util.*;

class BJ11401 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		long N = S.nextLong(), K = S.nextLong(), B = K>N/2?N-K:K, R = 1, U = 1, D = 1, P = 1000000007, T = P-2;

		for(int i = 0; i < B;) {
			U = (U*(N-i))%P;
			D = (D*++i)%P;
		}
		
		while(T>0) {
			if (T%2 != 0) R = (R*D)%P;
			D = (D*D)%P;
	        T/=2;
		}
		R = (R%P)*U;
		System.out.println(R%P);
	}
}