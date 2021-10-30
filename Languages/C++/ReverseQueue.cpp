#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &Queue) {
 stack<int> Stack; 
	while (!Queue.empty()) { 
		Stack.push(Queue.front()); 
		Queue.pop(); 
	} 
	while (!Stack.empty()) { 
		Queue.push(Stack.top()); 
		Stack.pop(); 
	} 

}
int main() {
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}
