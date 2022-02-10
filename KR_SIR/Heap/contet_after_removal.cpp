#include <iostream>

using namespace std;

struct Heap{
    int H[30];
    int size;
};

typedef Heap *hptr;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void construct(hptr &HP, int n){
        HP->H[HP->size++] = n;
        int i = HP->size-1;
        while(i > 0){
            if(HP->H[i] > HP->H[(i-1)/2]){
                break;
            }
            else{
                swap(HP->H[i],HP->H[(i-1)/2]);
            } i = (i-1)/2;
        }
}

int min_of_two(hptr HP, int i, int j){
    if(HP->H[i] < HP->H[j]) return i;
    else return j;
}

void delete_element(hptr HP){
    
        HP->H[0] = HP->H[HP->size-1];
        HP->size--;
        int n = HP->size, i = 0;

        if(i< (n-1)/2)
            while(i < (n-1)/2){
                if(HP->H[i] > HP->H[2*i + 1] && HP->H[i] > HP->H[2*i + 2]){
                    int now = min_of_two(HP,2*i+1,2*i+2);
                    swap(HP->H[i],HP->H[now]);
                    i = now;
                }
                else if(HP->H[i] < HP->H[2*i + 1] && HP->H[i] > HP->H[2*i + 2]){
                    swap(HP->H[i],HP->H[2*i + 2]);
                    i = 2*i + 2;
                }
                else if(HP->H[i] > HP->H[2*i + 1] && HP->H[i] < HP->H[2*i + 2]){
                    swap(HP->H[i],HP->H[2*i + 1]);
                    i = 2*i + 1;
                }
                else    break;
            }
        else{
            int now = min_of_two(HP,i,i+1);
            if(now != i) swap(HP->H[i],HP->H[i+1]);
        }
}

void print(hptr HP){
    int n = HP->size;
    int i = 0;
    while(i < n){
        cout<< HP->H[i++] << " ";
    }
}

int main(){
    hptr HPm = new Heap;
    HPm->size = 0;
    int n;
    cin>>n;
    while(n != -1){
        construct(HPm,n);
        cin>>n;
    }
    cout<< "Present Heap Array: - "<< endl;
    print(HPm);
    cout<< endl << "Enter the number of elements to delete: - "<< endl;
    int k;
    cin>>k;

    for(int l=0;l<k;l++)
        delete_element(HPm);
    cout<< "Heap Array after deleting "<< k << " elements: - "<<endl;
    print(HPm);
    cout<< endl;
    return 0;
}