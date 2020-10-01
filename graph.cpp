#include <vector>

using namespace std;

struct node {
    int number;
    vector<node*> neigh{};
}

class graph {

private:
    node *zero = new node();
    node *one = new node();

public:
    graph() {
        zero = NULL;
        tail = NULL;
    }

    void correlate(node *x, node *y) {
        x->neigh.push_back(y);
    }
    

}