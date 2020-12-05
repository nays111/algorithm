package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _13305 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		long[] distances = new long[N-1];
		long[] prices = new long[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<N-1;i++) {
			int distance = Integer.parseInt(st.nextToken());
			distances[i] = distance;
			
		}
		
		st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<N;i++) {
			int place = Integer.parseInt(st.nextToken());
			prices[i]=place;
			
		}
		long start = distances[0]*prices[0];
		int nowCity = 0;
		int nextCity = nowCity+1;
		while(nextCity<N-1) {
			if(prices[nowCity]<prices[nextCity]) {
				start += prices[nowCity]*distances[nextCity];
			}else {
				start+=prices[nextCity]*distances[nextCity];
				nowCity = nextCity;
			}
			nextCity++;
		}
		System.out.print(start);
		
	}

}
