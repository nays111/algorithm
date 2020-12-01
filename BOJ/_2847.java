package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2847 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int arr[] = new int[N];
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		if(N==1) {
			System.out.print(0);;
		}else {
			int count = 0;
			for(int i=N-2;i>=0;i--) {
				//int highLevel = arr[i + 1];
				//int lowLevel = arr[i];
				if(arr[i]>=arr[i+1]) {
					count+= (arr[i]-(arr[i+1]-1));
					arr[i] = arr[i+1]-1;
				}
			}
			System.out.print(count);
		}
	}

}
