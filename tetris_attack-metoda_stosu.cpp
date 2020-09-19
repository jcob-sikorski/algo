#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;


struct node {
    //fields
    int data;
    node *next;
};


class linked_list {
    private:
    // initialization
    node *head = new node();
    node *tail = new node();

    public:
    // public constructor - without public, I wouldn't have a way to create linked_list
    linked_list () {
        head = NULL;
        tail = NULL;
    }

    void insert_start(int value) {
        node *temp = new node();

        node *copy = new node();

        temp->data=value;
        temp->next=head;
        head = temp;
    }


    void insert_end(int value) {
        node *temp = new node(); 

        // To access members of a structure (node) 
        // through a pointer (temp), use the arrow operator.
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head=temp;
            tail=temp;
            temp=NULL;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }


    void insert_index(int index, int value) {
        node *pre = new node();
        node *cur = new node();
        node *temp = new node();

        cur = head;

        for (int i = 0; i < index; i++) {
            pre = cur;
            cur = cur->next;
        }

        temp->data = value;
        pre->next = temp;
        temp->next = cur;
    }


    void delete_first() {
        node *temp = new node();

        temp = head;
        head = head->next;
        delete temp;
    }


    void delete_last() {
        node *pre = new node();
        node *cur = new node();

        cur = head;

        while(cur->next != NULL) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        tail = pre;
        delete cur;
    }


    void delete_node(node *n) {
            node *pre = new node();
            node *cur = new node();
            cur = head;

            while(cur->next != NULL && cur != n) {
                pre = cur;
                cur = cur->next;
            }

            pre->next = cur->next;
            if (cur == head) {
                head = cur->next;
            }
            else if (cur == tail) {
                tail = pre;
            }

            delete cur;
            display_nodes();
    }


    void delete_by_data(int data) {
            node *pre = new node();
            node *cur = new node();
            cur = head;


            while(cur->next != NULL && cur->data != data) {
                pre = cur;
                cur = cur->next;
            }


            pre->next = cur->next;
            if (cur == head) {
                head = cur->next;
            }
            else if (cur == tail) {
                tail = pre;
            }


            delete cur;
            display_nodes();
    }
    

    void delete_index(int index) {
        node *pre = new node();
        node *cur = new node();

        cur = head;
        
        for (int i = 0; i < index; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }


    void display_nodes() {
        node *temp = new node();
        temp = head;

        while (temp->next != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << temp->data << endl;
        cout << endl << endl;
    }


    linked_list split_index(int index) {
        node *pre = new node();
        node *cur = new node();

        node *nd_head = new node();
        cur = head;

        for (int i = 0; i < index; i++) {
            pre=cur;
            cur=cur->next;
        }
        linked_list obj;

        nd_head = cur;

        obj.set_head(nd_head);
        obj.set_tail(tail);

        pre->next = NULL;
        tail = pre;

        return obj;
    }


    void set_head(node *head) {
        this->head = head;
    }
    void set_tail(node *tail) {
        this->tail = tail;
    }


    node* return_head() {
        return head;
    }
    node* return_tail() {
        return tail;
    }


    static bool by_data(node *a, node *b) { 
        return (a->data < b->data); 
    }


    void tetris_attack() {
        node *t = new node();
        node *h = new node();

        node *pre = new node();
        node *cur = new node();

        h = head;

        pre = h->next;
        
        if (pre->next != NULL) {
            cur = pre->next;
            t = cur->next;
        }

        int wynik = 0;
        while (t->next != NULL) {
            int counter = 0;
            if (h != t) {
                vector<node*> potential_inv {h, pre, cur, t};

                sort(potential_inv.begin(), potential_inv.end(), linked_list::by_data);

                for (node* a : potential_inv) {
                    cout << a->data << "  ";
                }
                cout << endl;


                node *temp = new node();
                int i = 0;

                bool altered = false;

                while(i < 3) {
                    temp = potential_inv.at(i);
                    if (temp->data == potential_inv.at(i+1)->data) {
                        int data1 = temp->data;
                        int data2 = temp->next->data;
                        
                        for (int j = 0; j < 2; j++) {
                            delete_by_data(data1);
                            delete_by_data(data2);
                            altered=true;
                        }
                        i++;
                    }
                    i++;
                }
                if (!altered) {
                    h = h->next;
                    pre = h->next;
                    cur = pre->next;
                    t = cur->next;
                } else {
                    linked_list::tetris_attack();
                    cout << wynik << endl;
                }
            }
            display_nodes();
        }
        return wynik;
    }


    //node* clone() const { return new node(*this); }
};


// https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr


// tworzymy rekursywną funkcję, która dzieli 2 stosy(linked_lists) na kolejną połowę jesli ich wielkość się zmieniła i nie znaleziono
// żadnych par inwersji - jeśli znaleziono - mergujemy stosy i dzielimy je na połowę
// warunkiem zakończenia funcji jest przypadek, w którym stosy mają wielkość 0
// pozostaje tylko pytanie, czy linked_list jest w stanie zapewnić akcje, których potrzebuje owa funkcja
// dlaczego nie stos? stosu się nie da podzielić na połowę, tak aby jego góra była "sąsiadem" góry 2 stosu
// "góra" w tym algorytmie jest reprezentacją środka ciągu


int main()
{
    vector<int> arr = {5, 2, 3, 1, 4, 1, 4, 3, 5, 2};
    // example
    linked_list obj;

    for (int i = 0; i < arr.size(); i++) {
        obj.insert_end(arr.at(i));
    }

	//obj.insert_end(25);
	//obj.insert_end(50);
	//obj.insert_end(90);
	//obj.insert_end(40);
    //obj.insert_end(100);

    obj.display_nodes();

    obj.tetris_attack();

	system("pause");
	return 0;
}