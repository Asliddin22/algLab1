#include <iostream>
#include <climits>
#define perm(i,j);

using namespace std;

class  DeiksterAlgoSolution {
public:
    static const int V = 6;

    void Permutation(int* perm) {
        const int n = 4;
        int i = 0, j = 0;
        int temp = perm[j];
        perm[j] = perm[i];
        perm[i] = temp;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                while (--i >= 0 && perm[i] > perm[i + 1]);
        if (i == -1)
            return;
        for (int j = i + 1, k = n - 1; j < k; j++, k--)
            perm(j, k);
        while (perm[i] < perm[j])
            j++;
        perm(i, j);
    }

    void Dijkstra(int GR[V][V], int st) {
        int distance[V], count, index, i, u, m = st + 1;
        bool visited[V];
        for (i = 0; i < V; i++) {
            distance[i] = INT_MAX;
            visited[i] = false;
        }
        distance[st] = 0;
        for (count = 0; count < V - 1; count++) {
            int min = INT_MAX;
            for (i = 0; i < V; i++)
                if (!visited[i] && distance[i] <= min) {
                    min = distance[i];
                    index = i;
                }
            u = index;
            visited[u] = true;
            for (i = 0; i < V; i++)
                if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
                    distance[u] + GR[u][i] < distance[i])
                    distance[i] = distance[u] + GR[u][i];
        }
        cout << "Стоимость пути из начальной вершины до остальных:\t\n";
        for (i = 0; i < V; i++)
            if (distance[i] != INT_MAX)
                cout << m << " > " << i + 1 << " = " << distance[i] << endl;
            else
                cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    int start, GR[DeiksterAlgoSolution::V][DeiksterAlgoSolution::V] = {
        {0, 1, 4, 0, 2, 0},
        {0, 0, 0, 9, 0, 0},
        {4, 0, 0, 7, 0, 0},
        {0, 9, 7, 0, 0, 2},
        {0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 0} };
    cout << "Начальная вершина >> ";
    cin >> start;

    DeiksterAlgoSolution deikstrAlgo;
    deikstrAlgo.Dijkstra(GR, start - 1);

    system("pause");
    return 0;
}
