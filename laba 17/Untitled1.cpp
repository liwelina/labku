#include <iostream>
#include <string>
using namespace std;
struct Student {
	string surname;
	int group;
	int marks[4];
	double average;
	};
	
	
	void CalculateAverage(Student &s) {
	int sum=0;
	for (int i = 0; i < 4; i++) {
    sum += s.marks[i];
    }
    s.average = sum / 4.0;
}
	void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
    if (arr[j].average > arr[j + 1].average) {
    swap(arr[j], arr[j + 1]);
    }
    }
    }
}

void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].group < key.group) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void binarySearch(Student arr[], int n, double value) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (arr[middle].average == value) {
            found = true;

            
            int i = middle;
            while (i >= 0 && arr[i].average == value) {
                cout << arr[i].surname << " " << arr[i].group << " avg: " << arr[i].average << endl;
                i--;
            }

            i = middle + 1;
            while (i < n && arr[i].average == value) {
                cout << arr[i].surname << " " << arr[i].group << " avg: " << arr[i].average << endl;
                i++;
            }
            break;
        }
        else if (arr[middle].average < value) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    if (!found) {
        cout << "Student not found" << endl;
    }
}


void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].surname << " "
             << arr[i].group << " avg: "
             << arr[i].average << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];


    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Surname: ";
        cin >> students[i].surname;
        cout << "Group: ";
        cin >> students[i].group;

        cout << "Enter 4 marks: ";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].marks[j];
        }

        CalculateAverage(students[i]);
    }


    Student* copy = new Student[n];
    for (int i = 0; i < n; i++) {
        copy[i] = students[i];
    }


    bubbleSort(students, n);
    insertionSort(copy, n);

    cout << endl << "Sorted by average:" << endl; //за зролстанням
    printStudents(students, n);

    cout << endl << "Sorted by group :" << endl; //за спаданням
    printStudents(copy, n);

  
    double value;
    cout << endl << "Enter average to search: ";
    cin >> value;

    binarySearch(students, n, value);

    delete[] students;
    delete[] copy;

    return 0;
}

