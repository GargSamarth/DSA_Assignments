#include <iostream>

using namespace std;

struct intervals{
    int l,h;
};

int main(){
    int n;
    cout<< "Enter the number of intervals: ";
    cin>>n;
    intervals *A = new intervals[n];

    for(int i=0;i<n;i++){
        int l,h;
        cin>>l>>h;
        A[i].l = l;
        A[i].h = h;
    }
}