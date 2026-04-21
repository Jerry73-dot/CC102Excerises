#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream outFile;
    ifstream inFile;
    ofstream copyFile;
    string line;
    outFile.open("color.txt");

    if(!outFile.is_open()){
        cout<<"Error: Unable to create color.txt"<<endl;
        return 1;
    }

    outFile<<"Red"<<endl;
    outFile<<"Blue"<<endl;
    outFile<<"Green"<<endl;
    outFile<<"Yellow"<<endl;
    outFile<<"Purple"<<endl;

    outFile.close();
    inFile.open("color.txt");

    if(!inFile.is_open()){
        cout << "Error: Unable to open color.txt for reading" << endl;
        return 1;
    }
    
    copyFile.open("color_copy.txt");

    if(!copyFile.is_open()){
        cout<<"Error: Unable to create color_copy.txt"<<endl;
        inFile.close();
        return 1;
    }
    
    while(getline(inFile, line)){
        copyFile<<line<<endl;
    }

    inFile.close();
    copyFile.close();

    cout<<"File copied successfully from color.txt to color_copy.txt"<<endl;

    return 0;
}