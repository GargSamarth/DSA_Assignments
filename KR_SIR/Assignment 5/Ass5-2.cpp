#include <iostream>

using namespace std;

int *Insertion_Sort(int *A, int i, int j, int tag, int point, int n){
    if(tag == 1)
        point = A[i];
        //j=i-1;

    if(i < n){
        if(A[j] > point && j>=0){
            A[j+1] = A[j];
            return Insertion_Sort(A, i,j-1,2,point,n);
        }
        A[j+1] = point;
        return Insertion_Sort(A,i+1,i,1,point,n);
    }
    else
    {
        return A;
    }
}

int main(){
    int *A = new int [6];
    for(int i=0;i<6;i++)
        cin>> A[i];
    
    A = Insertion_Sort(A,1,0,1,0,6);
    for(int i=0;i<6;i++)
        cout<< A[i] << " ";

    cout<< endl;
    return 0;
}