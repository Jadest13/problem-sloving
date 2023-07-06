import java.util.*;

class BJ04948 {
	public static void main(String[]V) {
		Scanner S = new Scanner(System.in);
		while(true){
			int R = 0, T = S.nextInt(), A[] = new int[T*2+1];
			if(T==0)break;
			Arrays.fill(A, 0);
			A[1]=1;
			for(int i = 2; i <= T*2; i++)
				for(int j = 2; i*j <= T*2; j++)
					A[i*j] = 1;
			for(int i = T+1; i <= T*2; i++)
				if(A[i]!=1) R++;
			System.out.println(R);
		}
	}
}