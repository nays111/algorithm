package codup;


import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class _7570 {

	public static void main (String args[]) throws IOException { 
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int dp[] =new int[N+1];
		
		for(int i=0;i<N;i++) {
			int num = sc.nextInt();
			dp[num] = dp[num-1]+1;
		}
		Arrays.sort(dp);
		System.out.print(N-dp[N]);

	}

}
