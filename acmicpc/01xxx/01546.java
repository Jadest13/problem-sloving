import java.util.*;

class BJ01546 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		
		int R = 0, H = 0, a = S.nextInt();
		for(int i = 0; i < a; i++) {
			int b = S.nextInt();
			R += b;
			if(b>H)H = b;
		}
		System.out.print(R*100.0/(H*a));
	}
}