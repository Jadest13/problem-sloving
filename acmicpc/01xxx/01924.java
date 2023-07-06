import java.util.*;

class BJ01924 {
	public static void main(String[]V) {
		int[]M = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
		Scanner S = new Scanner(System.in);
		int A = (M[S.nextInt()-1] + S.nextInt())%7;
		System.out.print(A==1?"MON":A==2?"TUE":A==3?"WED":A==4?"THU":A==5?"FRI":A==6?"SAT":"SUN");
	}
}