#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int particition(int *A, int l, int h, int tag){
    int i=l+1,j=h-2, pivot;

    if(tag == 1){
        if(A[h-1] < A[l])
            swap(A[l], A[h-1]);
        pivot = A[l];
    }

    if(tag == 2)
        pivot = A[h-1];

    while(i < j){

        while(A[i] <= pivot && i<=j)
            i++;
        while(A[j] > pivot && i<=j)
            j--;

        if(i<j)
            swap(A[i],A[j]);

    }

    if(tag == 1){
        swap( A[l],A[j] );
         return j;
    }

    else{
        swap( A[h-1],A[i] );
        return i;
    }
}

void QuickSort(int *A, int l, int h){
    int j1, j2;

    if(l < h){
        j1 = particition(A,l,h,1);
        j2 = particition(A,j1,h,2);
        QuickSort(A,l,j1);
        QuickSort(A,j1+1,j2);
        QuickSort(A,j2+1,h);
    }
}

int main(){
    int n;
    cin>>n;

    int *A = new int [n];

    for(int i=0;i<n;i++)
        cin>> A[i];

    QuickSort(A,0,n);

    for(int i=0;i<n;i++)
        cout<< A[i]<< " ";

    cout<<endl;

    return 0;
}