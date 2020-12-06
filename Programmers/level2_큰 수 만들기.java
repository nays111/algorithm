class Solution {
    public String solution(String number, int k) {
        StringBuilder answer = new StringBuilder();
        int temp = 0;
        int index = 0;
        for(int i=0;i<number.length()-k;i++){
            temp=0;
            for(int j=index;j<=i+k;j++){
                if(temp<number.charAt(j)-'0'){
                    temp = number.charAt(j)-'0';
                    index=j+1;
                }
            }
            answer.append(temp);
        }
        return answer.toString();
    }
}