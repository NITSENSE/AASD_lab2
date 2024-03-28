#include "linked_list.cc"
int main() {
	setlocale(LC_ALL, "ru");
	LinkedList<Student> Student_list;
	Student_list.push_tail(Student("Святослав", "Ильин", 1, 2));
	Student_list.push_tail(Student("Вова", "Косцов", 3, 4));
	Student_list.push_tail(Student("Ваня", "Клюшин", 2, 4));
	Student_list.push_tail(Student("Витя", "Ионов", 4, 5));
	Student_list.push_tail(Student("Паша", "Чепчиков", 5, 3));
	Student_list.push_tail(Student("Петя", "Мирославов", 1, 2));
	Student_list.push_tail(Student("Дима", "Исаков", 1, 5));
	Student_list.push_tail(Student("Илья", "Братчиков", 3, 5));
	Student_list.push_tail(Student("Даня", "Зайцев", 4, 2));
	Student_list.push_tail(Student("Саша", "Антонов", 5, 3));
	Student_list.push_tail(Student("Артем", "Тимошенко", 1, 4));
	std::cout << "___________________________________" << std::endl;
	std::cout << "Список студентов до отчисления:" << std::endl;
	std::cout << "___________________________________" << "\n\n" << std::endl;
	Student_list.print();
	std::cout << "\n\n" << "___________________________________" << std::endl;
	std::cout << "Список студентов после отчисления:" << std::endl;
	std::cout << "___________________________________" << "\n\n" << std::endl;
	Student_list.delete_student();
	Student_list.print();
	
}