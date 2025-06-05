#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int hashmap[26] = {0};

int findRoot(int a){
    if(hashmap[a] == a) return a;
    return hashmap[a] = findRoot(hashmap[a]);
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    for(int i = 0; i < 26; i ++){
        hashmap[i] = i;
    }
    int len = s1.size(), a1, a2;
    for(int i = 0; i < len; i++){
        a1 = findRoot(s1[i] - 97);
        a2 = findRoot(s2[i] - 97);
        if(a1 < a2){
            hashmap[a2] = a1;
        }else if(a1 > a2){
            hashmap[a1] = a2;
        }
    }
    string result = "";
    int k = 0;
    for(char c : baseStr){
        result += char(findRoot(c - 97) + 97);
    }
    return result;
}

int main(){
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    string result = smallestEquivalentString(s1,s2,baseStr);
    cout << result << "\n";
}