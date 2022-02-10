#include <iostream>

using namespace std;

//Ques 1
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

int main(){
    //----------1--------------
    int n;
    cin>>n;
    int *A = new int [n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    
    A = selectionSort(A,n);

    for(int i=0;i<n;i++)
        cout<< A[i]<< " ";
    cout<< endl;

    return 0;

}