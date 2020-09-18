#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <memory>

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
    // example
    linked_list obj;
	obj.insert_end(25);
	obj.insert_end(50);
	obj.insert_end(90);
	obj.insert_end(40);
    obj.insert_end(100);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display_nodes();

    linked_list nd;

    nd = obj.split_index(2);

    cout << "obj tail " << obj.return_tail()->data << "nd head " << nd.return_head()->data << endl;

	system("pause");
	return 0;
}