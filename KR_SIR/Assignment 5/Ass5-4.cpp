#include <iostream>

using namespace std;

void merge(int *A, int n, int *B);

void distribution(int *A, int l, int h, int *B){
    if((h-l) > 0){
        int temp = (l+h)/2;
        distribution(A, l, temp,B);
        distribution(A,temp+1,h,B);
    }
    else{
        //cout<< endl << A[l] << "--------------" << l <<endl;
        merge(A,l,B);
    }
    return;
}

void merge(int *A, int n, int *B){
    
    if( n == 0 )
        B[n] = A[n];
    else{
        for(int i=0;i<=n;i++){
            if(A[n] < B[i] && i<n){
                int x = n-i;
                int temp = n;
                while(x--){
                    B[temp] = B[temp-1];
                    temp--;
                }
                B[temp] = A[n];
                break;
            }
            if(i==n)
                B[n] = A[n];
        }
    }
    return;
}

int *merge_sort(int *A, int n){
    int *B = new int [n];
    distribution(A,0,n-1,B);
    return B;
}

int main(){
    int n;
    cin>>n;

    int *A = new int [n];
    for(int i=0;i<n;i++)
        cin>>A[i];

    A = merge_sort(A,n);
    for(int i=0;i<n;i++)
        cout<< A[i] << " ";

    cout<< endl;
    return 0;
}