import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        String str = "";
        str+=n;
        char[] ch = str.toCharArray();
        Arrays.sort(ch);
        str="";
        System.out.print(ch);
        for(int i=ch.length-1;i>=0;i--){
            str +=ch[i];
        }
        answer = Long.parseLong(str);
        return answer;
    }
}