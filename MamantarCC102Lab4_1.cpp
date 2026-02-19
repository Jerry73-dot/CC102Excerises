#include <iostream>
using namespace std;

int main() {
    const int students = 3;
    const int quizzes = 3;

    string names[students];
    double scores[students][quizzes];
    double average[students];

    for (int i = 0; i < students; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> names[i];

        for (int j = 0; j < quizzes; j++) {
            cout << "Enter score for Quiz " << j + 1 << ": ";
            cin >> scores[i][j];
        }
    }

    cout << "\n--- Student Averages ---\n";

    for (int i = 0; i < students; i++) {
        double total = 0;

        for (int j = 0; j < quizzes; j++) {
            total += scores[i][j];
        }

        average[i] = total / quizzes;

        cout << "\nName: " << names[i];
        cout << "\nAverage: " << average[i];

        if (average[i] >= 75)
            cout << "\nStatus: Passed\n";
        else
            cout << "\nStatus: Failed\n";
    }

    return 0;
}
