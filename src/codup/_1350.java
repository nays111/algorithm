package codup;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class _1350 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		ArrayList<Long> list= new ArrayList<>();
		for(int i=0;i<N;i++) {
			long a = Long.parseLong(st.nextToken());
			list.add(a);
		}
		int cluster_size = Integer.parseInt(br.readLine());
		long answer = 0L;
		for(int i=0;i<list.size();i++) {
			if((long)list.get(i) % cluster_size ==0) {
				answer +=(long)cluster_size*list.get(i) / cluster_size;
			}else {
				answer +=(long)cluster_size*(list.get(i)/cluster_size +1);
			}
		}
		bw.write(answer+"\n");
		
		bw.flush();
		br.close();
		bw.close();

	}

}
