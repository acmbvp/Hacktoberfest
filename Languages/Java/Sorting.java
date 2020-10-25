
import java.util.*;
class Sorting{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int arr[]= new int[7];
        int temp;
        System.out.println("Enter the element of array");
        for(int i=0;i<7;++i)
       {
            arr[i]=sc.nextInt();
       }

       for(int i = 0;i<7;++i)
       {
           for (int j=i+1;j<7;++j)
           {
               if(arr[i]>arr[j])
               {
                   temp = arr[i];
                   arr[i]=arr[j];
                   arr[j]=temp;
               }
           }
       }
       System.out.println("The elements of sorted array is :");
       for(int i=0;i<7;++i)
       {
           System.out.print(arr[i]+" ");
       }
    }
}
