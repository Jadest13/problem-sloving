import java.util.*;

class BJ08393 {
	public static void main(String[]V) {
		int R = 0;
		for(int a = new Scanner(System.in).nextInt(), i = 0; i < a; i++, R+=i);
		System.out.print(R);
	}
}