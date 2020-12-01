package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class _14659 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int arr[] =new int[30000];
		String[] strings = br.readLine().split(" ");
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(strings[i]);
		}
		int result = 0;
		for(int i=0;i<N;i++) {
			int criteria = arr[i];
			int count = 0;
			for(int j=i+1;j<N;j++) {
				if(arr[j] > criteria) {
					break;
				}else {
					count++;
				}
			}
			result = Math.max(result,count); //그때그때 큰거를 구해주기
		}
		System.out.print(result);
	}

}
