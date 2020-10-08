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
        if (graph.find(p.first) == graph.end()) {
            graph[p.first] = vector<int>();
        }
        graph[p.first].push_back(p.second);
        N++;
    }


    int BFS(int x, int y) {
        vector<int> visx = vector<int>(N, false);
        vector<int> visy = vector<int>(N, false);

        list<int> queuex;
        list<int> queuey;

        queuex.push_back(x);
        queuey.push_back(y);

        char bit = 'x';

        int counter = 0;

        while (!queuex.empty() || !queuey.empty()) {
            if (x == y) {
                return counter;
            }

            if (bit == 'x') {
                cout << "X" << queuex.front() << "  ";

                visx[queuex.front()] = true;

                for (int vertex : graph[queuex.front()]) {
                    //if (!visx[vertex]) {
                        queuex.push_back(vertex);
                        //visx[vertex] = true;
                    //}
                }
                queuex.pop_front();
                x = queuex.front();
                bit = 'y';
            }
            else {
                cout << "Y" << queuey.front() << "  ";

                visy[queuey.front()] = true;

                for (int vertex : graph[queuey.front()]) {
                    //if (!visy[vertex]) {
                        queuey.push_back(vertex);
                        //visy[vertex] = true;
                    //}
                }
                queuey.pop_front();
                y = queuey.front();
                bit = 'x';
                counter++;
            }
        }
        //X1  Y5  X2  Y4  X3  Y6  X4  Y1  X5  Y2  X6
        //X1  Y5  X2  Y4  X3  Y6  X4  Y1  X5  Y2  X6  Y3
        cout << "                   " << counter << endl;
        return 0;
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
    
    graph.BFS(x, y);
    return 0;
}