#include <iostream>

using namespace std;

struct list1 {
    int data;
    int mark;
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
            T->mark = 0;

            cin>>tag;
            insert(ML,tag, flag);
        }

        else if(tag == 1 && x != -1){

            lptr1 T = new list1;
            T->next = NULL;
            T->data = x;
            T->mark = 0;

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

void make_discover(lptr1 ML){
    ML->mark = 1;
}

bool discovered(lptr1 ML){
    if(ML->mark == 1)
        return true;
    else 
        return false;
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

void min_ele(lptr1 ML, int &min, lptr1 &ptr){

    if(ML != NULL){

        if(ML->data < min && !discovered(ML)){
            min = ML->data;
            ptr = ML;
        }

        if(ML->dlink != NULL){
            lptr1 T = ML->dlink;

            while(T != NULL){
                if(T->data < min && !discovered(T)){
                    min = T->data;
                    ptr = T;
                }

                T = T->dlink;
            }
        }
        min_ele(ML->next, min, ptr);
    }
}

void counter(lptr1 ML, int &count){

    if(ML != NULL){
        count++;

        if(ML->dlink != NULL){
            lptr1 T = ML->dlink;

            while(T != NULL){
                count++;
                T = T->dlink;
            }
        }
        counter(ML->next,count);
    }
}

// void sort(lptr1 ML){
//     lptr1 T = ML;
//     int count = 0;
//     counter(T,count);

//     lptr1 ptr;
//     int min = 123457;

//     while(count--){

//         min = 123457;
//         min_ele(ML,min,ptr);
//         cout<< min << " ";
//         make_discover(ptr);

//     }
// }

lptr1 min(lptr1 Td, lptr1 Tn, int &flag){


        if( Td->data < Tn->data){
                //cout<< Td->data << " " << endl;
                //min(Td->dlink, Tn,1);
                flag = 1;
                return Td;
            
            //min(Td->dlink, Tn,1);
        }

        else if(Td->data > Tn->data){
                //cout<< Tn->data << " " << endl;
                //min(Td, min(Tn->dlink, Tn->next,1),0);
                flag = 2;
                return Tn;
            
            //min(Td, min(Tn->dlink, Tn->next,1),0);
        }
        //min(Td->dlink, Tn->next,0);
        else{
            flag = 3;
            lptr1 temp = new list1;
            temp->data = 5;
            return (temp);
        }

}

void sort(lptr1 ML){

    lptr1 Td = ML->dlink;   lptr1 Tn = ML->next;
    int flag = 0;


    cout<< min(Td, Tn, flag)->data;

    if(flag == 1)
        Td = Td->dlink;

    else if(flag == 2)
        Tn = min(Tn->dlink, Tn->next, flag);

    if(Td == NULL)
        ML = ML->next;
        Td = Tn->dlink->dlink;

    if(Tn == NULL)
    Tn = ML->next->dlink;


    cout<< min(Td,min(Tn->dlink, Tn->next, flag), flag)->data;
    Td = Td->dlink;

    cout<< min(Td,min(Tn->dlink, Tn->next, flag), flag)->data;

    cout<< min(Td,min(Tn->dlink, Tn->next, flag), flag)->data;

    cout<< min(Td,min(Tn->dlink, min(Tn->next->dlink, Tn->next->next, flag), flag), flag)->data;

    cout<< min(Td,min(Tn->dlink->dlink, min(Tn->next->dlink, Tn->next->next, flag), flag), flag)->data;
    Td = Td->dlink;
    //Td = NULL
    
    cout<< min(Tn->dlink->dlink ,min(Tn->next->dlink, Tn->next->next, flag), flag)->data;

    cout<< min(Tn->dlink->dlink ,min(Tn->next->dlink->dlink, Tn->next->next, flag), flag)->data;
    //Tn->next->next->next == NULL

    cout<< min(Tn->dlink->dlink ,Tn->next->dlink->dlink, flag)->data;
    //Tn->dlink->dlink->dlink = NULL
    //Tn->next->dlink->dlink->dlink = NULL
}

// int min(lptr1 Td, lptr1 Tn){

//     if(Td->data < Tn->data)
//         return Td->data;
    
//     else
//         return Tn->data;
    
// }

// void sort(lptr1 ML){
//     lptr1 Td = ML->dlink;
//     lptr1 Tn = ML->next;

//     int val1 = Td->data;
//     int val2 = Tn->data;

//     while(Tn != NULL || Td != NULL){

//         if(Td != NULL && val1 < val2){
//             cout<< Td->data << " ";
//             Td = Td->dlink;

//             if(Td != NULL)
//                 val1 = Td->data;
//         }

//         else if(Tn != NULL && val1 > val2){
//             cout<< Tn->data << " ";
//             int flag = 0;

//             if(Tn->next != NULL && Tn->dlink != NULL)
//                 val2 = min(Tn->dlink, Tn->next);
            
//             if(flag == 0)
//                 Tn = Tn->next;
//             //else
//         }

//     }
    
// }

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
    cout<< ML->data << " " << endl;

    sort(ML);
    cout<< endl;
    
    return 0;
}