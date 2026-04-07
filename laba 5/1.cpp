#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void addStart(Node*& head, int x) {
    head = new Node{x, head};
}

void addEnd(Node*& head, int x) {
    Node* n = new Node{x, NULL};
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

double avg(Node* head) {
    int sum = 0, k = 0;
    while (head) {
        sum += head->data;
        k++;
        head = head->next;
    }
    return (double)sum / k;
}

void deleteFirstEven(Node*& head) {
    if (!head) return;

    if (head->data % 2 == 0) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }

    Node* t = head;
    while (t->next && t->next->data % 2 != 0)
        t = t->next;

    if (t->next) {
        Node* d = t->next;
        t->next = d->next;
        delete d;
    }
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void clear(Node*& head) {
    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
}

int main() {
    Node* head = NULL;

    addStart(head, 5);
    addEnd(head, 10);
    addEnd(head, 15);
    addEnd(head, 7);

    print(head);

    cout << "Average: " << avg(head) << endl;

    deleteFirstEven(head);
    print(head);

    clear(head);

    return 0;
}