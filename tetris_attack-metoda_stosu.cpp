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
    unique_ptr<node> next;
    //node *next;
};

class linked_list {
    private:
    // smart pointer with wrapper around it
    // initialization
    unique_ptr<node> head = make_unique<node>();
    unique_ptr<node> tail = make_unique<node>();
    //node *head, *tail;

    public:
    // public constructor - without public, I wouldn't have a way to create linked_list
    linked_list () {
        head = NULL;
        tail = NULL;
    }


    void create_node(int value) {
        unique_ptr<node> temp = make_unique<node>(); 
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
        unique_ptr<node> temp = make_unique<node>();
        temp->data=value;
        temp->next=head;
        head=temp;
    }

    void insert_end(int value) {
        unique_ptr<node> temp = make_unique<node>();
        temp->data = value;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }


    void insert_position(int pos, int value) {
        unique_ptr<node> pre = make_unique<node>();
        unique_ptr<node> cur = make_unique<node>();
        unique_ptr<node> temp = make_unique<node>();

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
        unique_ptr<node> temp = make_unique<node>();

        temp = head;
        head = head->next;
        delete temp;
    }

    void delete_last() {
        unique_ptr<node> pre = make_unique<node>();
        unique_ptr<node> cur = make_unique<node>();

        cur = head;

        while(cur->next != NULL) {
            pre = cur;
            cur = cur->next;
        }
        tail = pre;
        delete cur;
    }


    void delete_position(int pos) {
        unique_ptr<node> pre = make_unique<node>();
        unique_ptr<node> cur = make_unique<node>();

        cur = head;
        
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }


    void display_nodes() {
        unique_ptr<node> temp = make_unique<node>();
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
        }
    }
}
// https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr


// tworzymy rekursywną funkcję, która dzieli 2 stosy na kolejną połowę jesli ich wielkość się zmieniła i nie znaleziono
// żadnych par inwersji - jeśli znaleziono - mergujemy stosy i dzielimy je na połowę
// warunkiem zakończenia funcji jest przypadek, w którym stosy mają wielkość 0
// pozostaje tylko pytanie, czy linked_list jest w stanie zapewnić akcje, których potrzebuje owa funkcja
// dlaczego nie stos? stosu się nie da podzielić na połowę, tak aby jego góra była "sąsiadem" góry 2 stosu
// "góra" w tym algorytmie jest reprezentacją środka ciągu


int main()
{
	list obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	system("pause");
	return 0;
}