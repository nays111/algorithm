import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
       
        int num = 10;
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i=0;i<arr.length;i++){
            if(arr[i]!=num){
                list.add(arr[i]);
                num=arr[i];
            }
        }
         int[] answer = new int[list.size()];
        for(int i=0;i<list.size();i++){
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}