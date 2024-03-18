#include<iostream> 
using namespace std;
const int MAX_SIZE = 10; //���������� ��������� � ������� (�����)

struct my_stack //��������� ��������� ����
{
	int data[MAX_SIZE]; //������ � ����������� ��������� MAX_SIZE
	int last;           //��������� �� ������� �����
};
void push(my_stack& s, int x)//��������� ���������� ��������
{
	if (s.last == MAX_SIZE) { //��������� � ������������ ����� cout<<"Stack Overflow";
		return;
	} s.data[s.last++] = x;
}
int pop(my_stack& s) //��������� �������� � ������� �����
{
	return s.data[--s.last];//���������� ������� � ������� �����
}

int main()
{
	my_stack a; a.last = 0; 
	push(a, 3);
	push(a, 6);
	push(a, 2);
	cout << pop(a) << " ";//��������� ������� 2 cout<<pop(a)<<" ";//��������� ������� 6 cout<<pop(a)<<" ";//��������� ������� 3 return 0;
}
