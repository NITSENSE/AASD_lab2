#ifndef LIST_ONCE
#define LIST_ONCE

#include<iostream>
template<typename T>
struct Node {
	T data;
	Node<T>* next;
	explicit Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList {
	Node<T>* _head;
	size_t _size;
public:
	LinkedList() : _head(nullptr), _size(0) {}

	explicit LinkedList(const LinkedList<T>& copy) : LinkedList() {
		Node<T>* temp = copy._head;
		while (temp)
		{
			push_tail(temp->data);
			temp = temp->next;
		}
	}

	void push_tail(T data) {
		_size++;
		if (_head == nullptr) _head = new Node<T>(data);
		else {
			Node<T>* temp = _head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = new Node<T>(data);
		}
	}

	
	

};

#endif