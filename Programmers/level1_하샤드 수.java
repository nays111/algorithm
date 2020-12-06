class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        String str = String.valueOf(x);
        int arr[] = new int[str.length()];
        for(int i=0;i<str.length();i++){
            arr[i] = str.charAt(i)-'0';
        }
        int sum = 0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
        }
        if(x%sum==0){
            answer = true;
        }else{
            answer=false;
        }
        
        return answer;
    }
}