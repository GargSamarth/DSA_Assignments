#include <iostream>

using namespace std;

struct Heap{
    int H[90];
    int size;
};

typedef Heap *hptr;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void construct_min(hptr &HP, int n){
        HP->H[HP->size++] = n;
        int i = HP->size-1;

        while(i > 0){
            if(HP->H[i] > HP->H[(i-1)/4]){
                break;
            }
            else{
                swap(HP->H[i],HP->H[(i-1)/4]);
            }
            i = (i-1)/4;
        }
}

void construct_max(hptr &HP, int n){
        HP->H[HP->size++] = n;
        int i = HP->size-1;

        while(i > 0){
            if(HP->H[i] < HP->H[(i-1)/4]){
                break;
            }
            else{
                swap(HP->H[i],HP->H[(i-1)/4]);
            }
            i = (i-1)/4;
        }
}

bool check_heap_arr(int *A, int n, int i){
    if(i < (n-1)/2){
        if(A[i] < A[4*i+1] && A[i] < A[4*i+2] && A[i] < A[4*i+3] && A[i] < A[4*i+4])
            return check_heap_arr(A,n,i+1);
        else
            return false;
    }
    else return true; 
}

int min_of_two(hptr HP, int i, int j){
    if(HP->H[i] < HP->H[j]) return i;
    else return j;
}

void delete_node(hptr HP){
    HP->H[0] = HP->H[HP->size-1];
    HP->size--;
    int n = HP->size, i = 0;

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

    hptr HPM = new Heap;
    HPM->size = 0;

    int n;
    cin>>n;

    while(n != -1){
        construct_min(HPm,n);
        construct_max(HPM,n);
        cin>>n;
    }

    print(HPm);
    cout<<endl;
    print(HPM);
    cout<< endl;

    return 0;
}