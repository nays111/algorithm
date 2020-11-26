package codup;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;

class Nation implements Comparable<Nation>{
	int index;
	int gold;
	int silver;
	int bronze;
	int rank;
	Nation(int index,int gold,int silver,int bronze,int rank){
		this.index=index;
		this.gold = gold;
		this.silver = silver;
		this.bronze = bronze;
		this.rank = rank;
	}
	@Override
	public int compareTo(Nation o) {
		// TODO Auto-generated method stub
		if(this.gold > o.gold) {
			return -1;
		}else if(this.gold == o.gold) {
			if(this.silver > o.silver) {
			return -1;
			}else if(this.silver == o.silver) {
				if(this.bronze > o.bronze) {
					return -1;
				}else if(this.bronze == o.bronze) {
					return 0;
				}
			}
		}
		return 1;
	}
	
}


public class _8979 {
	public static void calculateRank(ArrayList<Nation> list) {
		for(int i=1;i<list.size();i++) {
			if(list.get(i).gold==list.get(i-1).gold
					&& list.get(i).silver==list.get(i-1).silver
					&& list.get(i).bronze==list.get(i-1).bronze){
				list.get(i).rank = list.get(i-1).rank;
				
			}else {
				list.get(i).rank = i+1;
			}
		}
	}
	/*public static void calculateRank(Nation[] array) {
		for(int i=1;i<array.length;i++) {
			if(array[i].gold==array[i-1].gold
					&& array[i].silver==array[i-1].silver
					&& array[i].bronze==array[i-1].bronze) {
				array[i].rank = array[i-1].rank;
			}else {
				array[i].rank = i+1;
			}
		}
	}*/

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] str = br.readLine().split(" ");
		int N = Integer.parseInt(str[0]);
		int K = Integer.parseInt(str[1]);
		
		ArrayList<Nation>list = new ArrayList<>();
		//Nation[] array = new Nation[N];
		for(int i=0;i<N;i++) {
			
			String[] str2 = br.readLine().split(" ");
			int index,gold,silver,bronze;
			index = Integer.parseInt(str2[0]); //index
			gold = Integer.parseInt(str2[1]); //gold
			silver = Integer.parseInt(str2[2]); //silver
			bronze = Integer.parseInt(str2[3]); //bronze
			list.add(new Nation(index,gold,silver,bronze,0));
			//array[i] = new Nation(index,gold,silver,bronze,0);
		}
		Collections.sort(list);
		//Arrays.sort(array);
		
		//calculateRank(array);
		calculateRank(list);
		for(int i=0;i<N;i++) {
			if(list.get(i).index == K) {
				
				bw.write(list.get(i).rank+"\n");
				
				
				break;
			}
		}
		bw.flush();
		br.close();
		bw.close();
	}

}
