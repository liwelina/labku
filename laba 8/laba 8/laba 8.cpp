#include <iostream>
#include <string>

using namespace std;

struct StackNode {
    int grade;
    StackNode* next;
};

void push(StackNode*& top, int v) {
    StackNode* n = new StackNode;
    n->grade = v;
    n->next = top;
    top = n;
}

void printStack(StackNode* top) {
    if (!top) {
        cout << "Stack empty" << endl;
        return;
    }
    StackNode* c = top;
    while (c) {
        cout << c->grade << " ";
        c = c->next;
    }
    cout << endl;
}

void avg(StackNode* top) {
    if (!top) return;
    double s = 0;
    int k = 0;
    StackNode* c = top;
    while (c) {
        s += c->grade;
        k++;
        c = c->next;
    }
    cout << "Average: " << (s / k) << endl;
}

void clearStack(StackNode*& top) {
    while (top) {
        StackNode* t = top;
        top = top->next;
        delete t;
    }
}

struct Course {
    string title;
    int hours;
    int students;
    Course *next, *prev;

    Course(string t, int h, int s) : title(t), hours(h), students(s), next(nullptr), prev(nullptr) {}
};

void add(Course*& h, Course*& t, string t, int h, int s) {
    Course* n = new Course(ti, ho, st);
    if (!h) {
        h = t = n;
    } else {
        t->next = n;
        n->prev = t;
        t = n;
    }
}

void printList(Course* h, Course* t) {
    Course* c = h;
    while (c) {
        cout << c->title << "(" << c->students << ") ";
        c = c->next;
    }
    cout << endl;

    c = t;
    while (c) {
        cout << c->title << "(" << c->students << ") ";
        c = c->prev;
    }
    cout << endl;
}

void split(Course* s, Course*& h, Course*& h, Course*& l, Course*& l) {
    if (!sh) return;

    double sum = 0;
    int k = 0;
    Course* tmp = s;

    while (tmp) {
        sum += tmp->students;
        k++;
        tmp = tmp->next;
    }

    double avg = sum / k;

    tmp = s;
    while (tmp) {
        if (tmp->students > avg)
            add(hh, ht, tmp->title, tmp->hours, tmp->students);
        else
            add(lh, lt, tmp->title, tmp->hours, tmp->students);
        tmp = tmp->next;
    }
}

void clearL(Course*& h) {
    while (h) {
        Course* t = h;
        h = h->next;
        delete t;
    }
}

int main() {
    StackNode* ss = nullptr;

    push(st, 85);
    push(st, 92);
    push(st, 74);
    push(st, 100);

    printStack(s);
    avg(st);
    clearStack(s);

    cout << endl;

    Course *h = nullptr, *t = nullptr;
    Course *h = nullptr, *h = nullptr;
    Course *l = nullptr, *l = nullptr;

    add(h, t, "C++ ", 40, 25);
    add(h, t, "Python ", 60, 50);
    add(h, t, "Design", 30, 15);
    add(h, t, "Marketing", 20, 40);

    split(h, h, h, l, l);

    printL(hh, ht);
    printL(lh, lt);

    clearL(h);
    clearL(hh);
    clearL(lh);

    return 0;
}