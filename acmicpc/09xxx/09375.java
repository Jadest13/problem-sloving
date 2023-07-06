import java.util.*;

class BJ09375 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(); T-- > 0;) {
			ArrayList<String> A = new ArrayList<String>();
			ArrayList<Integer> B = new ArrayList<Integer>();
			int R = 1;
			for(int N = S.nextInt(); N-- > 0;) {
				String a = S.next(), b = S.next();
				if(!A.contains(b)) {
					A.add(b);
					B.add(2);
				}
				else
					for(int i = 0; i < A.size(); i++)
						if(b.equals(A.get(i)))
							B.set(i, B.get(i)+1);
			}
			for(int i = 0; i < A.size();)
				R *= B.get(i++);
			System.out.println(R-1);
		}
	}
}