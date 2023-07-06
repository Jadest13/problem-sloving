import java.util.*;

class BJ01158 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt(), M = S.nextInt(), i = 0, j;
		Queue<Integer> Q = new LinkedList<Integer>();
		String s = "<";
		for(; i < N;)
			Q.add(++i);
		for(i = 0; i < N; i++) {
			for(j = 0; j < M;) {
				if(++j == M)
					s+=Q.poll()+", ";
				else
					Q.add(Q.poll());
			}
		}
		System.out.print(s.substring(0, s.length()-2)+">");
	}
}