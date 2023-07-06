import java.util.*;

class BJ01149 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt(), R, G, B, a = 0, b = 0, c = 0, i = 0;
		for(; i++ < N;) {
			R = a; G = b; B = c;
			a = m(G,B) + S.nextInt();
			b = m(R,B) + S.nextInt();
			c = m(R,G) + S.nextInt();
		}
		System.out.print(m(m(a,b),c));
	}
	static int m(int a, int b) {return a>b?b:a;}
}