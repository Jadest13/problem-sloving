import java.util.*;

class BJ10430 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		
		int A = S.nextInt();
		int B = S.nextInt();
		int C = S.nextInt();
		
		System.out.print((A+B)%C+"\n"+(A+B)%C+"\n"+(A*B)%C+"\n"+(A*B)%C);
	}
}
