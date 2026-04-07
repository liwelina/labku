#include <iostream>
#include <string>
using namespace std;

struct City {
    string name;
    double dist;
    City* next;
};

void add(City*& head, string n, double d) {
    head = new City{n, d, head};
}

void maxCities(City* head) {
    City *m1 = head, *m2 = head;

    while (head) {
        if (head->dist > m1->dist) {
            m2 = m1;
            m1 = head;
        } else if (head->dist > m2->dist && head != m1) {
            m2 = head;
        }
        head = head->next;
    }

    cout << "Farthest: " << m1->name << " " << m2->name << endl;
}

void clear(City*& head) {
    while (head) {
        City* t = head;
        head = head->next;
        delete t;
    }
}

int main() {
    City* head = NULL;

    add(head, "Lviv", 540);
    add(head, "Odesa", 475);
    add(head, "Kharkiv", 480);

    maxCities(head);

    add(head, "Berlin", 1200);

    maxCities(head);

    clear(head);

    return 0;
}