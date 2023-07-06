import java.util.*;

class BJ10866 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		Deque<Integer> D = new ArrayDeque<Integer>();
		for(int T = S.nextInt(); T-- > 0;) {
			String s = S.next();
			if(s.contains("h_f"))
				D.push(S.nextInt());
			if(s.contains("h_b"))
				D.add(S.nextInt());
			if(s.contains("p_f"))
				System.out.println(D.isEmpty()?-1:D.pop());
			if(s.contains("p_b"))
				System.out.println(D.isEmpty()?-1:D.pollLast());
			if(s.contains("z"))
				System.out.println(D.size());
			if(s.contains("m"))
				System.out.println(D.isEmpty()?1:0);
			if(s.equals("front"))
				System.out.println(D.isEmpty()?-1:D.peek());
			if(s.equals("back"))
				System.out.println(D.isEmpty()?-1:D.getLast());
		}
	}
}