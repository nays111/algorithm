import java.util.*;
class Solution {
    public static int getDistance(int location,int number){
        if(location==0){
            location=11;
        }
        if(number==0){
            number=11;
        }
        int XLocation=(location-1)/3;
        int YLocation = (location-1)%3;
        
        int XNumber = (number-1)/3;
        int YNumber = (number-1)%3;
        
        int result = Math.abs(XNumber-XLocation)+Math.abs(YNumber-YLocation);
        return result;
        
    }
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int leftLocation = 10;
        int rightLocation = 12;
        for(int i=0;i<numbers.length;i++){
            if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
                sb.append("L");
                leftLocation = numbers[i];
            }else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
                sb.append("R");
                rightLocation=numbers[i];
            }else{
                int leftDistance = getDistance(leftLocation,numbers[i]);
                int rightDistance = getDistance(rightLocation,numbers[i]);
                if(leftDistance-rightDistance>0){
                    sb.append("R");
                    rightLocation = numbers[i];
                }else if(rightDistance-leftDistance>0){
                    sb.append("L");
                    leftLocation=numbers[i];
                }else{
                    if(hand.equals("right")){
                        sb.append("R");
                        rightLocation=numbers[i];
                    }else{
                        sb.append("L");
                        leftLocation = numbers[i];
                    }
                }
            }
        }
        return sb.toString();
    }
}