#include <iostream>
using namespace std;

int main() {
    char repeat;

    do {
        int N;
        cout << "Enter N: ";
        cin >> N;
        char grid[100][100];
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if((i + j) % 3 == 0)
                    grid[i][j] = 'x';
                else
                    grid[i][j] = 'o';
            }
        }
        cout << "\nPattern:\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\nRepeat program? (y/n): ";
        cin >> repeat;

    } while(repeat == 'y' || repeat == 'Y');

    return 0;
}