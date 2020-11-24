package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class _1834 {

    public static void main(String[] args) throws IOException {
    	//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	Scanner sc = new Scanner(System.in);
    	
    	long N = sc.nextLong();
    	//int N = Integer.parseInt(br.readLine());
    	long sum = 0;
    	for(int i=1;i<N;i++) {
    		sum += (N+1)*i;
    	}
    	System.out.print(sum);
    } 
}
