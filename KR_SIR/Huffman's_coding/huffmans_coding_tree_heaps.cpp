#include <iostream>
using namespace std;

struct btnode {
    btnode *lchild;
    char data;
    int freq;
    btnode *rchild;
};

//define 
typedef btnode *btptr;

struct Heap{
    btptr H[30];
    int size;
};

//define
typedef Heap *hptr;

void swap(btptr &a, btptr &b){
    btptr temp = a; a = b; b = temp;
}
void construct_min(hptr &HP, btptr P){
    HP->H[HP->size++] = P;
    int i = HP->size-1;
    while(i > 0){
        if(HP->H[i]->freq > HP->H[(i-1)/2]->freq)   break;
        else    swap(HP->H[i],HP->H[(i-1)/2]);
        i = (i-1)/2;}
}
int min_of_two(hptr HP, int i, int j){
    if(HP->H[i]->freq < HP->H[j]->freq) return i;
    else return j;
}
btptr delete_node(hptr &HP){
    btptr rt = HP->H[0];
    HP->H[0] = HP->H[HP->size-1];
    HP->size--;
    int n = HP->size, i = 0;
    while(i < (n-1)/2){
        if(HP->H[i]->freq > HP->H[2*i + 1]->freq && HP->H[i]->freq > HP->H[2*i + 2]->freq){
            int now = min_of_two(HP,2*i+1,2*i+2);
            swap(HP->H[i],HP->H[now]);
            i = now;
        }
        else if(HP->H[i]->freq < HP->H[2*i + 1]->freq && HP->H[i]->freq > HP->H[2*i + 2]->freq){
            swap(HP->H[i],HP->H[2*i + 2]);
            i = 2*i + 2;
        }
        else if(HP->H[i]->freq > HP->H[2*i + 1]->freq && HP->H[i]->freq < HP->H[2*i + 2]->freq){
            swap(HP->H[i],HP->H[2*i + 1]);
            i = 2*i + 1;
        }
        else    break;
    }
    return rt;
}
void min_freq(hptr &DL, btptr &min1, btptr &min2){
    min1 = delete_node(DL);
    min2 = delete_node(DL);
}
void insert(btptr min1, btptr min2, hptr &DLL){
    btptr T1 = min1;
    btptr T2 = min2;
    btptr P = new btnode;
    P->data = 'T';
    P->freq = T1->freq + T2->freq;
    P->lchild = T2;
    P->rchild = T1;
    construct_min(DLL,P);
}
void find_path(btptr T, string st, char ch, string &ans){
    if(T != NULL){
        if(T->data == ch){
            ans = st;
            return;
        }
        find_path(T->lchild,st+"0", ch,ans);
        find_path(T->rchild,st+"1", ch,ans);
    }
}
void encode(btptr T, string str){
    int len = str.length();
    string temp, ans="",st="";
    for(int i=0;i<len;i++){
        find_path(T,st,str[i],temp);
        ans+=temp;
    }
    cout<< ans << endl;
}
void follow_path(btptr &T, char ch, char &temp){
    if(T->rchild == NULL && T->lchild == NULL){
        temp = T->data;
        return;
    }
    if(ch == '0')
        T = T->lchild;
    else if(ch == '1')
        T = T->rchild;
}
void decode(btptr T, string str){
    int len = str.length();
    char temp = ' ';
    btptr temp1 = T;
    for(int i=0;i<=len;i++){
        follow_path(temp1,str[i],temp);
        if(i!= len-1 && temp != ' '){
            cout<< temp;
            temp = ' ';
            temp1 = T;
            i--;
        }
    }
    cout<<temp<<endl;
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
        btptr T = new btnode;
        T->data = data;
        T->freq = freq;
        T->lchild = T->rchild = NULL;
        construct_min(HP,T);
    }
    while(HP->size > 1){
        btptr min1 = NULL, min2 = NULL;
        min_freq(HP,min1,min2);
        insert(min1,min2,HP);
    }
    btptr TREE = delete_node(HP);
    cout<< "Enter 1 to decode, 2 to encode: ";
    cin>>n;
    string str;
    if(n == 1){
        cin>>str;
        decode(TREE,str);
    }
    else if(n == 2){
        cin>>str;
        encode(TREE,str);
    }
    else cout<< "Wrong input please try again"<< endl;
    return 0;
}
