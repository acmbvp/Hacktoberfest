package cn;

public class StackUsingLL<T> {
	private Node<T> head;
	private int count;
	
	public void push(T element){
		Node<T> newNode = new Node<>(element);
		newNode.next = head;
		head = newNode;
		count++;
		
	}
	public T pop(){
		if(head==null){
			return null;
		}
		T element = head.data;
		count--;
		head = head.next;
		return element;
		
	}
	public int size(){
		if(count==0){
			//exception throw
		}
		return count;
	}
	public boolean isEmpty(){
		if(count==0){
			return true;
		}
		return false;
		
	}
	
	
}
