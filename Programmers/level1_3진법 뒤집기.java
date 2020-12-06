class Solution {
    public int solution(int n) {
        int answer = 0;
        String a="";
        while(n!=0){
            a+=n%3;
            n=n/3;
        }
        System.out.print(a);
        int[] arr = new int[a.length()];
        for(int i=0;i<a.length();i++){
            arr[i] = a.charAt(i)-'0';
        }
        System.out.print(arr[0]);
        
        int multi = 1;
        for(int i=arr.length-1;i>=0;i--){
            answer+=arr[i]*multi;
            multi*=3;
        }
        
        return answer;
    }
}