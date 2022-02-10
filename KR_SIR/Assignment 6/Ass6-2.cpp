#include <iostream>

using namespace std;

int *sorted_triplet(int *A, int n, int *B, int i, int j, int track){
    static int count = 0;
    if(n>j && (count<3)){
        if(count==0 || (B[i-1] < A[j])){
            count++;
            B[i] = A[j];
            return sorted_triplet(A,n,B,i+1,j+1,track);
        }
        return sorted_triplet(A,n,B,i,j+1,track);
    }
    else{
        if(count == 3)
            return B;
        else if(count < 3 && track < n){
            delete B;
            B = new int [3];
            count = 0;
            return sorted_triplet(A,n,B,0,track+1,track+1);
        }
        else{
            cout<< "No such triplets exists"<<endl;
            int *k = new int [3];
            for(int i = 0;i<3;i++)
                k[i] = 0;
            return k;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int *A = new int [n];
    int *B = new int [3];
    for(int i=0;i<n;i++)
        cin>>A[i];
    
    B = sorted_triplet(A,n,B,0,0,0);

    for(int i=0;i<3;i++)
        cout<< B[i]<< " ";
    cout<< endl;

    return 0;
}