import java.util.Scanner;

class BJ01978 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int T = S.nextInt(), R = T, i = 0, j;
		for(; i < T; i++) {
			int a = S.nextInt();
			if(a==1)
				R--;
			else
				for(j = 2; j < a; j++)
					if(a%j==0) {
						R--;
						break;
					}
		}
		System.out.print(R);
	}
}