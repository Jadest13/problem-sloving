import java.io.*;
import java.util.*;

class BJ15552 {
	/*public static void main(String[]Z) throws Exception {
		BufferedReader R = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter W = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int T = Integer.parseInt(R.readLine()); T-->0;) {
			StringTokenizer S = new StringTokenizer(R.readLine());
			int A = Integer.parseInt(S.nextToken()), B = Integer.parseInt(S.nextToken());
			W.write(A+B+"\n");
			W.flush();
		}
	}*/
	
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		for(int T = S.nextInt(); T-->0;) {
			System.out.println(S.nextInt()+S.nextInt());
		}
	}
}