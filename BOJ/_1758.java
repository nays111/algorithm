package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class _1758 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		Integer arr[] = new Integer[N];
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(arr, Comparator.reverseOrder()); // 배열을 내림차순으로 정렬.
		long sum = 0;
		for(int i=0;i<N;i++) {
			if (arr[i] - i <= 0) {
                break;}
			sum+=arr[i]-(i+1-1);
		}
		System.out.print(sum);
	}
}
	
