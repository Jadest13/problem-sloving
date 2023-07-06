import java.util.*;

class BJ06591 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		while(true) {
			int N = S.nextInt(), M = S.nextInt(), i = 0, T = M>N/2?N-M:M;
			if(N==0) break;
			double R = 1;
			for(; i < T;)
				R=R*(N-i)/++i;
			System.out.println((int)R);
		}
	}
}