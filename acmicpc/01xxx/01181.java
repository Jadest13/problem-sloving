import java.util.*;

class BJ01181 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		int T = S.nextInt(), i = 0, j;
		HashSet<String> A = new HashSet<String>();
		for(; i < T; i++) {
			A.add(S.next());
		}
		String[]B = new String[A.size()];
		A.toArray(B);
		Arrays.sort(B, new Comparator<String>() {
			public int compare(String a, String b) {
				return Integer.compare(a.length(), b.length());
			}
		});
		for(i = 0; i < B.length;) {
			for(j = i+1; j < B.length; j++)
				if(B[i].length()!=B[j].length())break;
			Arrays.sort(B, i, j);
			i = j;
		}
		for(i = 0; i < B.length;)
			System.out.println(B[i++]);
	}
}