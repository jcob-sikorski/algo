#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <algorithm>

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
        if (graph.find(p.first) == graph.end()) {
            graph[p.first] = vector<int>();
        }
        graph[p.first].push_back(p.second);
        N++;
    }


    //void BFS_util();

    //void BFS(int start) {
    //    // Create a queue for BFS
    //    list<int> queue;
    //    queue.push_back(start);
    //
    //    while(!queue.empty()) {
    //        // Dequeue a vertex from queue
    //        int s = queue.front();
    //        cout << s << endl;
    //        queue.pop_front();
    //
    //        // Get all adjacent vertices of the dequeued
    //        // vertex
    //        for (int v: graph[s]) {
    //            queue.push_back(v);
    //        }
    //    }
    //}


    //void BFS(int start) {
    //    // Create a queue for BFS
    //    list<int> queue;
    //    queue.push_back(start);
    //
    //    while(!queue.empty()) {
    //        // Dequeue a vertex from queue
    //        int s = queue.front();
    //        //cout << s << endl;
    //        queue.pop_front();
    //
    //        // Get all adjacent vertices of the dequeued
    //        // vertex
    //        cout << s << ": ";
    //        for (int v: graph[s]) {
    //            cout << v << " ";
    //            queue.push_back(v);
    //        }
    //        cout << endl;
    //    }
    //}


    void BFS(int start) {
        // Create a queue for BFS
        list<int> queue;
        queue.push_back(start);
        int state = 0;

        set<int> x_neigh;
        set<int> y_neigh;
        while (!qx.empty() && !qy.empty() && qx.front() != qy.front()) {
            if (state) {
                // Dequeue a vertex from queue
                int s = qx.front();
                qx.pop_front();

                // Get all adjacent vertices of the dequeued
                // vertex
                cout << s << ": ";
                
                for (int v: graph[s]) {
                    cout << v << " ";
                    qx.push_back(v);

                    x_neigh.insert(v);
                }
                cout << endl;
                state = 1;
            }
            else {
                // Dequeue a vertex from queue
                int s = qy.front();
                qy.pop_front();

                // Get all adjacent vertices of the dequeued
                // vertex

                cout << s << ": ";
                for (int v: graph[s]) {
                    cout << v << " ";
                    qy.push_back(v);

                    y_neigh.insert(v);
                }
                cout << endl;

                // https://stackoverflow.com/questions/29419922/fastest-way-to-find-out-if-two-sets-overlap
                if (set_intersection(x_neigh.begin(),x_neigh.end(),y_neigh.begin(),y_neigh.end());
                //, std::inserter(,intersect.begin()));
                state = 0;
            }
        }
    }


    void setx(int x) {
        // set start pos of x
        currx = x;
    }
    void sety(int y) {
        // set start position of y
        curry = y;
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

    graph.setx(x);
    graph.sety(y);

    graph.display();
    
    graph.BFS(4);
    //graph.BFS(x, y);
    return 0;
}