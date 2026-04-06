#include <iostream>
#include <string>
using namespace std;

struct Music {
    string carrier;
    string title;
    string artist;
    double duration;
    int tracks;
    double price;
    Music* next;
};

void push(Music*& top, string carrier, string title, string artist, double duration, int tracks, double price) {
    top = new Music{carrier, title, artist, duration, tracks, price, top};
}

Music* pop(Music*& top) {
    if (top == nullptr) return nullptr;

    Music* temp = top;
    top = top->next;
    return temp;
}

bool isEmpty(Music* top) {
    return top == nullptr;
}

double getTotalDurationByArtist(Music* top, string artistName) {
    double total = 0;

    while (top != nullptr) {
        if (top->artist == artistName) {
            total += top->duration;
        }
        top = top->next;
    }

    return total;
}

double getAveragePrice(Music* top) {
    double sum = 0;
    int count = 0;

    while (top != nullptr) {
        sum += top->price;
        count++;
        top = top->next;
    }

    if (count == 0) return 0;
    return sum / count;
}

void deleteStack(Music*& top) {
    while (top != nullptr) {
        Music* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    Music* stack = nullptr;
    Music* cassetteStack = nullptr;

    push(stack, "vinyl", "Album1", "Artist1", 40, 10, 20);
    push(stack, "cassette", "Album2", "Artist1", 50, 12, 15);
    push(stack, "cd", "Album3", "Artist2", 60, 14, 25);
    push(stack, "cassette", "Album4", "Artist3", 30, 8, 10);

    string artistName;
    cout << "Enter artist: ";
    cin >> artistName;

    double totalDuration = getTotalDurationByArtist(stack, artistName);
    cout << "Total duration: " << totalDuration << endl;

    while (!isEmpty(stack)) {
        Music* temp = pop(stack);

        if (temp->carrier == "cassette") {
            temp->next = cassetteStack;
            cassetteStack = temp;
        } else {
            delete temp;
        }
    }

    cout << "Average price: " << getAveragePrice(cassetteStack) << endl;

    deleteStack(cassetteStack);

    return 0;
}