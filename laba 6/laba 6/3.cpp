#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    queue<int> q;
    queue<int> newQ;

    srand(time(0));

    int n = 10;

    for (int i = 0; i < n; i++) {
        int x = rand() % 50 + 1;
        q.push(x);
    }

    cout << "Original queue:"<<endl;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        if (x % 2 == 0) {
            newQ.push(x);
            newQ.push(100);
        }
    }

    cout << "New queue:"<<endl;

    queue<int> temp = newQ;

    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    double product = 1;
    int count = 0;

    while (!newQ.empty()) {
        int x = newQ.front();
        newQ.pop();

        product *= x;
        count++;
    }

    double geomMean = pow(product, 1.0 / count);

    cout << "Geometric mean:" << geomMean << endl;

    return 0;
}