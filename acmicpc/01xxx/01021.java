import java.util.*;

class BJ01021 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		Deque<Integer> D = new ArrayDeque<Integer>();
		int N = S.nextInt(), M = S.nextInt(), i = 0, R = 0, a, r, d;
		for(; i < N;)
			D.add(++i);
		for(i = 0; i < M; i++) {
			a = S.nextInt();
			r = 0;
			d = D.size();
			while(true) {
				if(a==D.peek()) {
					D.pop();
					break;
				} else {
					D.add(D.pop());
					r++;
				}
			}
			R+=r>d/2?d-r:r;
		}
		System.out.println(R);
	}
}