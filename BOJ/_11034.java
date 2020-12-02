package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _11034 {

private static final String NEW_LINE = "\n";
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		String input = "";
		while((input = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(input);
			
			int[] arr = new int[3];
			for(int i = 0; i < 3; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			sb.append(Math.max(arr[1] - arr[0], arr[2] - arr[1]) - 1).append(NEW_LINE);
		}
		
		System.out.print(sb.toString());
	}

}
