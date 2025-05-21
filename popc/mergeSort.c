#include <stdio.h>
#include <stdlib.h>

int * merge(int arr1[],int m, int arr2[], int n){
    int* result = malloc((m+n)*sizeof(int));
    int l = m+n, i,j=0,k=0;
    for(i = 0;i < l&& j<m && k<n;i++){
        if(arr1[j]<arr2[k]){
            result[i] = arr1[j];
            j++;
        }else{
            result[i] = arr2[k];
            k++;
        }
    }
    if(k == n){
        for(j = j; j < m; j++){
            result[i] = arr1[j];
            i++;
        }
    }else if(j == m){
        for(k = k; k < n; k++){
            result[i] = arr2[k];
            i++;
        }
    }
    if(m != 1){
        free(arr1);
    }
    if(n != 1){
        free(arr2);
    }
    return result;
}

int* mergeSort(int* arr,int l){
    if(l <= 1){
        return arr;
    }
    int m,n;
    if(l % 2){
        m = l/2+1;
        n = l/2;
    }else{
        m = l/2;
        n = m;
    }
    return merge(mergeSort(arr,m),m,mergeSort(&arr[m],n),n);
}

void main(){
    int arr[] = {1};
    int n = 1;
    int* result = mergeSort(arr,n);
    for(int i = 0; i < n; i ++){
        printf("%d ",result[i]);
     }
     printf("\n");
     if(n > 1)
        free(result);
}