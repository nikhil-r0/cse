#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int num;
    cout << "Enter number:";
    cin >> num;
    int res = 0;
    while(num > 0){
        res = (res * 10)+ (num % 10);
        // cout << res << " ," << num % 10 << " | ";
        num /= 10;
    }
    // cout << endl;
    cout << res << endl;
    return 0;
}