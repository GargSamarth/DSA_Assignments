#include <iostream>

using namespace std;

int max_term(int *A, int l, int h){
    int max = A[l];
    for(int i=l+1;i<h;i++)
        if(A[i]>max)
            max = A[i];
    return max;
}

int *window(int *A, int n, int b){

    int j=0,*B;
    B = new int [n-b+1];

    for(int i=0;i<n-b+1;i++){
        B[j++] = max_term(A,i,i+b);
    }
    return B;
}

int main(){
    int n,b;
    cin>>n>>b;

    int *A = new int [n];
    int *B = new int [n-b+1];

    for(int i=0;i<n;i++)
        cin>>A[i];

    B = window(A,n,b);

    for(int i=0;i<n-b+1;i++)
        cout<<B[i]<< " ";
    cout<<endl;

    return 0;
}