import java.util.*;

class BJ02920 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int[]T = new int[8];
		String R = "";
		for(int i = 0; i < 8; i++) {
			T[i] = S.nextInt();
			R+=i==0?"":T[i]>T[i-1]?"+":"-";
		}
		System.out.print(R.equals("+++++++")?"ascending":R.equals("-------")?"descending":"mixed");
	}
}