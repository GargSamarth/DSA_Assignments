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

void merge_two(int *A, int *B, int n1, int n2, int p1, int p2){
    if(p1<n1){
        if(A[p1] > B[p2])
            swap(A[p1],B[p2]);

        merge_two(A,B,n1,n2,p1+1,p2);      
    }

    else if((p1 == n1) && (p2 < (n2-1)))
        merge_two(A,B,n1,n2,0,p2+1);

    else if(p2 == n2-1){
        selectionSort(B,n2);
        return;
    }
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int *A = new int [n1];
    int *B = new int [n2];

    for(int i=0;i<n1;i++)
        cin>> A[i];
    
    for(int i=0;i<n2;i++)
        cin>> B[i];
    
    merge_two(A,B,n1,n2,0,0);

    for(int i=0;i<n1;i++)
        cout<< A[i]<< " ";

    cout<<endl;

    for(int i=0;i<n2;i++)
        cout<< B[i]<< " ";
    
    cout<< endl;
    return 0;
}