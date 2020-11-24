package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class _3034 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = sc.nextInt();
		int width = sc.nextInt();
		int height = sc.nextInt();
		int d = (int) Math.sqrt(width*width + height*height);
		
		for(int i=0;i<N;i++) {
			int n=Integer.parseInt(br.readLine());
			if(n<=d) {
				System.out.println("DA");
			}
			System.out.println("NE");
		}
	
		br.close();
	}
}
