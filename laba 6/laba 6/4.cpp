#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Team {
    string name;
    string city;
    int points;
};

int main() {
    queue<Team> q;

    q.push({"1", "Kyiv", 10});
    q.push({"2", "Lviv", 5});
    q.push({"3", "Kyiv", 8});
    q.push({"4", "Odesa", 12});
    q.push({"5", "Lviv", 7});

    int size = q.size();

    Team leader = q.front();
    Team outsider = q.front();

    for (int i = 0; i < size; i++) {
        Team t = q.front();
        q.pop();

        if (t.points > leader.points)
            leader = t;

        if (t.points < outsider.points)
            outsider = t;

        q.push(t);
    }

    cout << "Leader: " << leader.name << endl;
    cout << "Outsider: " << outsider.name << endl;

    queue<Team> uniqueQ;
    string cities[100];
    int count = 0;

    for (int i = 0; i < size; i++) {
        Team t = q.front();
        q.pop();

        bool used = false;

        for (int j = 0; j < count; j++) {
            if (cities[j] == t.city)
                used = true;
        }

        if (!used) {
            uniqueQ.push(t);
            cities[count++] = t.city;
        }

        q.push(t);
    }

    int k = 8;
    queue<Team> filtered;

    for (int i = 0; i < size; i++) {
        Team t = q.front();
        q.pop();

        if (t.points > k)
            filtered.push(t);

        q.push(t);
    }

    cout << "Unique cities:"<<endl;
    while (!uniqueQ.empty()) {
        Team t = uniqueQ.front();
        uniqueQ.pop();
        cout << t.name << " " << t.city << " " << t.points << endl;
    }

    cout << "Points > " << k << ":"<<endl;
    while (!filtered.empty()) {
        Team t = filtered.front();
        filtered.pop();
        cout << t.name << " " << t.city << " " << t.points << endl;
    }

    return 0;
}