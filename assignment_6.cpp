#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1)
        return false;

    for(int i=2;i<=sqrt(n); i++){
        if (n % i==0)
            return false;
    }
    return true;
}

int countPrimesInFile(){
    ifstream file("NUMS.TXT");
    int num, count = 0;

    if(!file){
        cout<<"Error opening file!"<<endl;
        return -1;
    }

    while(file>>num){
        if(isPrime(num)){
            count++;
        }
    }

    file.close();
    return count;
}

int main(){
    int result = countPrimesInFile();

    if (result != -1){
        cout<<"Number of prime numbers: "<<result<<endl;
    }

    return 0;
}