package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _14754 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int height = Integer.parseInt(st.nextToken());
		int width = Integer.parseInt(st.nextToken());
		int arr[][] = new int[height][width];
		int height_max[] = new int[height];
		int width_max[] = new int[width];
		long sum = 0;
		long add = 0;
		for(int i=0;i<arr.length;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<arr[i].length;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				height_max[i] = Math.max(height_max[i], arr[i][j]);
				width_max[j] = Math.max(width_max[j], arr[i][j]);
				add +=arr[i][j];
			}
		}
	
		for(int i=0;i<height_max.length;i++) {
			sum+=height_max[i];
		}
		for(int j=0;j<width_max.length;j++) {
			sum+=width_max[j];
		}
	
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[i].length;j++) {
				if(height_max[i]==width_max[j]) {
					sum-=height_max[i];
				}
			}
		}
		System.out.print(add-sum);

	}

}
