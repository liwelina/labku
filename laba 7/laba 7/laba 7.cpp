#include <iostream>
#include <string>

using namespace std;

struct TemperatureNode {
    string date;
    double value;
    TemperatureNode* next;
    TemperatureNode* prev;

    TemperatureNode(string d, double v) : date(d), value(v), next(nullptr), prev(nullptr) {}
};

void add(TemperatureNode*& h, TemperatureNode*& t, string d, double v) {
    TemperatureNode* n = new TemperatureNode(d, v);
    if (h == nullptr) {
        h = t = n;
    } else {
        t->next = n;
        n->prev = t;
        t = n;
    }
}

void merge(TemperatureNode*& h1, TemperatureNode*& t1, TemperatureNode* h2, TemperatureNode* t2) {
    if (h1 == nullptr) {
        h1 = h2;
        t1 = t2;
    } else if (h2 != nullptr) {
        t1->next = h2;
        h2->prev = t1;
        t1 = t2;
    }
}

void minmax(TemperatureNode* h) {
    if (h == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    double mn = h->value;
    double mx = h->value;

    TemperatureNode* c = h->next;
    while (c != nullptr) {
        if (c->value < mn) mn = c->value;
        if (c->value > mx) mx = c->value;
        c = c->next;
    }

    cout << "Min temperature: " << mn << endl;
    cout << "Max temperature: " << mx << endl;
}

void clear(TemperatureNode*& h) {
    while (h != nullptr) {
        TemperatureNode* tmp = h;
        h = h->next;
        delete tmp;
    }
}

int main() {
    TemperatureNode *h1 = nullptr, *t1 = nullptr;
    TemperatureNode *h2 = nullptr, *t2 = nullptr;

    add(h1, t1, "01.01", -5.5);
    add(h1, t1, "15.01", -10.0);

    add(h2, t2, "01.02", 3.2);
    add(h2, t2, "20.02", -2.0);

    merge(h1, t1, h2, t2);

    minmax(h1);

    clear(h1);

    return 0;
}