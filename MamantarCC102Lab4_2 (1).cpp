#include <iostream>
using namespace std;

//Love you sir Jaycee hahaha 😂😂😂

int main() {
    const int months = 12;
    double sales[months][2];

    double total = 0;

    cout << "Enter sales for 12 months:\n";

    for (int i = 0; i < months; i++) {
        sales[i][0] = i + 1;
        cout << "Month " << i + 1 << ": ";
        cin >> sales[i][1];
        total += sales[i][1];
    }

    double highest = sales[0][1];
    double lowest = sales[0][1];
    int highMonth = 0, lowMonth = 0;

    for (int i = 1; i < months; i++) {
        if (sales[i][1] > highest) {
            highest = sales[i][1];
            highMonth = i;
        }
        if (sales[i][1] < lowest) {
            lowest = sales[i][1];
            lowMonth = i;
        }
    }

    cout << "\nTotal Sales: " << total;
    cout << "\nAverage Sales: " << total / months;
    cout << "\nHighest Sales: " << highest << " (Month " << sales[highMonth][0] << ")";
    cout << "\nLowest Sales: " << lowest << " (Month " << sales[lowMonth][0] << ")";

    return 0;
}