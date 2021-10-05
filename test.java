import java.util.*;
public class test{

     public static void main(String []args){
       Scanner sc = new Scanner(System.in);
       String str= sc.nextLine();
       
       for(int i=0;i<str.length();i++)
       {
           if ( str.charAt(i) >= 'A' && str.charAt(i) <= 'Z')
           {
               
               System.out.println("");
               System.out.print(Character.toLowerCase(str.charAt(i)));
           }
            else if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z')
            {
               
                System.out.print( Character.toUpperCase(str.charAt(i)));
            }
       }
     }
}