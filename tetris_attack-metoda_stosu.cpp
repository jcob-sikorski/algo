#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

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
    }

    int delete_by_data_and_return_index(int data) {
            node *pre = new node();
            node *cur = new node();
            cur = head;

            int counter = 0;

            while(cur->next != NULL && cur->data != data) {
                pre = cur;
                cur = cur->next;
                counter++;
            }


            pre->next = cur->next;
            if (cur == head) {
                head = cur->next;
            }
            else if (cur == tail) {
                tail = pre;
            }


            delete cur;
            return counter;
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
        if (head != NULL) {
            temp = head;
        }

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
};


int main()
{
    vector<int> arr = {5, 2, 3, 1, 4, 1, 4, 3, 5, 2};

    unordered_set<int> dist;

    linked_list obj;

    int steps = 0;

    for (int i = 0; i < arr.size(); i++) {
        obj.insert_end(arr.at(i));

        obj.display_nodes();

        if (dist.find(obj.return_tail()->data) == dist.end()) {
            dist.insert(obj.return_tail()->data);
        }
        else {
            int data = obj.return_tail()->data;

            int index1 = obj.delete_by_data_and_return_index(data);
            int index2 = obj.delete_by_data_and_return_index(data);

            steps += (abs(index1 - index2));
        }
    }
    cout << steps;

    return 0;
}