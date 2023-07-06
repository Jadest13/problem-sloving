import java.util.*;

class BJ02504 {
	public static void main(String[]V) {
		String S = new Scanner(System.in).next();
		int x = 0, y = 0, a = 0, b = 1, R = 0, i = 0, l = S.length();
		
		for(; i < l&&l%2==0; i++) {
			char c = S.charAt(i);
			
			if(c=='(') {
				b *= 2;
				a=0;
				
				x++;
			} if (c==')') {
				if(a==0) {
					R+=b;
					a=1;
				}
				b/=2;
				
				x--;
			} if (c=='[') {
				b *= 3;
				a=0;
				
				y++;
			} if (c==']') {
				if(a==0) {
					R+=b;
					a=1;
				}
				b/=3;
				
				y--;
			}
			if(i>0) {
				if((c==')'&&S.charAt(i-1)=='[')||(c==']'&&S.charAt(i-1)=='('))
					break;
			}
			if(x<0||y<0)break;
		}
		System.out.print(i < l?0:R);
	}
}