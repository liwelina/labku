#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Element {
    double value;
    Element* next;
};


void push(Element*& top, double value) {
    top = new Element{value, top};
}


double pop(Element*& top) {
    if (top == nullptr) return 0;

    Element* temp = top;
    double val = temp->value;
    top = top->next;
    delete temp;
    return val;
}

bool isEmpty(Element* top) {
    return top == nullptr;
}


void showStack(Element* top) {
    while (top != nullptr) {
        cout << top->value << " ";
        top = top->next;
    }
    cout << endl;
}


double findAverage(Element* top) {
    double sum = 0;
    int count = 0;

    while (top != nullptr) {
        sum += top->value;
        count++;
        top = top->next;
    }

    if (count == 0) return 0;
    return sum / count;
}


void deleteStack(Element*& top) {
    while (top != nullptr) {
        Element* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    srand(time(0));

    Element* stack = nullptr;
    Element* newStack = nullptr;

    int n;
    cout << "Number of elements: ";
    cin >> n;


    for (int i = 0; i < n; i++) {
        double x = -6 + rand() % 18; 
        push(stack, x);
    }

    cout << "Initial stack:";
    showStack(stack);

    double limit;
    cout << "Enter a number: ";
    cin >> limit;


    while (!isEmpty(stack)) {
        double x = pop(stack);

        if (x >= limit) {
            push(newStack, x);
        }
    }

    cout << "New stack:";
    showStack(newStack);

    cout << "Average: " << findAverage(newStack) << endl;

    deleteStack(newStack);

    return 0;
}