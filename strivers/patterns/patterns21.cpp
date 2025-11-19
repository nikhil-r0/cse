#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size:";
    cin >> n;
    int i = 0, j = 0;
    char c = 'A' + n - 1;
    for(j = 0; j < n; j++) cout << "*";
    cout << endl;
    for(i = 0; i < n - 2; i++){
        cout << "*";
        for(j = 0; j < n - 2; j++) cout << " ";
        cout<< "*" << endl;
    }
    for(j = 0; j < n; j++) cout << "*";
    cout << endl;
}