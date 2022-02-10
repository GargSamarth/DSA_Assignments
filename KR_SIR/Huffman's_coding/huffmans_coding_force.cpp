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

struct node {
    node *left;
    btptr data;
    node *right;
};

//define
typedef node *lptr;

void insert_dll(lptr T, btptr k){
    lptr T1 = new node;
    T1->data = k;
    T1->left = T1->right = NULL;
        while(T->right != NULL)
            T = T->right;
        T->right = T1;
        T1->left = T;
}
void min_freq(lptr &DL, lptr &min1, lptr &min2){
    lptr T = DL;
    int min = 9542;
    while(T != NULL){
        if(T->data->freq < min){
            min = T->data->freq;
            min1 = T;
        }
        T = T->right;
    }
    if(min1->left == NULL){
        DL = DL->right;
        if(DL != NULL)
            DL->left = NULL;
        min1->right = NULL;
    }
    else{
        min1->left->right = min1->right;
        if(min1->right != NULL)
            min1->right->left = min1->left;
        min1->left = min1->right = NULL;
    }
    min = 9654;
    T = DL;
    while(T != NULL){
        if(T->data->freq < min){
            min = T->data->freq;
            min2 = T;
        }
        T = T->right;
    }
    if(min2->left == NULL){
        DL = DL->right;
        if(DL != NULL)
            DL->left = NULL;
        min2->right = NULL;
    }
    else{
        min2->left->right = min2->right;
        if(min2->right != NULL)
            min2->right->left = min2->left;
        min2->left = min2->right = NULL;
    }
}
void insert(lptr min1, lptr min2, lptr &DLL){
    btptr T1 = min1->data;
    btptr T2 = min2->data;
    btptr P = new btnode;
    P->data = 'T';
    P->freq = T1->freq + T2->freq;
    P->lchild = T2;
    P->rchild = T1;
    if(DLL != NULL) insert_dll(DLL,P);
    else{
        DLL = new node;DLL->right = DLL->left = NULL;DLL->data = NULL;
        insert_dll(DLL,P);
        DLL = DLL->right;DLL->left->right = NULL;DLL->left = NULL;}
}
int count_nodes(lptr P){
    int count = 0;
    while(P != NULL){
        count++;
        P = P->right;
    }
    return count;
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
    if(ch == '0'){
        T = T->lchild;
    }
    else if(ch == '1'){
        T = T->rchild;
    }
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
    lptr DLL = new node;
    DLL->right = DLL->left = NULL;
    DLL->data = NULL;
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
        insert_dll(DLL,T);
    }
    DLL = DLL->right;
    DLL->left->right = NULL;
    DLL->left = NULL;

    while(count_nodes(DLL) > 1){
        lptr min1 = NULL, min2 = NULL;
        min_freq(DLL,min1,min2);
        insert(min1,min2,DLL);
    }
    btptr TREE = DLL->data;
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
    else{
        cout<< "Wrong input please try again"<< endl;
    }
    return 0;
}

//00101110011100010001