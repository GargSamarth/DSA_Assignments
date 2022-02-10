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

void construct_min(hptr &HP, int n){
        HP->H[HP->size++] = n;
        int i = HP->size-1;

        while(i > 0){
            if(HP->H[i] > HP->H[(i-1)/2]){
                break;
            }
            else{
                swap(HP->H[i],HP->H[(i-1)/2]);
            }
            i = (i-1)/2;
        }
}

void construct_max(hptr &HP, int n){
        HP->H[HP->size++] = n;
        int i = HP->size-1;

        while(i > 0){
            if(HP->H[i] < HP->H[(i-1)/2]){
                break;
            }
            else{
                swap(HP->H[i],HP->H[(i-1)/2]);
            }
            i = (i-1)/2;
        }
}

bool check_heap_arr(int *A, int n, int i){
    if(i < (n-1)/2){
        if(A[i] < A[2*i+1] && A[i] < A[2*i+2])
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

void heap_sort(hptr HP){
    while(HP->size > 0){
        cout<< HP->H[0] << " ";
        HP->H[0] = HP->H[HP->size-1];
        HP->size--;
        int n = HP->size, i = 0;
        if(i< (n-1)/2){
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
        else{
            int now = min_of_two(HP,i,i+1);
            if(now != i)
                swap(HP->H[i],HP->H[i+1]);
        }
    }
    cout<< endl;
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
    //cout<< "Enter the array to check for a heap and terminate it by -1: "<< endl;
    // int k,i=0;
    // int B[30];
    // cin>>k;
    // while(k != -1){
    //     B[i++] = k;
    //     cin>>k;
    // }

    // cout<< boolalpha << check_heap_arr(B,i,0) << endl;
    heap_sort(HPm);

    return 0;
}