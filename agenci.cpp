#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <deque>

using namespace std;


class Graph {

private:
    int N;
    unordered_map<int, vector<int>> graph;

public:

    void corr(pair<int, int> p) {
        if (graph.find(p.first) == graph.end()) {
            graph[p.first] = vector<int>();
        }
        graph[p.first].push_back(p.second);
        N++;
    }



    int BFS(int startx, int starty) {
        // Create a queue for BFS
        deque<pair<int, int>> qx;
        qx.push_back(make_pair(0, startx));
        deque<pair<int, int>> qy;
        qy.push_back(make_pair(0, starty));

        int counter;

        int state = 1;

        list<pair<int, int>> paths_x;
        list<pair<int, int>> paths_y;

        while (!qx.empty()) {
            if (state) {
                pair<int, int> path = qx.front();
                // Dequeue a vertex from queue
                int s = path.second;
                qx.pop_front();

                // Get all adjacent vertices of the dequeued
                // vertex
                cout << s << ": ";


                for (int v: graph[s]) {
                    pair<int, int> new_path = make_pair(path.first+1, v);
                    cout << v << " ";
                    qx.push_back(new_path);

                    paths_x.push_back(new_path);
                }
                cout << endl;
                state = 0;
            }
            else {
                pair<int, int> path = qy.front();
                // Dequeue a vertex from queue
                int s = path.second;
                qy.pop_front();

                // Get all adjacent vertices of the dequeued
                // vertex
                cout << "             " << s << ": ";


                for (int v: graph[s]) {
                    pair<int, int> new_path = make_pair(path.first+1, v);
                    cout << v << " ";
                    qy.push_back(new_path);

                    paths_y.push_back(new_path);
                }
                cout << endl;

                if (!qx.empty() && !qy.empty()) {
                    list<pair<int, int>> intersection;

                    set_intersection(
                        paths_x.begin(), paths_x.end(),
                        paths_y.begin(), paths_y.end(), back_inserter(intersection)
                        );

                    if (!intersection.empty()) {
                        for (auto i : intersection) {
                            counter = i.first;
                            goto end;
                        }
                    }
                }
                state = 1;
            }
        }

        end:
        return counter;
    }

    void display() {
        for (auto kv : graph) {
            cout << kv.first << "   ";
            for (int i : kv.second) {
                cout << i << " ";
            }
            cout << endl;
        }
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

    graph.display();
    
    cout << graph.BFS(x, y) << endl;
    return 0;
}