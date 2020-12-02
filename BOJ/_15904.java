package codup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _15904 {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution(br.readLine()));
    }

    static String solution(String s) {
        char[] ucpc = {'U', 'C', 'P', 'C'};
        int index = 0;

        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == ucpc[index]) {
                index++;
            }

            if(index == 4) {
                return "I love UCPC";
            }
        }

        return "I hate UCPC";
    }
}
