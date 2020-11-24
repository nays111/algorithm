package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1546 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		double arr[] = new double[N];
		double max = 0;
		double sum = 0;
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(br.readLine());
			if(max < arr[i]) {
				max = arr[i];
			}
			arr[i] = (arr[i]/max)*100;
		
			
			sum +=arr[i];
		}
		
		
		
		System.out.printf("%f",sum/N);
	}

}
