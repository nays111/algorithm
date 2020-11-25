package codup;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class _2033 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Long N = Long.parseLong(br.readLine());
		long d = 10;
		
		while(d<N) {
			if(N%d < d/2) {
				N-=N%d;
			}else {
				N+=d-(N%d);
			}
			
			d*=10;
		}
		bw.write(N+"\n");
		
		bw.flush();
		br.close();
		bw.close();
		
	}

}
