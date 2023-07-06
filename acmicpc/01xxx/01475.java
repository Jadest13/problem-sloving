import java.util.*;

class BJ01475 {
	public static void main(String[]V) {
		String S = new Scanner(System.in).next().replace('9', '6');
		int R = 0, T[] = new int[9];
		for(int i = 0; i < S.length(); i++)
			T[S.charAt(i)-48]++;
		T[6]=(T[6]+1)/2;
		for(int i = 0; i < 9; i++)
			R=T[i]>T[R]?i:R;
		System.out.println(T[R]);
	}
}