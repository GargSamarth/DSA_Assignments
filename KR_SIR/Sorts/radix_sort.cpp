#include <iostream>

using namespace std;

int max_term_edited(int *A, int n, int num, int denom){
    int max = (A[0] / denom) % num;

    for(int i=1;i<n;i++){
        if( ((A[i] / denom) % num) > max )
            max = (A[i] / denom) % num;
    }
    return max;    
}

int max_term(int *A, int n){
    int max = A[0];

    for(int i=1;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;    
}

int *count_sort(int *A, int n, int num, int denom){

    int max = max_term_edited(A,n,num,denom)+1;
    int *fr = new int [max];

    for(int i=0 ; i<max ; i++)
        fr[i] = 0;

    for(int i=0 ; i<n ; i++)
        fr[(A[i] / denom) % num]++;
    
    for(int i=1 ; i<max ; i++){
        fr[i] = fr[i] + fr[i-1];
    }
    //cout<< endl;

    int *B = new int [n+1];
    int x;

    for(int i=0 ; i<n ; i++){

        x = n - fr[(A[i] / denom) % num];
        B[x] = A[i];

        fr[(A[i] / denom) % num] = fr[(A[i] / denom) % num] - 1;
    }

    return B;
}

int *radix_sort(int *A, int n){

    int *B =new int [n];
    int max = max_term(A,n)*10;
    int denom = 1, num = 10;

    while(max>0){
        A = count_sort(A,n,num,denom);
        denom*=10;
        max = max/10;
    }
    for(int i=0;i<n;i++)
        B[i] = A[n-1-i];

    return B;
}

int main(){
    int n;
    cin>>n;

    int *A = new int [n+1];

    for(int i=0;i<n;i++)
        cin>> A[i];

    //int *B = new int [n];
    A = radix_sort(A,n);

    for(int i=0 ; i<n; i++)
        cout<< A[i] << " ";

    cout<< endl;

    return 0;

}