#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        int max = sqrt(n) + 1;
        for(int i = 2; i <= max; i++){
            if(n % i == 0)return false;
        }
        return true;
    }
};


int main(){
    Solution sol;
    cout << "Enter number:";
    int num;
    cin >> num;
    cout << sol.isPrime(num) << endl;
}