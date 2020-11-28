import java.util.Arrays;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i=0;i<commands.length;i++){
            int[] temp = new int[(commands[i][1]-commands[i][0]+1)]; //5-2+1
            for(int j=0;j<temp.length;j++){
                temp[j] = array[j+(commands[i][0]-1)];
            }
            Arrays.sort(temp);
            answer[i] = temp[commands[i][2]-1];
        }
        return answer;
    }
}