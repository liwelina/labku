#include <iostream>
#include <string>
using namespace std;

struct Course {
    string name;
    int students;
    Course* next;
};

void add(Course*& head, string name, int students) {
    Course* n = new Course{ name, students, nullptr };

    if (!head) {
        head = n;
        return;
    }

    Course* t = head;
    while (t->next)
        t = t->next;

    t->next = n;
}

void print(Course* head) {
    while (head) {
        cout << head->name << "(" << head->students << ") ";
        head = head->next;
    }
    cout << endl;
}


void split(Course* src, Course*& big, Course*& small) {
    double sum = 0;
    int k = 0;

    Course* t = src;

    while (t) {
        sum += t->students;
        k++;
        t = t->next;
    }

    double avg = sum / k;

    t = src;
    while (t) {
        if (t->students > avg)
            add(big, t->name, t->students);
        else
            add(small, t->name, t->students);

        t = t->next;
    }
}

int main() {
    Course* list = nullptr;

    add(list, "C++", 25);
    add(list, "Python", 50);
    add(list, "Design", 15);
    add(list, "Marketing", 40);

    Course* big = nullptr;
    Course* small = nullptr;

    split(list, big, small);

    cout << "Big:";
    print(big);

    cout << "Small:";
    print(small);

    return 0;
}