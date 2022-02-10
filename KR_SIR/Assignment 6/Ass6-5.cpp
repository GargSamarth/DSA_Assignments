#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void merge_two_part2(int *A, int *B, int n1, int n2, int p1, int p2){
    if(p1<n1 && A[p1] == 0){
        if( A[p1+1] > B[p2] ){
            if(A[p1-1] < B[p2] || p1 == 0){
                swap(A[p1], B[p2]);
                merge_two_part2(A,B,n1,n2,p1+1,p2+1);
            }
                
            else{
                swap(A[p1-1],A[p1]);
                merge_two_part2(A,B,n1,n2,p1-1,p2);
            }
        }
        else if( A[p1+1] < B[p2]){
            if(A[p1+1] != 0){
                swap(A[p1], A[p1+1]);
                merge_two_part2(A,B,n1,n2,p1+1,p2);
            }
            else{
                
            }
        }
    }
    else
        merge_two_part2(A,B,n1,n2,p1+1,p2);
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int *A = new int [n1];
    int *B = new int [n2];

    for(int i=0;i<n1;i++)
        cin>> A[i];
    
    for(int i=0;i<n2;i++)
        cin>> B[i];
    
    merge_two(A,B,n1,n2,0,0);

    for(int i=0;i<n1;i++)
        cout<< A[i]<< " ";

    cout<<endl;

    // for(int i=0;i<n2;i++)
    //     cout<< B[i]<< " ";
    
    // cout<< endl;
    return 0;
}