#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size:";
    cin >> n;
    int i = 0, j = 0, c = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < i; j++) cout << n - j << " ";
        c = n - j;
        for(j = 0; j < (n - i)*2 - 1; j++) cout << c << " ";
        for(j = 0; j < i; j++) cout << c + j + 1 << " ";
        cout << endl;
    }
    for(i = n-2; i >= 0; i--){
        for(j = 0; j < i; j++) cout << n - j << " ";
        c = n - j;
        for(j = 0; j < (n - i)*2 - 1; j++) cout << c << " ";
        for(j = 0; j < i; j++) cout << c + j + 1 << " ";
        cout << endl;
    }
}