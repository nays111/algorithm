class Solution {
    static public int gcd(int a,int b){
        while(b!=0){
            int r = a%b;
            a=b;
            b=r;
        }
        return a;
    }
    static public int lcm(int a,int b){
        int l_cm = (a*b)/gcd(a,b);
        return l_cm;
    }
    public int solution(int[] arr) {
        int answer = 0;
        int first = arr[0];
        for(int i=1;i<arr.length;i++){
            first = lcm(first,arr[i]);
        }
        return first;
    }
}