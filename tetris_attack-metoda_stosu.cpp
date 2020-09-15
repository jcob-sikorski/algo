#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;




// maybe I have to use shared_pointer instead of a unique one?







struct node {
    // we can have indefinite amounts and types of data

    //fields
    int data;
    node *next;
    //node *next;
};

class linked_list {
    private:
    // smart pointer with wrapper around it
    // initialization
    node *head = new node();
    node *tail = new node();
    //node *head, *tail;

    public:
    // public constructor - without public, I wouldn't have a way to create linked_list
    linked_list () {
        head = NULL;
        tail = NULL;
    }


    void create_node(int value) {
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

    void insert_start(int value) {
        node *temp = new node();

        node *copy = new node();

        temp->data=value;
        head = temp;
        
        temp->next=head;
        *head=*temp;

        cout << "next node after head is 50 " << endl;
        cout << "the next node after head really is: " << head->next->data << endl;
    }

    void insert_end(int value) {
        node *temp = new node();
        temp->data = value;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }


    void insert_position(int pos, int value) {
        node *pre = new node();
        node *cur = new node();
        node *temp = new node();

        cur = head;

        for (int i = 1; i < pos; i++) {
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
        tail = pre;
        delete cur;
    }


    void delete_position(int pos) {
        node *pre = new node();
        node *cur = new node();

        cur = head;
        
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }


    //void split_position() {
    //    
    //}
    

    void display_nodes() {
        node *temp = new node();
        //node *temp=new node;
        //temp=head;
        //while(temp!=NULL)
        //{
        //  cout<<temp->data<<"\t";
        //  temp=temp->next;
        //}
        temp = head;

        while (temp->next != NULL) {
            cout << temp->data << endl;
            *temp = *head->next;
        }
        cout << temp->data << endl;
    }
};
// https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr


// tworzymy rekursywną funkcję, która dzieli 2 stosy na kolejną połowę jesli ich wielkość się zmieniła i nie znaleziono
// żadnych par inwersji - jeśli znaleziono - mergujemy stosy i dzielimy je na połowę
// warunkiem zakończenia funcji jest przypadek, w którym stosy mają wielkość 0
// pozostaje tylko pytanie, czy linked_list jest w stanie zapewnić akcje, których potrzebuje owa funkcja
// dlaczego nie stos? stosu się nie da podzielić na połowę, tak aby jego góra była "sąsiadem" góry 2 stosu
// "góra" w tym algorytmie jest reprezentacją środka ciągu


int main()
{
    linked_list obj;
	obj.create_node(25);
	obj.create_node(50);
	obj.create_node(90);
	obj.create_node(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.create_node(55);
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60);
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
	obj.delete_position(4);
	obj.display_nodes();
	cout<<"\n--------------------------------------------------\n";
	system("pause");
	return 0;
}