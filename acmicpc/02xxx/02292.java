import java.util.*;

class BJ02292 {
	public static void main(String[]V) {
		int a = new Scanner(System.in).nextInt(), i = 1, j = 1, R = 1;
		while(a>j) {
			j+=i++*6;
			R++;
		}
		System.out.print(R);
	}
}