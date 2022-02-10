#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

int *selectionSort(int *A, int n){
    static int i = 0,j = 0;
    if(j < n-1){
        j++;
        ( A[i] > A[j] ? (swap( A[i],A[j] ),selectionSort(A, n)) : selectionSort(A, n) );
    }
    else if(i<n-2){
        i++;
        j=i;
        selectionSort(A,n);
    }
    return A;
}

int *bubbleSort(int *A, int n){
    static int i = 0,j = 5;
    if(j < n-i-2){
        j++;
        ( A[j] > A[j+1] ? (swap( A[j],A[j+1] ),bubbleSort(A, n)) : bubbleSort(A, n));
    }
    else if(i<n-2){
        i++;
        j=5;
        bubbleSort(A,n);
    }
    return A;
}

int main(){
    int n=12;
    int *p = new int[n];

    for(int i=0;i<n;i++)
        cin>> p[i];

    p = selectionSort(p,n/2);
    p = bubbleSort(p,n);
    
    for(int i=0;i<n;i++)
        cout<< p[i] << " ";
    
    cout<<endl;
    
    return 0;
}
