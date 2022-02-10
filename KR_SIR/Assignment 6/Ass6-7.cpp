#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int *single_swap(int *A, int n, int l ,int tag){
    
    if(n>1){
        if(A[n] < A[n-1] && tag==1)
            return single_swap(A,n-1,n,2);

        else if( tag==2  &&  A[n] < A[n-1]){
                swap(A[l], A[n-1]);
                return A;
        }
        else
            return single_swap(A,n-1,l,tag);
    }

    else{
        if(l>0)
            swap(A[l],A[l-1]);
        else
            cout<< "Your Array is sorted" << endl;
        return A;
    }
    return A;
}

int main(){

    int n;
    int *A = new int [n];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>> A[i];

    A = single_swap(A,n,0,1);

    for(int i=0;i<n;i++)
        cout<< A[i] << " ";
    cout<< endl;
    return 0;
}