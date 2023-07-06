import java.util.*;

class BJ01193 {
	public static void main(String[]V) {
		int T = new Scanner(System.in).nextInt(), i = 0, j = 0;
		
		while(T>j)
			j+=++i;
		System.out.print(i%2!=0?1+j-T+"/"+(T-j+i):T-j+i+"/"+(1+j-T));
	}
}