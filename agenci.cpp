#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>

using namespace std;


class Graph {

private:
    int N;
    unordered_map<int, vector<int>> graph;
    int currx;
    int curry;

    vector<int> xy{currx, curry};

    int counter = 0;

public:

    void corr(pair<int, int> p) {
        if (graph.find(p.first) != graph.end()) {
            graph[p.first] = vector<int>();
        }
        graph[p.first].push_back(p.second);
        N++;
    }


    // BFS algorithm
    int BFS(int startVertex, int id) {
        vector<bool> visited = vector<bool>(N);

        for (int i = 0; i < N; i++) {
            visited[i] = false;
        }

        list<int> queue;

        visited[startVertex] = true;
        queue.push_back(startVertex);

        list<int>::iterator i;

        while (!queue.empty()) {
            xy.at(id) = queue.front();
            cout << "Visited " << queue.front() << " ";
            queue.pop_front();
            counter++;

            if (xy[0] == xy[1]) {
                return counter;
            }


            for (int vertex : graph[startVertex]) {
                if (!visited[vertex]) {
                    visited[vertex] = true;
                    queue.push_back(vertex);
                }
            }
        }
        return 0;
    }

    void setx(int x) {
        currx = x;
    }
    void sety(int y) {
        curry = y;
    }
};


int main() {
    int n = 6;
    int m = 7;
    
    int x = 1;
    int y = 5;

    vector<pair<int, int>> x_y{make_pair(1,2),make_pair(4,5),make_pair(2,3),
        make_pair(3,4),make_pair(4,1),make_pair(5,4),make_pair(5,6)};
    
    Graph graph;

    for (int i = 0; i < m; i++) {
        graph.corr(x_y.at(i));
    }

    graph.setx(x);
    graph.sety(y);
    
    graph.BFS(x, 0);
    graph.BFS(y, 1);

    return 0;
}