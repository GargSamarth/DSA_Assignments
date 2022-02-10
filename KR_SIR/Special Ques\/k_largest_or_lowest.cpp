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

int min_of_two(hptr HP, int i, int j){
    if(HP->H[i] < HP->H[j]) return i;
    else return j;
}

int max_of_two(hptr HP, int i, int j){
    if(HP->H[i] > HP->H[j]) return i;
    else return j;
}

void delete_node(hptr HP){
    cout<< HP->H[0]<< " ";
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

void delete_node2(hptr HP){
    cout<< HP->H[0]<< " ";
    HP->H[0] = HP->H[HP->size-1];
    HP->size--;
    int n = HP->size, i = 0;

    while(i < (n-1)/2){
        
        if(HP->H[i] < HP->H[2*i + 1] && HP->H[i] < HP->H[2*i + 2]){
            int now = max_of_two(HP,2*i+1,2*i+2);
            swap(HP->H[i],HP->H[now]);
            i = now;
        }
        else if(HP->H[i] > HP->H[2*i + 1] && HP->H[i] < HP->H[2*i + 2]){
            swap(HP->H[i],HP->H[2*i + 2]);
            i = 2*i + 2;
        }
        else if(HP->H[i] < HP->H[2*i + 1] && HP->H[i] > HP->H[2*i + 2]){
            swap(HP->H[i],HP->H[2*i + 1]);
            i = 2*i + 1;
        }
        else    break;
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
    cout<< "Enter the value of k: ";
    int k;
    cin>>k;

    int temp = k;
    while(temp--)
        delete_node(HPm);
    cout<<endl;
    temp = k;
    while(temp--)
        delete_node2(HPM);
    cout<< endl;
    return 0;
}