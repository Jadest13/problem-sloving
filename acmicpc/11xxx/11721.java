import java.util.*;

class BJ11721 {
	public static void main(String[]V) {
		String S = new Scanner(System.in).next();
		int i;
		for(i = 0; i < S.length()/10; i++)
			System.out.println(S.substring(i*10, i*10+10));
		System.out.print(S.substring(i*10));
	}
}