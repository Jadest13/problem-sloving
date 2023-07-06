import java.util.*;

class BJ10872 {
	public static void main(String[]Z) {
		int R = 1, i = new Scanner(System.in).nextInt();
		for(; i > 0;)
			R*=i--;
		System.out.print(R);
	}
}