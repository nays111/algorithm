package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2292 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int range=1;
		int cnt = 1;
		int tmp = 1;
		while(true) {
			if(range>=n) {
				break;
			}
			tmp=6*(cnt++);
			range +=tmp;
		}
		
		System.out.print(cnt);

	}

}
