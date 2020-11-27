package codup;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class _1789 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		long S = Long.parseLong(br.readLine());
		long N = 1;
		
		while(S-N>=0) {
			S-=N;
			N++;
		}
		bw.write(N-1+"\n");
		bw.flush();
		br.close();
		bw.close();

	}

}
