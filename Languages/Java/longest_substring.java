import java.util.*;
public class longest_substring {
    public static int lengthOfLongestSubstring(String str) {
       int n = str.length(); 
	int res = 0;
	int prev[]=new int[256];
	Arrays.fill(prev,-1);
	int i=0;
	for (int j = 0; j < n; j++){
	    i=Math.max(i,prev[str.charAt(j)]+1);
	    int maxEnd=j-i+1;
	    res=Math.max(res,maxEnd);
	    prev[str.charAt(j)]=j;
	} 
	return res; 
    }
    public static void main(String args[]){
        String str ="Hello";
        lengthOfLongestSubstring(str);
    }
}
