#include <iostream>

using namespace std;

struct list1 {
    int data;
    list1 *dlink;
    list1 *next;
};

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

            lptr1 T = new list1;
            T->next = NULL;
            T->data = x;

            if(flag == 0){
                TML->dlink = T;
                flag = 1;
            }

            else{

                lptr1 T1 = TML->dlink;

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
            lptr1 T = ML->dlink;

            while(T != NULL){
                cout<< T->data << " ";
                T = T->dlink;
            }
        }
        print(ML->next);
    }
}

void connect(lptr1 ML1, lptr1 ML2){
    

    while(ML1 != NULL){

        if(ML2->dlink != NULL && ML2->dlink->data > ML1->data){
            cout<< ML1->data << " " << ML2->dlink->data << " ";
            ML2 = ML2->dlink;
            ML1 = ML1->dlink;
        }

        else if(ML2->dlink != NULL && ML2->dlink->data < ML1->data){
            ML2 = ML2->dlink;
        }

        else if(ML2->dlink == NULL){
            break;
        }
    }

}

void sort(lptr1 ML){
    lptr1 TML = ML;
    lptr1 T1;
    lptr1 T2;
    int flag = 0;

    while(TML != NULL){

        cout<< TML->data << " ";

            if(TML->dlink != NULL){
                
                if(flag == 1){
                    connect(T1,TML);
                }

                    T1 = TML;
                    T2 = NULL;
                
                while(T1 != NULL){
                    //T2 = T1;
                    T1= T1->dlink;
                    flag = 0;
                    //if(T1 != NULL)
                    //cout<< T1->data<< " ";

                    if(T1 != NULL && T1->data > TML->next->data){
                        flag = 1;
                        //T2->dlink = NULL;                        
                        break;
                    }
                }

            }

            else if(TML->dlink == NULL && flag == 1){
                while(T1 != NULL){
                    cout<< T1->data << " ";
                    T1 = T1->dlink;    
                }
                flag = 0;
            }

        TML = TML->next;
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
    sort(ML);
    //print(ML);
    cout<< endl;

    return 0;
}