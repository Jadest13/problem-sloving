import java.util.*;

class BJ05430 {
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(); T-- > 0;) {
			String s = S.next();
			Deque<String> D = new ArrayDeque<String>();
			int a = S.nextInt(), i = 0, r = 1, f = 0;
			String b = S.next(), A[] = b.substring(1, b.length()-1).split(",");
			for(; i < a;)
				D.add(A[i++]);
			for(i = 0; i < s.length();) {
				char c = s.charAt(i++);
				if(c==82) {
					r*=-1;
				} else {
					if(D.isEmpty()) {
						f++;
						break;
					}
					if(r==1)
						D.pop();
					else
						D.pollLast();
				}
			}
			if(r!=1) {
				Deque<String> d = new ArrayDeque<String>();
				for(i = D.size(); i-- > 0 ;)
					d.push(D.pop());
				D = d;
			}
			System.out.println(f!=0?"error":D.toString().replace(" ", ""));
		}
	}
}