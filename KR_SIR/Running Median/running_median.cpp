#include <iostream>
using namespace std;

struct Heap{
    int H[30],size;
};
typedef Heap *hptr;
void swap(int &a, int &b){
    int temp = a; a = b; b = temp;
}
void construct_min(hptr &HP, int n){
    HP->H[HP->size++] = n;  int i = HP->size-1;
    while(i > 0){
        if(HP->H[i] > HP->H[(i-1)/2])   break;
        else    swap(HP->H[i],HP->H[(i-1)/2]);
        i = (i-1)/2;}
}
void construct_max(hptr &HP, int n){
    HP->H[HP->size++] = n;  int i = HP->size-1;
    while(i > 0){
        if(HP->H[i] < HP->H[(i-1)/2])    break;
        else    swap(HP->H[i],HP->H[(i-1)/2]);
        i = (i-1)/2;}
}

int main(){
    int *A = new int[20];
    int i=0,n,m,count_min=0,count_max=0,peak_min=-1,peak_max=-1;
    cin>>n;
    cout<< "Median: "<<n<< endl;
    cin>>m;
    cout<< "Median: "<<(n+m)/2<< endl;

    hptr HPm = new Heap;
    HPm->size = 0;
    hptr HPM = new Heap;
    HPM->size = 0;

    if(n < m){
        construct_min(HPm,n);
        count_min++;    peak_min=HPm->H[0];
        construct_max(HPM,m);
        count_max++;    peak_max=HPM->H[0];
    }
    else{
        construct_min(HPm,m);
        count_min++;    peak_min=HPm->H[0];
        construct_max(HPM,n);
        count_max++;    peak_max=HPM->H[0];
    }
    cin>>n;

    while(n != -1){
        if(n < peak_min){
            construct_min(HPm,n);
            count_min++;    peak_min=HPm->H[0];
        }
        else if(n > peak_max){
            construct_max(HPM,n);
            count_max++;    peak_max=HPM->H[0];
        }
        else{
            if(count_max < count_min){
                construct_max(HPM,n);
                count_max++;    peak_max=HPM->H[0];
            }
            else{
                construct_min(HPm,n);
                count_min++;    peak_min=HPm->H[0];
            }
        }
        cout<<"Median: "<< (peak_max+peak_min)/2<< endl; 
        cin>>n;
    }
    cout<< endl;

    return 0;
}