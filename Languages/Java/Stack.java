import java.io.*;
import java.util.*;
public class Exp2_stack_class extends Stack<Integer> {
	 private int top;
	 Exp2_stack_class()
	    {
	        top=-1;
	    }
	    public int arr[]=new int[10];
	    public void push(int x)
	    {
	        arr[++top]=x;
	        System.out.println("The element pushed into the stack is: "+x);
	    }
	    public Integer  pop()
	    {
	          int z=arr[top--];
	        return z;
	    }
	    public boolean isEmpty()
	    {
	        if(top<0)
	            return  true;
	        else
	            return  false;
	    }
	    static void stack_add(Stack<Integer> stack,int n)
	    {
	    	for(int i=0;i<n;i++)
	    	{
	    		System.out.println(stack.push(i));
	    	}
	    }
	    static  void stack_search(Stack<Integer> stack,int ele)
	    {
	    	Integer pos=(Integer)stack.search(ele);
	    	if(pos==-1)
	    	{
	    		System.out.println("Element not found!!!!");
	    	}
	    	else {
	    		System.out.println(ele + " Found at position :" + pos);
	    		
	    	}
	    }
	      void super_custom(int n) {
	    	System.out.println("Displaying the use of super()");
	    	System.out.println("Displaying elements in the stack");
	    	for(int i=0;i<n;i++)
	    	{
	    	 System.out.println(super.push(i));
	    }
	    	System.out.println("Popping out !!!");
	    	Integer pop=(Integer)super.pop();
	    	System.out.println("Element popped out is: " + pop);
	      }
	    
	    
	   
	    public static void  main(String args[])
	    {
	    	
	    	Exp2_stack_class Stack=new Exp2_stack_class();
	    
	        Stack.push(10);
	        Stack.push(20);
	        Stack.push(30);
	        Stack.push(40);
	        Stack.push(50);
	        System.out.println("The element popped from the stack is: "+Stack.pop());
	        System.out.println(Stack.isEmpty());
	        Scanner scn=new Scanner(System.in);
	       
	       
	        System.out.println("Enter the no of elements ");
	        int n=scn.nextInt();
	      
	        Stack.super_custom(n);
	        
	    }


}
