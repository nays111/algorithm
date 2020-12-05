package codup;

import java.io.IOException;
import java.util.Scanner;

public class _17262 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int a1[] = new int[100001];
		int a2[] = new int[100001];
		int answer = 0;
		int max = 0;
		int min = 100001;
		for(int i=0;i<N;i++) {
			a1[i]=sc.nextInt();
			a2[i]=sc.nextInt();
			if(a2[i]<min) {
				min=a2[i];
			}
			if(a1[i]>max) {
				max=a1[i];
			}
		}
		int answers = max-min;
		if(answers<0) {
			answer = 0;
		}else {
			answer=answers;
		}
		
		System.out.print(answer);
		

	}

}
