package codup;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class _11104 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		
		for(int i=0;i<N;i++) {
			long result =(long)0;
			long cnt = (long)1;
			StringTokenizer st = new StringTokenizer(br.readLine());
			String[] str = st.nextToken().split("");
			for(int j=23;j>=0;j--) {
				result+=Integer.parseInt(str[j])*cnt;
				cnt*=2;
			}
			bw.write(result+"\n");
		}		
		bw.flush();
		br.close();
		bw.close();
		
	}

}
