//Выберите подходящий тип данных для представления графа
//Напишите и протестируйте процедуры, обеспечивающие:
//добавление вершины в граф
//удаление вершины из графа
//вывод элементов графа на экран
//обход вершин графа в глубину
//обход вершин графа в ширину
//Входные параметры, задающие граф, необходимо считывать из файла.
//Выполните задание согласно вашему варианту :
//4. Для двух выделенных вершин графа постройте соединяющий их простой путь.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct RelNode
{
	int key;
	RelNode* next;
};

struct Graf
{
	int topkey;
	RelNode* relNodes;
	Graf* next;
};

void addTop(Graf*& graf, int topkey)
{
	Graf* newtop = new Graf;
	Graf* buf = graf;
	newtop->topkey = topkey;
	newtop->relNodes = NULL;
	newtop->next = NULL;
	if (!graf) {
		graf = newtop;
	}
	else{
		while (buf->next) {
			buf = buf->next;
		}
		buf->next = newtop;
	}
	int num= 0;
	cout << "Enter numbers of tied tops with top #" << topkey;

	while (cin >> num) {
		if (num == 0) break;
		RelNode* buff = new RelNode;
		buff->key = num;
		buff->next = nullptr;
		if (!newtop->relNodes) newtop->relNodes = buff;
		else {
			buff->next = newtop->relNodes;
			newtop->relNodes = buff;
		}
	}
}

void delTop(Graf*& graf, int topkey)
{
	Graf* buf = graf;
	Graf* prev = buf;
	Graf* delbuf;
	RelNode* pvv = buf->relNodes;
	RelNode* temp;
	while (buf) {
		temp = buf->relNodes;
		while (temp) {
			if (temp->key == topkey) {
				pvv->next = temp->next;
				delete[] temp;
				break;
			}
			pvv = temp;
			temp = temp->next;
		}
		if (buf->topkey == topkey) {
			while (buf->relNodes) {
				temp = buf->relNodes;
				buf->relNodes = buf->relNodes->next;
				delete[] temp;
			}
			prev->next = buf->next;
			delbuf = buf;
			delete[] delbuf;
			buf = prev;
		}
		prev = buf;
		buf = buf->next;
	}
}

void main()
{
	Graf* graf = NULL; 
	addTop(graf, 1);
	addTop(graf, 2);
	addTop(graf, 3);
	delTop(graf, 2);
}