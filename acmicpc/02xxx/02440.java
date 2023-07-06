import java.util.*;

class BJ02440 {
	public static void main(String[]V) {
		for(int a = new Scanner(System.in).nextInt(), i = a; i > 0; i--, System.out.println())
			for(int j = 0; j < i; j++, System.out.print("*"));
	}
}