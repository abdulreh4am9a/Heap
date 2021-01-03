#include<iostream>
using namespace std;
//template<typename T>
//void swap(T& x, T& y) {
//	T temp = x;
//	x = y;
//	y = temp;
//}
template<typename T>
void ReheapUp(T data[], int first, int last) {
	int parent = (last - 1) / 2;
	if (last > parent) {
		if (data[last] > data[parent]) {
			swap(data[last], data[parent]);
			ReheapUp(data, first, parent);
		}
	}
}
template<typename T>
void ReheapDown(T data[], int first, int last) {
	int left, right, max;
	left = (first * 2) + 1;
	right = (first * 2) + 2;
	max = left;
	if (left <= last) {
		if (right <= last && data[right] > data[left]) {
			max = right;
		}
		if (data[first] < data[max]) {
			swap(data[first], data[max]);
			ReheapDown(data, max, last);
		}
	}
}
template<typename T>
class priority_queue {
	T* data;
	int last_index, SIZE;
public:
	priority_queue(int s = 100) {
		SIZE = s;
		last_index = -1;
		data = new T[SIZE];
	}
	~priority_queue() {
		delete[]data;
	}
	void push(const T& val) {
		if (full()) {
			throw("Queue Overflow!");
		}
		data[++last_index] = val;
		ReheapUp(data, 0, last_index);
	}
	bool empty() const {
		return last_index == -1;
	}
	bool full() const {
		return last_index == SIZE - 1;
	}
	int size() const {
		return last_index + 1;
	}
	void make_empty() {
		last_index = -1;
	}
	T top() const {
		if (empty()) {
			throw("Queue Underflow!");
		}
		return data[0];
	}
	void pop() {
		if (empty()) {
			throw("Queue Underflow!");
		}
		data[0] = data[last_index--];
		ReheapDown(data, 0, last_index);
	}
};