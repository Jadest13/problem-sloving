import java.util.*;

class BJ09012 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(); T > 0; T--) {
			String s = S.next();
			int a = 0;
			for(int i = 0; i < s.length(); i++) {
				a+=s.charAt(i)=='('?1:-1;
				if(a<0)break;
			}
			System.out.println(a==0?"YES":"NO");
		}
	}
}