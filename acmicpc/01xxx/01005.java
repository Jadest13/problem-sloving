import java.util.*;

class BJ01005 {
	static int N, K, W, D[], A[], P[][];
	
	public static void main(String[]Z) {
	    Scanner S = new Scanner(System.in);
	    
	    for(int T = S.nextInt(); T-- > 0;) {
	    	N = S.nextInt();
	    	K = S.nextInt();
	    	
	    	D = new int[N+1];
	    	A = new int[N+1];
	    	P = new int[N+1][N+1];
	    	
	    	for(int i = 0; i++ < N;)
	    		D[i] = S.nextInt();
	    	
	    	for(int i = 0; i < K; i++) {
	    		P[S.nextInt()][S.nextInt()] = 1;
	    	}
	    	
	    	W = S.nextInt();
	    	System.out.println(F(W));
	    }
	}
	
	static int F(int a) {
		if(A[a]>0) return A[a];
		int r = 0;
		for(int i = 0; i++ < N;)
			if(P[i][a]==1)
				r = Math.max(r, F(i));
		return A[a] = r + D[a];
	}
}