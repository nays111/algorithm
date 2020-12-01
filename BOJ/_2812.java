package codup;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class _2812 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        String input = br.readLine();
        char[] arr = input.toCharArray();
        Deque<Character> deque = new ArrayDeque<>();
        for(int i=0;i<arr.length;i++) {
        	while(K>0 &&
        		!deque.isEmpty() &&
        		deque.getLast() < arr[i]) {
        		deque.removeLast();
        		K--;
        	}
        	deque.addLast(arr[i]);
        }
        StringBuilder ans = new StringBuilder();
        while(deque.size() > K) {
        	ans.append(deque.removeFirst());
        }
        bw.write(ans.toString()+"\n");
        bw.flush();
        bw.close();
        br.close();
	}

}
