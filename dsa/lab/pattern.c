/*
    2.Develop a Program in C for the following operations on Strings
        a. Read a main String (STR), a Pattern String (PAT) and a Replace String(REP)
        b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT
        in STR with REP if PAT exists in STR. Report suitable messages in case PAT
        does not exist in STR Support the program with functions for each of the
        above operations. Don't use Built-in functions.
*/

#include <stdio.h>

void repString(char* string, char* pat, char* rep, char* ans){
    int m = 0, k = 0, i = 0, c = 0, flag = 0;
    while( string[c] != '\0'){
        if(string[i] == pat[m]){
            m++;
            i++;
            if(pat[m] == '\0'){
                c = i;
                for(m = 0;rep[m] != '\0'; m++){
                    ans[k++] = rep[m];
                }
                flag = 1;
            }
        }else{
            ans[k++] = string[c++];
            i = c;
            m = 0;
        }
    }
    if(!flag){
        printf("No match found!\n");
    }
}

void main(){
    char string[100], pat[20], rep[20], ans[120];
    printf("Enter the String, Pattern and Replacement String:");
    scanf("%s%s%s",string,pat,rep);
    repString(string,pat,rep,ans);
    printf("Original String: %s\nPattern: %s\nReplacement String: %s\nAnswer: %s\n",string,pat,rep,ans);
}