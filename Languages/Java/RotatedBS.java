public class RotatedBS {
    public static void main(String[] args) {
        int[] arry ={5,6,7,8,1,2,3,4};
       
        System.out.println(rbs(arry, 8, 0, arry.length-1));
    }
    static int rbs(int[] arry, int target,int s,int e){
     if(s > e){
        return -1;
     } 
        int m = s+(e -s)/2;
     if(arry[m] == target){
        return m;
     }
      if(arry[s] <= arry[m]){
        if(target >= arry[s] && target <= arry[m]){
           return rbs(arry, target, s, m-1);
         }else{
            return rbs(arry, target, m+1, e);
         }
      }
      if(target >= arry[m] && target <= arry[e]){
        return rbs(arry, target, m+1, e);
      }

      return rbs(arry, target, s, m-1);
    
    }
}
