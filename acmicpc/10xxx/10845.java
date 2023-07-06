import java.util.*;

class BJ10845 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		Queue<Integer> A = new LinkedList<>();
		for(int T = S.nextInt(); T > 0; T--) {
			String s = S.next();
			if(s.equals("push"))
				A.offer(S.nextInt());
			if(s.equals("pop"))
				System.out.println(A.isEmpty()?-1:A.poll());
			if(s.equals("size"))
				System.out.println(A.size());
			if(s.equals("empty"))
				System.out.println(A.isEmpty()?1:0);
			if(s.equals("front"))
				System.out.println(A.isEmpty()?-1:A.peek());
			if(s.equals("back")) {
				Object[] a = A.toArray();
				System.out.println(A.isEmpty()?-1:a[A.size()-1]);
			}
		}
	}
}