#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> result;
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                result.emplace_back(i);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number: ";
    cin >> n;
    vector<int> a = sol.divisors(n);
    for(int num : a){
        cout << num << " ,";
    }
    cout << endl;
}