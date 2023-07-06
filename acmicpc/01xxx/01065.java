import java.util.*;

class BJ01065 {
	static int R;
	public static void main(String[]V) {
		for(int a = new Scanner(System.in).nextInt(), i = 1; i <= a; i++) {
			F(i);
		}
		System.out.print(R);
	}
	public static void F(int a) {
		if(a > 0 && a < 100)
			R++;
		else
			if(a/100 - a/10%10 == a/10%10 - a%10)
				R++;
	}
	/*public static void main(String[]V) {
		int R = 0;
		for(int a = new Scanner(System.in).nextInt(), i = 1; i <= a; i++) {
			if(i > 0 && i < 100)
				R++;
			else
				if(i/100 - i/10%10 == i/10%10 - i%10)
					R++;
		}
		System.out.print(R);
	}*/
}