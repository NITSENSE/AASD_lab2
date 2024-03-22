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
	Student_list.print();
	Student_list.delete_student();
	Student_list.print();
	
}