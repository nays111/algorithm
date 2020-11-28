import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String[] str = new String[numbers.length];
        
        //가장 먼저 int 배열을 String 배열로 변환
        for(int i=0;i<numbers.length;i++){
            str[i] = (String.valueOf(numbers[i]));
        }
        
        //330 과 303 중 뭐가 더 큰지 규칙 정해주기
        Arrays.sort(str,new Comparator<String>(){
            public int compare(String s1,String s2){
                return (s2+s1).compareTo(s1+s2);
            }
        });
        if(str[0].equals("0")) return "0";
        for(int i=0;i<str.length;i++){
            answer+=str[i];
        }
            
        
        return answer;
    }
}