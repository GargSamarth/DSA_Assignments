#include <iostream>

using namespace std;

int max_term(int *A, int n){
    int max = A[0];

    for(int i=1;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;    
}

// int find_index(int a[], int n, int x){
//     if(a[n] == x && n>-1)
//         return n;
//     else if(a[n] != x && n>-1)
//         return find_index(a,n-1,x);
//     else 
//         return -1;
// }

int *count_sort(int *A, int n){

    int max = max_term(A,n)+1;
    int *fr = new int [max];

    for(int i=1 ; i<max ; i++)
        fr[i] = 0;

    for(int i=0 ; i<n ; i++)
        fr[A[i]]++;
    
    for(int i=2 ; i<max ; i++){
        fr[i] = fr[i] + fr[i-1];
        //cout<< fr[i] << " ";
    }
    cout<< endl;

    int *B = new int [n];
    int x;

    for(int i=0 ; i<n ; i++){

        x = fr[A[i]];
        B[x] = A[i];
        //cout<< B[x]<< "---------------"<<endl;

        fr[A[i]] = fr[A[i]] - 1;
    }

    return B;
}

int main(){

    int n;
    cin>>n;

    int *A = new int [n+1];

    for(int i=0;i<n;i++)
        cin>> A[i];

    //int *B = new int [n];
    A = count_sort(A,n);

    for(int i=1 ; i<n+1 ; i++)
        cout<< A[i] << " ";

    cout<< endl;

    return 0;
}