#include <bits/stdc++.h>

using namespace std;


struct node {
    int par;
    int height = 0;
    bool visited = false;
    // bool autostrada = false;
    vector<int> children;
};

void change(int index, vector<node*> &ptr) {
    node* Node = ptr[index];

    Node->height--;
    // Node->autostrada ^= 1;

    for (int child : Node->children) {
        node* chil = ptr[child];
        // // to robimy tylko pod zmienionym na prośbę węzłem
        // ptr[child]->par = Node->par;
        // ptr[child]->height--;

        change(child, ptr);
    }
}

int query(int index, const vector<node*> &ptr) {
    return ptr[index]->height;

    // while (Node->par != 0) {
    //     if (!Node->autostrada) {
    //         suma++;
    //     }
    //     Node = ptr[Node->par];

    //     // // a co jeśli pytany index ma autostradę, musimy dać jeszcze check i jeśli nie ma autostrady
    //     // if (Node->par != 1) {
    //     //     query(Node->par, ptr, suma);
    //     // }
    // }
}

// a < b (a jest par b)
void construct(int a, int b, vector<node*> &ptr) {
    // a ma kolejne dziecko: b
    node *par = ptr[a];
    node *child = ptr[b];
    ptr[a]->children.push_back(b);

    // ojcem b jest a
    ptr[b]->par = a;
    // wystarczy ptr
}


void set_height(node *Node, vector<node*> &ptr) {
    for (int child_index : Node->children) {
        node *child = ptr[child_index];
        if (!child->visited) {
            child->height = ptr[child->par]->height;
            child->height++;
            child->visited = true;

            set_height(child, ptr);
        }
    }
}


int main() {
    int n;
    cin >> n;

    // vector<int> wynik;

    std::vector<node*> ptr;
    
    for (int i = 0; i <= n; i++) {
        ptr.push_back(new node());
    }

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;

        construct(a, b, ptr);
    }
    set_height(ptr[1], ptr);
    int m;
    cin >> m;

    for (int i = 0; i < n + m-1; i++) {
        char L;

        cin >> L;

        if (L == 'A') {
            cin >> a >> b;
            
            node* Node = ptr[b];

            for (int child : Node->children) {
                ptr[child]->par = Node->par;
            }

            change(b, ptr);
        }
        else {
            cin >> a;
            cout << query(a, ptr) << endl;
            // wynik.push_back(query(a, ptr));
        }
    }
    // for (int i = 0; i < wynik.size(); i++) {
    //     if (wynik[i] != out[i]) {
    //         cout << "ŹLE wiersz: " << i+1 << endl;
    //     }
    //     else {
    //         cout << "dobrze!" << endl;
    //     }
    // }
    // for (int i : wynik) {cout << i << " ";} cout << endl;
    // for (int i : out) {cout << i << " ";} 
    // cout << endl;
}