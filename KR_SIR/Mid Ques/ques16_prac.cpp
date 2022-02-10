#include <iostream>
using namespace std;

struct Heap{
    char HC[30];
    int freq[30];
    int size;
    Heap *tree[20];
};

//define
typedef Heap *hptr;

void swap1(char &a, char &b){
    char temp = a; a = b; b = temp;
}

void swap2(int &a, int &b){
    int temp = a; a = b; b = temp;
}

void swap3(hptr &a, hptr &b){
    hptr temp = a; a = b; b = temp;
}

void construct_min(hptr &HP, hptr P){
    HP->freq[HP->size] = P->freq[0];
    HP->HC[HP->size] = P->HC[0];
    HP->size++;
    int i = HP->size-1;
    while(i > 0){
        if(HP->freq[i] > HP->freq[(i-1)/2])   break;
        else{    
            swap1(HP->HC[i],HP->HC[(i-1)/2]);
            swap2(HP->freq[i],HP->freq[(i-1)/2]);
        }
        i = (i-1)/2;
    }
}

void construct2(hptr &HP, hptr P){
    HP->tree[HP->size++] = P;
    int i = HP->size-1;
    while(i > 0){
        if(HP->freq[i] > HP->freq[(i-1)/2])   break;
        else{    
            swap3(HP->tree[i],HP->tree[(i-1)/2]);
        }
        i = (i-1)/2;
    }
}

int min_of_two(hptr HP, int i, int j){
    if(HP->freq[i] < HP->freq[j]) return i;
    else return j;
}

hptr delete_node(hptr &HP){
    hptr rt;    rt->size = 0;
    rt->freq[0] = HP->freq[0];
    rt->HC[0] = HP->HC[0];

    HP->HC[0] = HP->HC[HP->size-1];
    HP->freq[0] = HP->freq[HP->size-1];
    HP->size--;

    int n = HP->size, i = 0;
    while(i < (n-1)/2){
        if(HP->freq[i] > HP->freq[2*i + 1] && HP->freq[i] > HP->freq[2*i + 2]){
            int now = min_of_two(HP,2*i+1,2*i+2);
            swap2(HP->freq[i],HP->freq[now]);
            swap1(HP->HC[i],HP->HC[now]);
            i = now;
        }
        else if(HP->freq[i] < HP->freq[2*i + 1] && HP->freq[i] > HP->freq[2*i + 2]){
            swap1(HP->HC[i],HP->HC[2*i + 2]);
            swap2(HP->freq[i],HP->freq[2*i + 2]);
            i = 2*i + 2;
        }
        else if(HP->freq[i] > HP->freq[2*i + 1] && HP->freq[i] < HP->freq[2*i + 2]){
            swap1(HP->HC[i],HP->HC[2*i + 1]);
            swap2(HP->freq[i],HP->freq[2*i + 1]);
            i = 2*i + 1;
        }
        else    break;
    }
    return rt;
}

void insert(hptr h1, hptr h2, hptr &HP){
    hptr P = new Heap;
    P->size = 0;
    P->HC[P->size] = 'T';
    P->freq[P->size] = h1->freq[h1->size] + h1->freq[h1->size];
    P->size++;
    if(h1->freq[h1->size] < h2->freq[h2->size]){
        construct2(P, h2);
        construct2(P, h1);
    }
    else{
        construct2(P, h1);
        construct2(P, h2);
    }
    construct2(HP,P);
}

void min_freq(hptr &HP, hptr &h1, hptr &h2){
    h1 = delete_node(HP);
    h2 = delete_node(HP);
}

int main(){ 
    hptr HP = new Heap;
    HP->size = 0;
    cout<< "Enter the number of letters you want to add ";
    int n,freq;
    char data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data>>freq;
        hptr T = new Heap;
        T->size = 0;
        T->HC[T->size] = data;
        T->freq[T->size] = freq;
        T->size++;
        construct_min(HP,T);
    }
    while(HP->size > 1){
        hptr min1 = NULL, min2 = NULL;
        min_freq(HP,min1,min2);
        insert(min1,min2,HP);
    }
    hptr TREE = delete_node(HP);
    return 0;
}
