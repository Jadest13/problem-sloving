import java.util.*;

class BJ01874 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int T = S.nextInt(), A[] = new int[T], j = 0, i = 0;
		Stack<Integer> B = new Stack<Integer>();
		StringBuffer s = new StringBuffer();
		for(; i < T;) {
			A[i++] = S.nextInt();
		}
		for(i = 1; i <= T;) {
			B.push(i++);
			s.append("+\n");
			while(!B.empty()&&B.peek()==A[j]) {
				s.append("-\n");
				B.pop();
				j++;
			}
		}
		System.out.print(B.empty()?s:"NO");
	}
}