// C_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include"dlist.h"

int main()
{
	struct dbl_linked_list* list = dbl_linked_list_init();
	dbl_linked_list_print(list);
	dbl_linked_list_push_front(list, 0);
	dbl_linked_list_print(list);
	dbl_linked_list_push_back(list, 2);
	dbl_linked_list_print(list);
	dbl_linked_list_insert(list, 0, 1);
	dbl_linked_list_print(list);
	dbl_linked_list_delete(&list);
	dbl_linked_list_print(list);
	dbl_linked_list_push_back(list, 2);
	dbl_linked_list_pop_back(list);
	dbl_linked_list_print(list);
	dbl_linked_list_pop_front(list);
	dbl_linked_list_print(list);
	dbl_linked_list_erase(list, 0);
	dbl_linked_list_print(list);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
