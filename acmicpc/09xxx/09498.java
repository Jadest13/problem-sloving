import java.util.*;

class BJ09498 {
	public static void main(String[]V) {
		int a = new Scanner(System.in).nextInt();
		System.out.print(a>89?"A":a>79?"B":a>69?"C":a>59?"D":"F");
	}
}