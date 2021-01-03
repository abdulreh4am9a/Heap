#include"priority_queue.h"
int main() {
	priority_queue<int> q(10);
	q.push(10);
	q.push(5);
	q.push(3);
	q.push(2);
	q.push(20);
	q.push(7);
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}