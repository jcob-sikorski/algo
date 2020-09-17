#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;


struct node {
    // we can have indefinite amounts and types of data

    //fields
    int data;
    node *next;
};

class linked_list {
    private:
    // smart pointer with wrapper around it
    // initialization
    node *head = new node();
    node *tail = new node();
    int size = 0;

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

        size++;
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

        size++;
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

        size++;
    }

    void delete_first() {
        node *temp = new node();

        temp = head;
        head = head->next;
        delete temp;

        size--;
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

        size--;
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

        size--;
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

    node split_index(int index, node ahead) {
        node *pre = new node;
        node *cur = new node;
    
        node *bhead = new node;
        cur = ahead;
    
        for (int i = 0; i < index; i++) {
            pre=cur;
            cur=cur->next;
        }
        pre->next = NULL;
        bhead = cur;
        return ahead, bhead;
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
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_end(55);
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_index(5,60);
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_index(4);
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	system("pause");
	return 0;
}