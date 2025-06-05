#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int hashmap[26] = {0};
void find(int best, int c1){
    int i = best;
    for(; i < 26; i ++){
        if(hashmap[i] == c1) hashmap[i] = best;
    }
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    int len = s1.size(), a1, a2;
    for(int i = 0; i < len; i++){
        a1 = hashmap[s1[i] - 97];
        a2 = hashmap[s2[i] - 97];
        if(a1 < a2){
            find(a1, a2);
        }else if(a1 > a2){
            find(a2, a1);
        }
    }
    string result = "";
    int k = 0;
    for(int i: hashmap){
        cout << char(k + 97) <<" : " << char(i + 97) << "\t";
        k++;
    }
    cout << "\n";
    for(char c : baseStr){
        result += char(hashmap[c - 97] + 97);
    }
    return result;
}

int main(){
    for(int i = 0; i < 26; i ++){
        hashmap[i] = i;
    }
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    string result = smallestEquivalentString(s1,s2,baseStr);
    cout << result << "\n";
}