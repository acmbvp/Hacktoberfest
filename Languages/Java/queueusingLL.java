package cn;
import java.util.*;
public class queueusingLL<T> {
		   
	   private Node<T> head;
	   
	    private Node<T> tail;
	    private int size = 0;
	    
	    public void enqueue(T element){
	    	Node<T> newNode = new Node<>(element);
	    	if(head==null){
	    		head = newNode;
	    	}
	    	if(tail==null){
	    		tail=newNode;
	    	}
	    	else{
	    		tail.next = newNode;
	    		tail = newNode;
	    	}
	    	size++;
	    }
	    public T dequeue(){
	    	T element = head.data;
	    	size--;
	    	head = head.next;
	    	if(head==null){
	    		tail = null;
	    	}
	    	return element;
	    }
	    public T front(){
	    	return head.data;
	    }
	    public int size(){
	    	return size;
	    }
	    public boolean isEmpty(){
	    	if(head==null && tail==null){
	    		return true;
	    	}
	    	return false;
	    }
	}


