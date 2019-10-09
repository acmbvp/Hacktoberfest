package cn;

public class StackUsingQueue<T> {
	private queueusingLL<T> q1;
	private queueusingLL<T> q2;
	
	public StackUsingQueue() {
		q1 = new queueusingLL<>();
		q2 = new queueusingLL<>();
		
	}
	
	public void push(T element) {
		q1.enqueue(element);
	}
	public T pop() {
		while(q1.size()!=1) {
			T ans = q1.dequeue();
			q2.enqueue(ans);
		}
		T data = q1.dequeue();
		while(!q2.isEmpty()) {
			T ans = q2.dequeue();
			q1.enqueue(ans);
		}
		return data;
		
	}
	

}
