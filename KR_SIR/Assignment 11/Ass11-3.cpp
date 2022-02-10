#include <iostream>

using namespace std;

int min_term(int *A, int l, int h){
    int min = A[l];
    for(int i=l+1;i<h;i++)
        if(A[i]<min)
            min = A[i];
    return min;
}

int max_term(int *A, int l, int h){
    int max = A[l];
    for(int i=l+1;i<h;i++)
        if(A[i]>max)
            max = A[i];
    return max;
}

int area(int *A, int n){
    
    int *C = new int [n];
    int j=0,count=1;
    C[j++] = max_term(A,0,n);
    count++;

    while(j<n){

        int *B = new int [n-count+1];

        for(int i=0;i<n-count+1;i++){
            B[i] = min_term(A,i,i+count)*count;
        }

        count++;
        C[j++] = max_term(B,0,n-count+1);
        delete B;

    }
    return max_term(C,0,n);
}

int main(){
    int n;
    cin>>n;
    int *A = new int [n];
    for(int i=0;i<n;i++)
        cin>>A[i];

    cout<< area(A,n)<<endl;

    return 0;
}