#include <list>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int BFS(unordered_map<int, vector<int>> graph, int startVertex, int N) {
    vector<bool> visited = vector<bool>(N);

    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    list<int> queue;

    queue.push_back(startVertex);

    while (!queue.empty()) {
        cout << "Visited " << queue.front() << " ";
        visited[queue.front()] = true;

        for (int vertex : graph[queue.front()]) {
            if (!visited[vertex]) {
                queue.push_back(vertex);
            }
        }
        queue.pop_front();
    }
    return 0;
}