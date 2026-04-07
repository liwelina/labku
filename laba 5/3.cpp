#include <iostream>
#include <string>
using namespace std;

struct Car {
    string name;
    int year;
    double price;
    Car* next;
};

void add(Car*& head, string n, int y, double p) {
    head = new Car{n, y, p, head};
}

void show(Car* head) {
    while (head) {
        if (2026 - head->year > 10 && head->price < 5000) {
            cout << head->name << " " << head->year << " " << head->price << endl;
        }
        head = head->next;
    }
}

void clear(Car*& head) {
    while (head) {
        Car* t = head;
        head = head->next;
        delete t;
    }
}

int main() {
    Car* head = NULL;

    add(head, "BMW", 2005, 4000);
    add(head, "Audi", 2018, 7000);
    add(head, "Mercedes", 2010, 3000);

    show(head);

    clear(head);

    return 0;
}