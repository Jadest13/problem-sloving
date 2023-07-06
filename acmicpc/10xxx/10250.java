import java.util.*;

class BJ10250 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(), i = 0; i < T; i++) {
			int H = S.nextInt(), W = S.nextInt(), N = S.nextInt(), A = N%H, B = N/H;
			
			System.out.printf("%d%02d\n",A==0?H:A,A==0?B:B+1);
		}
	}
}