#include <iostream>

using namespace std;

struct multi_ll{
    int tag;
    int mark;
    union {
        int idata;
        multi_ll *dlink;
    }data;
    multi_ll *next;
};

//type_define
typedef multi_ll *lptr;


void insert(lptr ML, int tag){

    if(tag != 0){

        lptr T = new multi_ll;
        
        if(tag == 1){
            int x;
            cin>>x;
            T->data.idata = x;
            T->tag = 1;
            T->mark = 0;
        }

        else if(tag == 2){

            lptr T2 = new multi_ll;
            T2->next = NULL;
            T2->data.idata = 0;
            insert(T2,1);
            T2 = T2->next;
            T->data.dlink = T2;
            T->tag = 2;

        }

        while(ML->next != NULL)
            ML = ML->next;

        ML->next = T;
        T->next = NULL;

        if(tag == 1)
            cin>>tag;

        else
            tag = 1;

        if(tag != 0)
            insert(ML,tag);
        
    }
    return ;
}

void make_discover(lptr ML){
    ML->mark = 1;
}

bool discovered(lptr ML){
    if(ML->mark == 1)
        return true;
    else 
        return false;
}

void print(lptr ML, int des){

    if(ML != NULL){

        if( ML->tag == 1){
            if(ML->data.idata <= des)
                cout<< ML->data.idata << " ";
        }

        else {

            if(ML->next->data.idata > des)
                print(ML->data.dlink,des);

        }

        // if(ML->tag == 1 && ML->data.idata == des)
        //     flag = 2;

        print(ML->next,des);
    }
}

void find(lptr ML, int k, lptr &ptr){
    if(ML != NULL){
        if(ML->tag == 1){
            if(ML->data.idata == k){
                ptr = ML;
                return;
            }
        }

        else{
            find(ML->data.dlink,k,ptr);
        }

        find(ML->next,k,ptr);
    }

}

void target(lptr ML, int s, int t){
    int count = 1;

    lptr T = ML;
    lptr ptr;

    find(T, s, ptr);

    print(ptr,t);
    cout<< endl;

}

int main(){
    lptr ML = new multi_ll;

    ML->mark = 0;
    ML->next = NULL;
    ML->data.dlink = NULL;

    insert(ML,1);
    ML = ML->next;
    int s, t;
    cin>>s>>t;
    target(ML,s,t);
    // cin>>s>>t;
    // target(ML,s,t);

    cout<< endl;

    return 0;
}

//1 1 2 1 3 2 4 1 5 2 6 1 7 0 8 1 9 0 10 1 11 1 12 2 13 1 14 1 15 1 16 0 17 1 18 0