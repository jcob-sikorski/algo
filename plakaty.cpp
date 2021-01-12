// podczas tworzenia drzewa ustalamy korzeń, 
// jeśli dzieci są takie same i sąsiadują to sklej je (uaktualnij range)
// jeśli dzieci są takie same i nie sąsiadują to                ??????????????????????

// podczas propagacji w górę ojciec zamienia dziecko w +inf

// potem, jeśli dziecko jest takie same jak ojciec idź w tą ściężkę i zamień każde z potomków dziecka na +inf

#include <bits/stdc++.h>

using namespace std;

// billboard representation
struct node {
    int val;

    // czy x, y jest potrzebne do zdeterminowania kto jest lewym a kto lewym synem? (to   )
    int x, y;

    bool l, r = false;

    node* parent = NULL;
}


// creates tree
vector<node*> createTree(const vector<int> &arr) {
    // create 1 based tree
    vector<node*> tree;

    int base = 1;
    int treeSize = arr.size();

    while (base < treeSize) {
        base *= 2;
    }

    tree.resize(2*base);
    
    // for each value in arr update tree
    for (int i = 0; i < arr.size(); i++) {
        node* Node = new node();
        tree[base+i] = Node;
    }

    // for each value in arr update l, r values
    // if neighbour is taller 
    // then
    // update l/r to true

    // trzeba zrobić check na base bounds
    for (int i = 0; i < arr.size(); i++) {
        node Node = tree[base+i];

        // set coordinates
        Node.x = i; Node.y = i;

        // l
        if (tree[base+i-1]->val >= Node->val){
            tree[base+i]->l = true;
        }
        // r
        if (tree[base+i+1]->val >= Node->val){
            tree[base+i]->r = true;
        }
    }
    return tree;
}

void propagate(int index, vector<node*> tree) {
    node* Node = tree[index];

    // if node isn't root
    if (Node->parent == NULL) {
        // next action
        return;
    }

    // if nodes are both equal
    if (tree[index*2]->val == tree[index*2+1]->val) {
        // create future parent which will change current parent
        node* new_parent = new Node();

        // check if both children can be connected
        if (tree[index*2].r && tree[index*2+1]->l) {
            // merge external: 

            // bool heights
            new_parent->l = tree[index*2]->l;
            new_parent->r = tree[index*2+1]->r;

            // range coordinates
            new_parent->x = tree[index*2]->x;
            new_parent->y = tree[index*2+1]->y;
        }
        // if can't, select left child as parent and delete it
        else {
            
        }

        tree[index/2] = new_parent;
    }

    tree[index] = min(tree[index*2]->val, tree[index*2+1]->val)
}




void update(int x, int val, int base, vector<int> &tree) {
    // init x and y as leaves in tree
    x += base - 1;

    tree[x] = val;

    // while y and x don't have common parent
    while (x != 1) {
        
        tree[x] = min(tree[2*x], tree[2*x+1]);

        // jump to parent
        x /= 2;
    }
}