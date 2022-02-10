#include <iostream>

using namespace std;


int soretd_window(int *A, int n, int i, int count){
    static int l,h;

        if( i<n-1 )
            if(A[i] <= A[i+1])
                return soretd_window(A,n,i+1,count+1);
        }
        
        else{
            l=i;
            return l;
        }
}

int main(){
    int n,B;
    int *A = new int [n];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>> A[i];

    B = soretd_window(A,n,0,0);
    if(B==n-1)
        cout<< "No Sorting needed" << endl;
    else 
        cout<< "Sort the array from index "<< B << " to " << n-1 << endl;

    delete A;
    return 0;
}