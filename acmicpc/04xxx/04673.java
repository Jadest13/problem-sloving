class BJ04673 {
	static int[]A = new int[10036];
	public static void main(String[]V) {
		for(int i = 1; i < 10001; i++) {
			A[F(i)] = 1;
			if(A[i] != 1)
				System.out.println(i);
		}
	}
	public static int F(int a) {
		int R = a;
		for(int i = a; i > 0; i/=10)
			R+= i%10;
		return R;
	}
}