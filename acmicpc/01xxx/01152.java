import java.util.*;

class BJ01152 {
	public static void main(String[]V) {
		String[]T = new Scanner(System.in).nextLine().trim().split(" +");
		System.out.print(T[0].isEmpty()?0:T.length);
	}
}