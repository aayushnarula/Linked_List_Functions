#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *link;
};
Node *head = NULL;
int insert_beg() {
    int value;
    cin >> value;
    Node *n = new Node();
    n->data = value;
    n->link = head;
    head = n;
}
int insert_end() {
    int value;
    cin >> value;
    Node *n = new Node();
    n->data = value;
    n->link = NULL;
    if (head == NULL) {
        head = n;
    } else {
        Node *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = n;
    }
}
int delete_beg() {
    if (head == NULL) {
        cout << "list is empty" << endl;
    } else {
        Node *temp = head;
        head = temp->link;
        free(temp);
    }
}
void delete_end() {
    Node *ptr;
    if (head == NULL)
        cout << "EMPTY LIST\n";
    if (head->link == NULL) {
        ptr = head;
        head = NULL;
        free(ptr);
    } else {
        Node *prev;
        ptr = head;
        while (ptr->link != NULL) {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
}
int middle_element() {
    Node *slow = head;
    Node *fast = head;
    if (head == NULL)
        cout << "List is Empty";
    else {
        while (fast != NULL && fast->link != NULL) {
            slow = slow->link;
            fast = fast->link->link;
        }
        cout << "Middle element is:" << slow->data;
    }
    cout << endl;
}
int reverse_list() {
    Node *p, *c, *n;
    p = NULL;
    c = head;
    while (c != NULL) {

        n = c->link;
        c->link = p;
        p = c;
        c = n;
    }
    head = p;
}
int display() {
    if (head == NULL) {
        cout << "list is empty" << endl;
    } else {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
}
int main() {
    int flag = 1;
    while (flag == 1) {
        cout<< "1)Insert_beg  2)Insert_end  3)delete_beg  4)delete_end  5)middle_element  6)reverse_list  7)display  8)Exit"<< endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                insert_beg();
                display();
                break;
            case 2:
                insert_end();
                display();
                break;
            case 3:
                delete_beg();
                display();
                break;
            case 4:
                delete_end();
                display();
                break;
            case 5:
                middle_element();
                display();
                break;
            case 6:
                reverse_list();
                display();
                break;
            case 7:
                display();
                break;
            case 8:
                flag = 0;
                break;
        }
    }
}
