#include <iostream>

using namespace std;

struct list2{
    int data;
    list2 *dlink;
};

struct list1 {
    int data;
    list2 *dlink;
    list1 *next;
};

typedef list2 *lptr2;
typedef list1 *lptr1;

void insert(lptr1 ML, int tag, int flag){
    static int x;

    if(x != -2){

        lptr1 TML = ML;
        while(TML->next != NULL)
        TML = TML->next;
        
        cin>>x;

        if(tag == 0 && x != -2){

            lptr1 T = new list1;
            
            T->data = x;
                
            TML->next = T;
            T->next = NULL;
            T->dlink = NULL;

            cin>>tag;
            insert(ML,tag, flag);
        }

        else if(tag == 1 && x != -1){

            lptr2 T = new list2;
            T->data = x;

            if(flag == 0){
                TML->dlink = T;
                flag = 1;
            }

            else{

                lptr2 T1 = TML->dlink;

                while(T1->dlink != NULL)
                    T1 = T1->dlink;

                T1->dlink = T;
            }

            T->dlink = NULL;
            insert(ML,1, flag);
        }

        if(x != -2)
            insert(ML,0,0);
        
    }
    return ;
}

void print(lptr1 ML){

    if(ML != NULL){

        cout<< ML->data<< " ";

        if(ML->dlink != NULL){

            lptr2 T = ML->dlink;

            while(T != NULL){
                cout<< T->data << " ";
                T = T->dlink;
            }

        }

        print(ML->next);
    }

}

int main(){
    lptr1 ML = new list1;
    int tag;
    char ch;

    ML->data = 0;
    ML->next = NULL;
    ML->dlink = NULL;

    insert(ML,0,0);
    ML = ML->next;
    print(ML);
    cout<< endl;

    return 0;
}