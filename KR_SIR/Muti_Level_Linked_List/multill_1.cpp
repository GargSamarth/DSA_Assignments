#include <iostream>

using namespace std;

struct multi_ll{
    int tag;
    union {
        char cdata;
        multi_ll *dlink;
    }data;
    multi_ll *next;
};

//type_define
typedef multi_ll *lptr;

void insert(lptr ML, int tag, char ch){

    if(ch != '#'){
        
        lptr T = new multi_ll;

        if(tag == 1){

            T->data.cdata = ch;
            //cout<< T->data.cdata << "----";
            T->tag = 1;
        }

        else if(tag == 2){

            lptr T2 = new multi_ll;
            T2->next = NULL;
            T2->data.cdata = ' ';
            int tag1 = 1;
            insert(T2,tag1, ch);
            T2 = T2->next;
            T->data.dlink = T2;
            T->tag = 2;

        }
        else if(tag == 3){
            
            T->data.cdata = ch;
            //cout<< T->data.cdata << "----";
            T->tag = 1;

            while(ML->next != NULL)
            ML = ML->next;

            ML->next = T;
            T->next = NULL;

            return;
        }

        cin>>ch;

        if(ch == '{')
            tag = 2;
        else if(ch == '}')
            tag = 3;
        else
            tag = 1;
        
        while(ML->next != NULL)
            ML = ML->next;

        ML->next = T;
        T->next = NULL;

        if(ch != '#')
            insert(ML,tag, ch);
        
    }
    return ;
}

void print(lptr ML){
    if(ML != NULL){

        if(ML->tag == 1)
            cout<< ML->data.cdata<< " ";
        else{
            print(ML->data.dlink);
        }

        print(ML->next);
    }
}

int main(){
    lptr ML = new multi_ll;
    int tag;
    char ch;

    ML->data.cdata = 0;
    ML->next = NULL;

    cin>>ch;
    insert(ML,1, ch);
    //cin>>ch;
    ML = ML->next;
    print(ML);
    cout<< endl;

    return 0;
}