#include "linked_list.cc"
int main() {
	LinkedList<int> ds;
	ds.push_tail(3);
	ds.push_tail(3);
	ds.push_tail(3);
	ds.push_tail(3);
	ds.push_tail(1);
	ds.push_tail(3);
	ds.push_tail(4);
	ds.push_tail(1);
	ds.push_tail(3);
	ds.push_tail(4);
	ds.push_tail(1);
	ds.push_tail(3);
	ds.push_tail(4);
	ds.push_tail(1);
	ds.push_tail(3);
	ds.push_tail(4);
	ds.print();
	std::cout << "______________________________________-" << std::endl;
	ds.delete_node(3);
	ds.print();

}