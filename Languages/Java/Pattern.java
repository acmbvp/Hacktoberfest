// 4 4 4 4 3 3 3 3 2 2 2 2 1 1 1 1 
// 4 4 4 3 3 3 2 2 2 1 1 1 
// 4 4 3 3 2 2 1 1 
// 4 3 2 1 

class Pattern
{
    public static void main(String[] args) {
        printPat(4);
    }
    static void printPat(int n)
    {
         // Your code here
         StringBuilder out = new StringBuilder();
         int count=n+1;
         for(int i=n;i>=1;i--)
         {
             count--;
             for(int j=n;j>=1;j--)
             {
                 for(int k=1;k<=count;k++)
                 {
                    out.append(j+" ");
                 }
             }
             out.append("\n");
         }
         System.out.print(out);
    }
}