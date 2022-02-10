#include <iostream>

using namespace std;

struct bstnode {
    bstnode *lc;
    int data;
    bstnode *rc;
};

struct Heap{
    int H[30],size;
};

//define 
typedef bstnode *bstptr;

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

void insert(bstptr &T, int k){
    if(T == NULL){
        T = new bstnode;
        T->data = k;
        T->lc = NULL;
        T->rc = NULL;
    }
    else{
        if(k < T->data)
            insert(T->lc, k);
        else
            insert(T->rc, k);
    }
}

void inorder(bstptr T, int *A, int &i){
    if(T != NULL){
        inorder(T->lc,A,i);
        A[i++] = T->data;
        inorder(T->rc,A,i);
    }
}

int min_of_two(hptr HP, int i, int j){
    if(HP->H[i] < HP->H[j]) return i;
    else return j;
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

int main(){
    int n;
    cin>>n;
    int **A,count=0;
    A = new int* [n];
    
    for(int i=0;i<n;i++){
        bstptr BT = NULL;
        int k,j=1;
        cin>>k;
        while(k != -1){
            count++;
            insert(BT,k);
            cin>>k;
        }
        A[i] = new int[count+1];
        A[i][0] = count;
        inorder(BT,A[i],j);
        count=0;
    }

    hptr HP = new Heap;
    HP->size = 0;

    for(int i=0;i<n;i++){
        for(int j=1;j<=A[i][0];j++){
            construct_min(HP,A[i][j]);
        }
    }
    heap_sort(HP);
    cout<< endl;
    return 0;
}