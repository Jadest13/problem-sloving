import java.util.*;

class BJ01011 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(), i = 0; i < T; i++) {
			int a = Math.abs(S.nextInt() - S.nextInt()), R = (int)(Math.sqrt(a));
			System.out.println(a>R*R+R?R*2+1:a>R*R?R*2:R*2-1);
		}
	}
}