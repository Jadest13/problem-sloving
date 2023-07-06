import java.util.*;

class BJ11866 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt(), M = S.nextInt(), i = 0, j;
		Queue<Integer> Q = new LinkedList<Integer>();
		Stack T = new Stack();
		for(; i < N;)
			Q.add(++i);
		for(i = 0; i < N; i++) {
			for(j = 0; j < M;) {
				if(++j == M)
					T.push(Q.poll());
				else
					Q.add(Q.poll());
			}
		}
		System.out.print("<"+T.toString().substring(1).replace("]", ">"));
	}
}