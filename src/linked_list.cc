#ifndef LIST_ONCE
#define LIST_ONCE

#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
struct Student {
	std::string name;
	std::string lastname;
	int number_grup;
	int score;
	Student(std::string name, std::string lastname, int number_grup, int score) : name(name), lastname(lastname), number_grup(number_grup), score(score){}
	friend std::ostream& operator<<(std::ostream&os, const Student&st) {
		os << st.name << " " << st.lastname << " " << st.number_grup << " " << st.score;
		return os;
	}
};


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

	~LinkedList() {
		clear();
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

	void pop_head() {
		if (!_head)
			throw std::invalid_argument("the list is empty");
		Node<T>* temp = _head;
		_head = _head->next;
		delete temp;
		_size--;
	}

	void pop_tail() {
		if (!_head)
			throw std::invalid_argument("the list is empty");
		Node<T>* temp = _head;
		if (_size == 1)
			pop_head();
		while (temp->next->next) temp = temp->next;
		delete temp->next;
		temp->next = nullptr;
		_size--;
	}

	void clear() {
		while (_head) {
			pop_head();
		}
	}
	
	LinkedList(size_t size, T lower_bound, T upper_bound) : LinkedList() {
		std::random_device rd;
		std::mt19937 gen(rd());

		if constexpr (std::is_integral_v<T>) {
			std::uniform_int_distribution<T> dist(lower_bound, upper_bound);

			for (size_t i = 0; i < size; ++i) {
				T data = dist(gen);
				push_tail(data);
			}
			_size = size;
		}
		else if constexpr (std::is_floating_point_v<T>) {
			std::uniform_real_distribution<T> dist(lower_bound, upper_bound);

			for (size_t i = 0; i < size; ++i) {
				T data = dist(gen);
				push_tail(data);
			}
			_size = size;
		}
	}

	LinkedList<T>& operator = (LinkedList<T>& copy) {
		if (this != &copy) {
			clear();
			Node<T>* temp = copy._head;
			while (temp) {
				push_tail(temp->data);
				temp = temp->next;
			}
		}
		return *this;
	}
	
	void push_tail(const LinkedList<T>& other) {
		if (this != &other) {
			Node<T>* temp = other._head;
			while (temp) {
				push_tail(temp->data);
				temp = temp->next;
			}
		}
	}

	void push_head(T data) {
		Node<T>* element = new Node<T>(data);
		++_size;
		if (_head == nullptr) _head = element;
		else {
			element->next = _head;
			_head = element;
		}
	}

	void push_head(const LinkedList<T>& other) {
		if (this != &other) {
			for (int i = other._size - 1; i >= 0; i--) {
				Node<T>* temp = other._head;
				for (int j = 0; j < i; j++)
					temp = temp->next;
				push_head(temp->data);
				_size++;
			}		
		}
	}

	void delete_node(T data) {
		Node<T>* pre = nullptr;
		Node<T>* temp = _head;
		size_t size = _size;
		for (int i = 0; i < size; ++i) {
			if ((temp->data == data) && (!pre)) {
				temp = temp->next;
				pop_head();
				--_size;
			}
			else if (temp->data == data) {
				pre->next = temp->next;
				delete temp;
				temp = pre->next;
				--_size;
			}
			else {
				pre = temp;
				temp = temp->next;
			}
		}
	}

	T& operator[](const int index) {
		if ((index >= _size) || (index < 0))
			throw std::invalid_argument("invalid index");
		Node<T>* temp = _head;
		for (int i = 0; i != index; ++i) {
			temp = temp->next;
		}
		return temp->data;
	}

	void print() {
		Node<T>* temp = _head;
		while (temp!= nullptr) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}


	void delete_student() {
		Node<Student>* temp = _head;
		Node<Student>* pre = nullptr;
		while (temp != nullptr) {
			if ((temp->data.score < 3) && (!pre)) {
				temp = temp->next;
				pop_head();
				--_size;
			}
			else if (temp->data.score < 3) {
				pre->next = temp->next;
				delete temp;
				temp = pre->next;
				--_size;
			}
			else {
				pre = temp;
				temp = temp->next;
			}
		}
	}
};

#endif