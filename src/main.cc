#include "linked_list.cc"
int main() {
	setlocale(LC_ALL, "ru");
	LinkedList<Student> Student_list;
	Student_list.push_tail(Student("���������", "�����", 1, 2));
	Student_list.push_tail(Student("����", "������", 3, 4));
	Student_list.push_tail(Student("����", "������", 2, 4));
	Student_list.push_tail(Student("����", "�����", 4, 5));
	Student_list.push_tail(Student("����", "��������", 5, 3));
	Student_list.push_tail(Student("����", "����������", 1, 2));
	Student_list.push_tail(Student("����", "������", 1, 5));
	Student_list.push_tail(Student("����", "���������", 3, 5));
	Student_list.push_tail(Student("����", "������", 4, 2));
	Student_list.push_tail(Student("����", "�������", 5, 3));
	Student_list.push_tail(Student("�����", "���������", 1, 4));
	std::cout << "___________________________________" << std::endl;
	std::cout << "������ ��������� �� ����������:" << std::endl;
	std::cout << "___________________________________" << "\n\n" << std::endl;
	Student_list.print();
	std::cout << "\n\n" << "___________________________________" << std::endl;
	std::cout << "������ ��������� ����� ����������:" << std::endl;
	std::cout << "___________________________________" << "\n\n" << std::endl;
	Student_list.delete_student();
	Student_list.print();
	
}