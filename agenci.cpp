#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
#include <sstream>

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


    void BFS(int startx, int starty) {

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
                // cout << s << ": ";


                for (int v: graph[s]) {
                    pair<int, int> new_path = make_pair(path.first+1, v);
                    // cout << v << " ";
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
                // cout << "             " << s << ": ";


                for (int v: graph[s]) {
                    pair<int, int> new_path = make_pair(path.first+1, v);
                    // cout << v << " ";
                    qy.push_back(new_path);

                    paths_y.push_back(new_path);
                }
                // cout << endl;

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
                else {
                    cout << "NIE" << endl;
                }
                state = 1;
            }
        }

        end:
        cout << counter << endl;
    }

    // void display() {
        // for (auto kv : graph) {
            // cout << kv.first << "   ";
            // for (int i : kv.second) {
                // cout << i << " ";
            // }
            // cout << endl;
        // }
    // }
};


int main() {

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    int x, y;

    cin >> n >> m;
    cin >> x >> y;

    Graph graph;

    // for two lines
	for(int i = 0; i < m; ++i) {
        string str;

		if(getline(cin, str)) {
			istringstream sstr(str);
			int a, b;

			while(sstr >> a >> b) {
                graph.corr(make_pair(a, b));
			}
		}
  	}
    graph.BFS(x, y);
    return 0;
}