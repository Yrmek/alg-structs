#include<iostream> 
using namespace std;
const int MAX_SIZE = 10; //Количество элементов в массиве (Стеке)

struct my_stack //Описываем структуру стек
{
	int data[MAX_SIZE]; //Массив с количеством элементов MAX_SIZE
	int last;           //Указатель на вершину стека
};
void push(my_stack& s, int x)//Процедура добавления элемента
{
	if (s.last == MAX_SIZE) { //Сообщение о переполнении стека cout<<"Stack Overflow";
		return;
	} s.data[s.last++] = x;
}
int pop(my_stack& s) //Получение элемента с вершины стека
{
	return s.data[--s.last];//Возвращаем элемент с вершины стека
}

int main()
{
	my_stack a; a.last = 0; 
	push(a, 3);
	push(a, 6);
	push(a, 2);
	cout << pop(a) << " ";//Программа выведет 2 cout<<pop(a)<<" ";//Программа выведет 6 cout<<pop(a)<<" ";//Программа выведет 3 return 0;
}
