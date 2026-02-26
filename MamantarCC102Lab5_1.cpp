#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int students, days;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of school days: ";
        cin >> days;

        // Create 2D vector
        vector<vector<int>> attendance(students, vector<int>(days));

        // Input attendance
        for (int i = 0; i < students; i++) {
            cout << "Student " << i + 1 << " attendance (";
            cout << days << " values - 1 for Present, 0 for Absent): ";

            for (int j = 0; j < days; j++) {
                cin >> attendance[i][j];
            }
        }

        cout << "\n===== Attendance Report =====\n";
        cout << left << setw(8) << "Student";

        for (int d = 0; d < days; d++) {
            cout << "D" << d + 1 << " ";
        }

        cout << setw(8) << "Total"
             << setw(12) << "Percentage"
             << "Remarks" << endl;

        // Process each student
        for (int i = 0; i < students; i++) {
            int total = 0;

            cout << left << setw(8) << i + 1;

            for (int j = 0; j < days; j++) {
                cout << attendance[i][j] << "  ";
                total += attendance[i][j];
            }

            double percentage = (double)total / days * 100;
            string remark = (percentage < 50) ? "DRP" : "OK";

            cout << setw(8) << total
                 << setw(12) << fixed << setprecision(0) << percentage << "%"
                 << remark << endl;
        }

        cout << "\nRun program again? (y/n): ";
        cin >> again;

        cout << endl;

    } while (again == 'y' || again == 'Y');

    return 0;
}