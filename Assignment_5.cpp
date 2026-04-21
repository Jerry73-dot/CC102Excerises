#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ofstream outFile;
    ifstream inFile;
    ofstream sortedFile;
    vector<string> words;
    string line;
    
    outFile.open("original.txt");

    if(!outFile.is_open()){
        cout<<"Error: Unable to create original.txt"<<endl;
        return 1;
    }

    outFile<<"One"<<endl;
    outFile<<"Two"<<endl;
    outFile<<"Three"<<endl;
    outFile<<"Four"<<endl;
    outFile<<"Five"<<endl;
    outFile<<"Six"<<endl;
    outFile.close();

    inFile.open("original.txt");

    if(!inFile.is_open()){
        cout<<"Error: Unable to open original.txt"<<endl;
        return 1;
    }

    while (getline(inFile, line)){
        words.push_back(line);
    }

    inFile.close();
    sort(words.begin(), words.end());
    sortedFile.open("sorted.txt");

    if(!sortedFile.is_open()){
        cout<<"Error: Unable to create sorted.txt"<<endl;
        return 1;
    }

    for(const string& word : words){
        sortedFile << word << endl;
    }

    sortedFile.close();
    cout<<"Sorting completed. Check sorted.txt"<<endl;

    return 0;
}