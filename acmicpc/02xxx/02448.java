import java.util.*;

class BJ02448 {
	
/*	public static char[][] T;
	public static void main(String[]V) {
		int a = new Scanner(System.in).nextInt();
		T = new char[a][a*2-1];
		F(a, 0, a);
		StringBuffer B = new StringBuffer();
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < a*2-1; j++) {
				if(T[i][j] == '\0')
					T[i][j] = ' ';
				B.append(T[i][j]);
			}
			B.append('\n');
		}
		System.out.print(B.toString());
	}
	
	public static void F(int x, int y, int N) {
		if(N == 3) {
			T[y][x-1] = '*';
			T[y+1][x-2] = '*';
			T[y+1][x] = '*';
			for(int i = 0; i < 5;)
				T[y+2][x-3+i++] = '*';
		} else {
			int H = N/2;
			F(x, y, H);
			F(x+H, y+H, H);
			F(x-H, y+H, H);
		}
	}*/
	public static void main(String[]V) {
		int a = new Scanner(System.in).nextInt();
		String[]T = new String[a];
		T[0] = "  *  ";
		T[1] = " * * ";
		T[2] = "*****";
		for(int i = 1; i < a/3; i*=2) {
			for(int j = 0; j < i*3; j++) {
				T[j+i*3] = T[j] + " " + T[j];
				for(int k = 0; k < i; k++)
					T[j] = "   " + T[j] + "   ";
			}
		}
		for(int i = 0; i < a; i++) {
			System.out.println(T[i]);
		}
	}
}