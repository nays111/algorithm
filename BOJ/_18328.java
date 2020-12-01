package codup;

import java.util.Scanner;

public class _18328 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String str =sc.nextLine();
		int ans = 0;
		str='A'+str;
		for(int i=0;i<str.length()-1;i++) {
			ans += Math.min(Math.abs((str.charAt(i+1) - 'A') - (str.charAt(i) - 'A')), 26 - Math.abs((str.charAt(i+1) - 'A') - (str.charAt(i) - 'A')));
		}
		System.out.print(ans);
		
	}

}
