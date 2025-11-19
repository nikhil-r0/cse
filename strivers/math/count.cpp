#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    cout << "Enter number: ";
    int num;
    cin >> num;
    if(num < 0) num *= -1;
    int i = 1;
    while(num >= 10){
        num = num/10;
        i++;
    }
    cout << i << " Digits" << endl;
    return 0;
}