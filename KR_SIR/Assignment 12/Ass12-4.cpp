#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void permutation(char *A, int l, int r, int n){

    if(l == r){
        for(int i=0;i<n;i++)
            cout<< A[i];
        cout<< " ";
    }
    else{
        for(int i=l;i<n;i++){
            swap(A[l],A[i]);

            permutation(A,l+1,r,n);

            swap(A[l],A[i]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    char *A = new char [n];

    for(int i=0;i<n;i++)
        cin>>A[i];

    permutation(A,0,n-1,n);
    cout<< endl;
    return 0;
}