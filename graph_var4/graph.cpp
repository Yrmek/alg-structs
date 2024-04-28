//�������� ���������� ��� ������ ��� ������������� �����
//�������� � ������������� ���������, ��������������:
//���������� ������� � ����
//�������� ������� �� �����
//����� ��������� ����� �� �����
//����� ������ ����� � �������
//����� ������ ����� � ������
//������� ���������, �������� ����, ���������� ��������� �� �����.
//��������� ������� �������� ������ �������� :
//4. ��� ���� ���������� ������ ����� ��������� ����������� �� ������� ����.

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

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
}

void addRelation(Graf*& graf, int key1, int key2)
{
	Graf* current = graf;
	Graf* node1 = nullptr;
	Graf* node2 = nullptr;

	// ������� ������� � ������� key1 � key2
	while (current)
	{
		if (current->topkey == key1)
			node1 = current;
		if (current->topkey == key2)
			node2 = current;

		current = current->next;
	}

	// ���������, ��� ��� ������� �������
	if (!node1 || !node2)
	{
		cout << "���� �� ������ �� �������." << endl;
		return;
	}

	// ��������� ����� ����� ���������
	RelNode* newRelNode1 = new RelNode;
	newRelNode1->key = key2;
	newRelNode1->next = node1->relNodes;
	node1->relNodes = newRelNode1;

	RelNode* newRelNode2 = new RelNode;
	newRelNode2->key = key1;
	newRelNode2->next = node2->relNodes;
	node2->relNodes = newRelNode2;

	cout << "��������� ��������� ����� ��������� " << key1 << " � " << key2 << endl;
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

void printGraph(Graf* graf)
{
	Graf* current = graf;
	while (current)
	{
		cout << "������� " << current->topkey << ": ";
		RelNode* relNode = current->relNodes;
		while (relNode)
		{
			cout << relNode->key << " ";
			relNode = relNode->next;
		}
		cout << endl;
		current = current->next;
	}
}

void dfs(Graf* graf, int startKey, bool* visited)
{
	Graf* current = graf;
	while (current && current->topkey != startKey)
		current = current->next;

	if (!current)
		return;

	visited[startKey] = true;
	cout << "�������� ������� " << startKey << endl;

	RelNode* relNode = current->relNodes;
	while (relNode)
	{
		if (!visited[relNode->key])
			dfs(graf, relNode->key, visited);
		relNode = relNode->next;
	}
}

void bfs(Graf* graf, int startKey)
{
	bool* visited = new bool[100] { false };
	queue<int> q;
	visited[startKey] = true;
	q.push(startKey);

	while (!q.empty())
	{
		int currentKey = q.front();
		q.pop();
		cout << "�������� ������� " << currentKey << endl;

		Graf* current = graf;
		while (current && current->topkey != currentKey)
			current = current->next;

		if (!current)
			continue;

		RelNode* relNode = current->relNodes;
		while (relNode)
		{
			if (!visited[relNode->key])
			{
				visited[relNode->key] = true;
				q.push(relNode->key);
			}
			relNode = relNode->next;
		}
	}

	delete[] visited;
}

bool dfsFindPath(Graf* graf, int startKey, int endKey, bool* visited)
{
	Graf* current = graf;
	while (current && current->topkey != startKey)
		current = current->next;

	if (!current)
		return false;

	visited[startKey] = true;

	if (startKey == endKey)
	{
		cout << startKey << " ";
		return true;
	}

	RelNode* relNode = current->relNodes;
	while (relNode)
	{
		if (!visited[relNode->key])
		{
			if (dfsFindPath(graf, relNode->key, endKey, visited))
			{
				cout << startKey << " ";
				return true;
			}
		}
		relNode = relNode->next;
	}

	return false;
}

bool findSimplePathUsingDFS(Graf* graf, int startKey, int endKey)
{
	bool* visited = new bool[100] { false };
	if (!dfsFindPath(graf, startKey, endKey, visited))
	{
		cout << "������� ���� ����� ��������� " << startKey << " � " << endKey << " �� ������." << endl;
		return false;
	}
	else {
		cout << "���� ������" << endl;
		return true;
	}
	delete[] visited;
}


void main()
{
	setlocale(LC_ALL, "");
	Graf* graf = NULL;
	addTop(graf, 1);
	addTop(graf, 2);
	addTop(graf, 3);
	addTop(graf, 4);
	addTop(graf, 5);
	addTop(graf, 6);

	// ��������� �������
	addRelation(graf, 1, 2);
	addRelation(graf, 1, 3);
	addRelation(graf, 2, 4);
	addRelation(graf, 3, 4);
	addRelation(graf, 4, 5);

	cout << "����:" << endl;
	printGraph(graf);

	cout << "����� � �������, ������� � ������� 1:" << endl;
	bool* visited = new bool[100] { false };
	dfs(graf, 1, visited);
	delete[] visited;

	cout << "����� � ������, ������� � ������� 1:" << endl;
	bfs(graf, 1);

	cout << "����� ���� ����� ��������� 1 � 5:" << endl;
	if (!findSimplePathUsingDFS(graf, 1, 5)) {
		addRelation(graf, 1, 5);
	}
	cout << "����� ���� ����� ��������� 1 � 6:" << endl;
	if (!findSimplePathUsingDFS(graf, 1, 6)) {
		addRelation(graf, 1, 6);
	}
	findSimplePathUsingDFS(graf, 1, 5);
	// �������� ������� 2
	delTop(graf, 2);

	cout << "���� ����� �������� ������� 2:" << endl;
	printGraph(graf);
}