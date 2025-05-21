#include <stdio.h>
#include <stdlib.h>

typedef struct arr{
    int* arr;
    int len;
}arr;

void printArr(arr a){
    for(int i = 0; i < a.len; i++){
        printf("%d\t",a.arr[i]);
    }
    printf("\n");
}

arr  createArr(int * a, int len){
    arr temp;
    temp.arr = a;
    temp.len = len;
    return temp;
}


void sort(arr a){
    int count = 0, temp;
    while(count != a.len - 1){
        count = 0;
        for(int i = 0; i < a.len - 1; i++){
            if(a.arr[i] > a.arr[i+1]){
                temp = a.arr[i];
                a.arr[i] = a.arr[i+1];
                a.arr[i+1] = temp;
            }else{
                count++;
            }
        }
    }
}

arr* both(arr a, arr b){
    int c1 = 0, c2 = 0, len = a.len + b.len;
    arr* result = malloc(sizeof(arr) * 2);
    result[0].arr = (int*)malloc(sizeof(int) * len);
    result[1].arr = (int*)malloc(sizeof(int) * len);
    result[0].len = 0; 
    result[1].len = 0;

    while (c1 != a.len && c2 != b.len) {
        if (a.arr[c1] > b.arr[c2]) {
            result[1].arr[result[1].len++] = b.arr[c2++];
        } else if (a.arr[c1] == b.arr[c2]) {
            result[0].arr[result[0].len++] = a.arr[c1++];
            c2++;
        } else {
            result[1].arr[result[1].len++] = a.arr[c1++];
        }
    }

    while (c1 != a.len) {
        result[1].arr[result[1].len++] = a.arr[c1++];
    }
    while (c2 != b.len) {
        result[1].arr[result[1].len++] = b.arr[c2++];
    }
    return result;
}


arr atleast2(arr num1, arr num2, arr num3){
    arr result;
    sort(num1);
    sort(num2);
    sort(num3);
    arr* result1 = both(num1,num2);
    arr* result2 = both(num3, result1[1]);
    result.len = result1[0].len + result2[0].len;
    result.arr = (int*) malloc(sizeof(int)*result.len);
    int c = 0;
    for(int i = 0; i < result1[0].len; i++, c++){
        result.arr[c] = result1[0].arr[i];
    }
    for(int i = 0; i < result2[0].len; i++, c++){
        result.arr[c] = result2[0].arr[i];
    }
    free(result1[0].arr);
    free(result2[0].arr);
    free(result1[1].arr);
    free(result2[1].arr);
    free(result1);
    free(result2);
    return result;
}


void main(){
    int a[] = {3,1}, b[] = {2,3}, c[] = {1,2}; 
    arr num1 = createArr(a,2);
    arr num2 = createArr(b,2);
    arr num3 = createArr(c,2);
    arr result = atleast2(num1,num2,num3);
    printArr(result);
    free(result.arr);
}