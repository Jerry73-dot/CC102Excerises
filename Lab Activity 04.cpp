#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int ROWS = 5;
    const int COLS = 10;
    int computers[ROWS][COLS] = {0};
    int choice;

    do {
        cout << "\n===== * COMPUTER SHOP RENTAL SYSTEM * =====\n";
        cout << "1. View Computer Layout\n";
        cout << "2. Rent a Computer\n";
        cout << "3. Return a Computer\n";
        cout << "4. Reset Rental System\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1: // View Layout
            cout << "\n   ";
            for(int c=1;c<=COLS;c++)
                cout << setw(3) << c;

            cout << endl;

            for(int r=0;r<ROWS;r++) {
                char rowLetter = 'A' + r;
                cout << rowLetter << "  ";

                for(int c=0;c<COLS;c++)
                    cout << setw(3) << computers[r][c];

                cout << endl;
            }
            break;

        case 2: { // Rent Computer
            int row,col,hours;

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;
            cout << "Enter hours: ";
            cin >> hours;

            if(row<1 || row>5 || col<1 || col>10 || hours<=0){
                cout<<"Invalid input!\n";
                break;
            }

            if(computers[row-1][col-1] > 0){
                cout<<"Computer unit already rented!\n";
            }
            else{
                computers[row-1][col-1] = hours;
                char rowLetter = 'A' + (row-1);
                cout<<"Computer unit "<<rowLetter<<col
                    <<" successfully rented for "<<hours<<" hour(s)!\n";
            }
            break;
        }

        case 3: { // Return Computer
            int row,col;

            cout<<"Enter row (1-5): ";
            cin>>row;
            cout<<"Enter column (1-10): ";
            cin>>col;
            if(row<1 || row>5 || col<1 || col>10){
                cout<<"Invalid input!\n";
                break;
            }
            if(computers[row-1][col-1]==0){
                cout<<"Computer unit already available!\n";
            }
            else{
                int storedHours = computers[row-1][col-1];
                double sale = storedHours * 20.0;

                char rowLetter = 'A' + (row-1);

                cout<<"Computer unit "<<rowLetter<<col<<" has been returned.\n";
                cout<<"Rental Sale: P"<<sale<<endl;

                computers[row-1][col-1] = 0;
            }
            break;
        }

        case 4:
            for(int r=0;r<ROWS;r++)
                for(int c=0;c<COLS;c++)
                    computers[r][c] = 0;
                    
            cout<<"Rental system reset successfully!\n";
            break;
        case 5:
            cout<<"Exiting program...\n";
            break;

        default:
            cout<<"Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}