import java.util.*;

class BJ06064 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(), i = 0; i < T; i++) {
			int m = S.nextInt(), n = S.nextInt(),
				x = S.nextInt(), y = S.nextInt(),
				R = -1, M = m*n;
			
			for(int j = x; j <= m*n; j+=m)
				if((j-1)%n+1==y) {
					R = j;
					break;
				}
			System.out.println(R);
		}
	}
}