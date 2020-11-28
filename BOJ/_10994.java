package codup;

import java.util.Scanner;

public class _10994 {
	static char map[][] = new char[500][500];
	public static void drawStar(int n,int x,int y) {
		if(n==1) {
			map[x][y] = '*';
			return ;
		}
		int len = (n-1)*4 + 1;
		
		//위 아래 가로선
		for(int i=y;i<y+len;i++) {
			map[x][i]='*';
			map[x+len-1][i]='*';
			
		}
		
		//좌, 우 세로선
		for(int i=x;i<x+len;i++) {
			map[i][y]='*';
			map[i][y+len-1]='*';
		}
		
		
		drawStar(n-1,x+2,y+2);
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int num = (N-1)*4 +1;
		
		//공백으로 초기화
		for(int i=0;i<num;i++) {
			for(int j=0;j<num;j++) {
				map[i][j]=' ';
			}
		}
		drawStar(N,0,0); //첫번째 기준을 0,0
		
		for(int i=0;i<num;i++) {
			for(int j=0;j<num;j++) {
				System.out.print(map[i][j]);
			}
			System.out.print("\n");
		}
	}

}
