import java.util.*;

class BJ04344 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		
		for(int a = S.nextInt(), i = 0; i < a; i++) {
			int b = S.nextInt();
			float R = 0;
			int[]c = new int[b];
			for(int j = 0; j < b; j++) {
				c[j] = S.nextInt();
				R += c[j];
			}
			R /= b*1.0;
			int d = 0;
			for(int j = 0; j < b; j++) {
				if(c[j] > R)
					d++;
			}
			System.out.printf("%.3f%%\n", d*100.0/b);
		}
	}
}