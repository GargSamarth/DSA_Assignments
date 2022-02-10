#include <iostream>

using namespace std;

struct multi_ll{
    int data;
    int mark;
    multi_ll *dlink;
    multi_ll *next;
};

//type_define
typedef multi_ll *lptr;

void insert(lptr ML, int tag){

    if(tag != 0){

        lptr TML = ML;
        while(TML->next != NULL)
            TML = TML->next;

        int x;
        cin>>x;

        if(tag == 1){

           lptr T = new multi_ll;
            T->data = x;
            TML->next = T;
            T->next = NULL;
            T->dlink = NULL;
            T->mark = 0;
            cin>>tag;

            if(tag != 0)
                insert(ML,tag);
        }

        else if(tag == 2){

            lptr T2 = new multi_ll;
            T2->next = NULL;
            T2->dlink = NULL;
            T2->data = x;
            T2->mark = 0;
            TML->dlink = T2;
            cin>>tag;
            insert(T2,tag);
        }

        if(tag != 0)
            insert(ML,1);
        
    }
    return ;
}

void count_max(lptr ML, int &max){

    if(ML != NULL){

        if(ML->dlink != NULL){
            count_max(ML->dlink, max);
            max++;
        }
        count_max(ML->next, max);
    }
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

void print(lptr ML, int flag){
    static lptr T;

    if(flag == 1)
        T = ML;

    if(ML != NULL){

        cout<< ML->data << " ";

        if(ML->dlink != NULL && !discovered(ML->dlink)){
                print(ML->dlink,1);
                make_discover(T);
        }

        else
            print(ML->next,0);
    }
}

void target(lptr ML){
    int count = 1;
    count_max(ML,count);

    lptr T = ML;

    while(count--){
        print(T, 1);
        cout<< endl;
    }
}

int main(){
    lptr ML = new multi_ll;

    ML->data = 0;
    ML->next = NULL;
    ML->dlink = NULL;

    insert(ML,1);
    ML = ML->next;
    target(ML);
    cout<< endl;

    return 0;
}

//1 1 2 1 3 2 4 1 5 2 6 1 7 0 8 1 9 0 10 1 11 1 12 2 13 1 14 1 15 1 16 0 17 1 18 0