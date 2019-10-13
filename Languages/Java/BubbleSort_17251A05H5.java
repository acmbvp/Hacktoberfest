class BubbleSort{
  public static void main(String args[]){
    int a[]={1,7,0,-4,3,2};
    int n=a.length;
    for (int c = 0; c < ( n - 1 ); c++) {
      for (int d = 0; d < n - c - 1; d++) {
        if (a[d] >a[d+1])
        {
          int swap= a[d];
          a[d]   = a[d+1];
          a[d+1] = swap;
        }
      }
    }
    for(int j=0;j<a.length;j++)
        System.out.print(a[j]+" ");
    System.out.println();
 
        
  }
}
