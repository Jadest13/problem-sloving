import java.util.*;

class BJ02839 {
	public static void main(String[]V) {
		Scanner S=new Scanner(System.in);
		
		int N = S.nextInt(), T = 0, F = N/5;;
		
		while(F>=0) {
			if((N-5*F)%3==0) {
				T=(N-5*F)/3;
				break;
			}
			F--;
		}
		System.out.print(T+F);
	}
}