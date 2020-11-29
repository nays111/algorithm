package codup;

import java.util.Scanner;

public class _10997 {
	static char map[][]=new char[500][500];
	public static void drawStar(int n,int x,int y) {
		
		int width = 4*(n-1)+1;
		int height = width+2;
		
		for(int i=1;i<width;i++) {
			map[x][y--]='*';
		}
		for(int i=1;i<height;i++) {
			map[x++][y]='*';
		}
		for(int i=1;i<width;i++) {
			map[x][y++]='*';
		}
		for(int i=1;i<height-2;i++) {
			map[x--][y]='*';
		}
		map[x][y]='*';
		y--;
		map[x][y]='*';
		if(n==2) {
			map[x][y-1]='*';
			map[x+1][y-1]='*';
			map[x+2][y-1]='*';
			return;
		}
		
		drawStar(n-1,x,y-1);
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if(N==1) {
			System.out.print("*");
			return;
		}
		int width = 4*(N-1)+1;
		int height = width+2;
		for(int i=0;i<height;i++) {
			for(int j=0;j<width;j++) {
				map[i][j]=' ';
			}
		}
		drawStar(N, 0, width-1); //시작점은 (0,4*(n-1)+1)
		for(int i=0;i<height;i++) {
			if(i==1) {
				System.out.print("*\n");
				continue;
			}
			for(int j=0;j<width;j++) {
				System.out.print(map[i][j]);
			}
			System.out.print("\n");
		}
	}

}
