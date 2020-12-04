import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        
        int[] answer_1 = {1,2,3,4,5};
        int[] answer_2 = {2,1,2,3,2,4,2,5};
        int[] answer_3 = {3,3,1,1,2,2,4,4,5,5};
        int[] count = {0,0,0};
        for(int i=0;i<answers.length;i++){
            if(answers[i] == answer_1[i%5]){
                count[0]++;
            }
            if(answers[i] == answer_2[i%8]){
                count[1]++;
            }
            if(answers[i] == answer_3[i%10]){
                count[2]++;
            }
        }
        int max = Math.max(count[0],Math.max(count[1],count[2]));
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i=0;i<3;i++){
            if(max == count[i]){
                list.add(i+1);
            }
        }
        int[] answer = new int[list.size()];
        for(int i=0;i<answer.length;i++){
            answer[i] = list.get(i);
        }
                           
        return answer;
    }
}