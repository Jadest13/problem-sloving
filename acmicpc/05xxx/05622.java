import java.util.*;

class BJ05622 {
	public static void main(String[]V) {
		String S = new Scanner(System.in).next();
		int R = 0, T[] = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7};
		for(int i = 0; i < S.length(); i++) {
			R+=T[S.charAt(i)-65]+3;
		}
		System.out.print(R);
	}
}