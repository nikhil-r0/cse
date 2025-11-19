#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size:";
    cin >> n;
    int i = 0, j = 0;
    char c = 'A' + n - 1;
    for(i = 0; i < n; i++){
        cout << endl;
        for(j = 0; j < n - i; j++) cout << "*";
        for(j = 0; j < i*2; j++) cout << " ";
        for(j = 0; j < n - i; j++) cout << "*";
    }
    for(i = n; i >= 0; i--){
        for(j = 0; j < n - i; j++) cout << "*";
        for(j = 0; j < i*2; j++) cout << " ";
        for(j = 0; j < n - i; j++) cout << "*";
        cout << endl;
    }
}