import java.util.*;

class BJ01260 {
	
	public static void main(String[]Z) {
		Scanner S = new Scanner(System.in);
		int N = S.nextInt(), M = S.nextInt(), V = S.nextInt();
		int A[][] = new int[N+1][N+1];
		int C[] = new int[N+1];
		int i = 0;
		
		for(; i < M; i++) {
			int a = S.nextInt(), b = S.nextInt();
			A[a][b] = A[b][a] = 1;
		}
		D(A, C, V);
		C = new int[N+1];
		System.out.println();
		B(A, C, V);
	}
	
	public static void D(int[][] A, int[] C, int V) {
		C[V] = 1;
		System.out.print(V+" ");
		for(int i = 1; i < A.length; i++) {
			if(C[i]!=1&&A[V][i]==1) D(A, C, i);
		}
	}
	
	public static void B(int[][] A, int[] C, int V) {
		Queue<Integer> Q = new LinkedList<Integer>();
		
		C[V] = 1;
		Q.add(V);
		
		while(!Q.isEmpty()) {
			int n = Q.poll();
			System.out.print(n+" ");
			for(int i = 0; i < A.length; i++) {
				if(C[i]!=1&&A[n][i]==1) {
					Q.add(i);
					C[i] = 1;
				}
			}
		}
	}
}