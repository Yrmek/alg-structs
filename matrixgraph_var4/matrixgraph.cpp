#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Graf
{
    int numVertices;
    bool** adjMatrix;

    Graf(int n)
    {
        numVertices = n;
        adjMatrix = new bool* [n];
        for (int i = 0; i < n; i++)
            adjMatrix[i] = new bool[n] { false };
    }

    ~Graf()
    {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }

    void addEdge(int v1, int v2)
    {
        adjMatrix[v1][v2] = true;
      
    }

    void removeEdge(int v1, int v2)
    {
        adjMatrix[v1][v2] = false;
        adjMatrix[v2][v1] = false;
    }

    void removeTop(int key)
    {
        for (int i = 0; i < this->numVertices; ++i) {
            adjMatrix[key][i] = false;
            adjMatrix[i][key] = false;
        }
    }

    void dfs(int startKey, bool* visited)
    {
        visited[startKey] = true;
        cout << "Посещена вершина " << startKey << endl;

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[startKey][i] && !visited[i])
                dfs(i, visited);
        }
    }

    void bfs(int startKey)
    {
        bool* visited = new bool[numVertices] { false };
        queue<int> q;
        visited[startKey] = true;
        q.push(startKey);

        while (!q.empty())
        {
            int currentKey = q.front();
            q.pop();
            cout << "Посещена вершина " << currentKey << endl;

            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currentKey][i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
    }

    bool dfsFindPath(int startKey, int endKey, bool* visited)
    {
        visited[startKey] = true;

        if (startKey == endKey)
        {
            cout << startKey << " ";
            return true;
        }

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[startKey][i] && !visited[i])
            {
                if (dfsFindPath(i, endKey, visited))
                {
                    cout << startKey << " ";
                    return true;
                }
            }
        }

        return false;
    }

    bool findSimplePathUsingDFS(int startKey, int endKey)
    {
        bool* visited = new bool[numVertices] { false };
        if (!dfsFindPath(startKey, endKey, visited))
        {
            cout << "Простой путь между вершинами " << startKey << " и " << endKey << " не найден." << endl;
            delete[] visited;
            return false;
        }
        else
        {
            cout << "Путь найден" << endl;
            delete[] visited;
            return true;
        }
    }

    void printGraph()
    {
        cout << "Граф:" << endl;
        for (int i = 0; i < this->numVertices; i++)
        {
            for (int j = 0; j < this->numVertices; j++)
            {
                cout << this->adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    setlocale(LC_ALL, "");
    Graf* graf = new Graf(7);

    graf->addEdge(0, 1);
    graf->addEdge(0, 2);
    graf->addEdge(1, 3);
    graf->addEdge(3, 4);
    graf->addEdge(2, 3);
    graf->addEdge(0, 6);
    graf->addEdge(6, 4);

    graf->printGraph();

    cout << "Обход в глубину, начиная с вершины 0:" << endl;
    bool* visited = new bool[graf->numVertices] { false };
    graf->dfs(0, visited);
    delete[] visited;

    cout << "Обход в ширину, начиная с вершины 0:" << endl;
    graf->bfs(0);

    cout << "Поиск пути между вершинами 0 и 4:" << endl;
    if (!graf->findSimplePathUsingDFS(0, 4))
    {
        graf->addEdge(0, 4);
    }

    cout << "Поиск пути между вершинами 1 и 2:" << endl;
    if (!graf->findSimplePathUsingDFS(1, 2))
    {
        graf->addEdge(0, 5);
    }


    graf->removeEdge(1, 3);

    cout << "Граф после удаления ребра (1, 3):" << endl;
    graf->printGraph();

    graf->removeTop(3);
    cout << "Граф после удаления вершины 3:" << endl;
    graf->printGraph();

    delete graf;
    return 0;
}