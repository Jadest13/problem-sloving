import java.util.*;

class BJ02581 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int M = S.nextInt(), N = S.nextInt(), m = 0, R = 0;;
		ArrayList<Integer> A = new ArrayList<Integer>();
		for(int i = 2; i <= N; i++) {
			int a = 0;
			for(int j = 0; j < A.size(); j++) {
				if(i%A.get(j)==0)
					a++;
			}
			if(a==0){
				A.add(i);
				if(i>=M) {
					if(m==0)m=i;
					R+=i;
				}
			}
		}
		System.out.print(R==0?-1:R+"\n"+m);
	}
}