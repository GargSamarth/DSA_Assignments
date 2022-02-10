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

void insert(lptr ML, int tag, int mark){
    static int x=0;

    if(x != -1){

        lptr TML = ML;
        while(TML->next != NULL)
            TML = TML->next;
        cin>>x;

        if(tag == 0 && x != -1){

           lptr T = new multi_ll;
            T->data = x;
            TML->next = T;
            T->next = NULL;
            T->dlink = NULL;
            T->mark = mark;
            //cout<< mark << "----mark----"<< endl;
            cin>>tag;

            if(tag == 0)
                insert(ML,tag,mark);
            else if(tag == 1)
                insert(ML,tag,mark+1);
        }

        else if(tag == 1 && x != -1){

            lptr T2 = new multi_ll;
            T2->next = NULL;
            T2->dlink = NULL;
            T2->data = x;
            T2->mark = mark;
            //cout<< mark << "----mark----"<< endl;
            TML->dlink = T2;
            cin>>tag;

            if(tag == 0)
                insert(T2,tag,mark);
            else if(tag == 1)
                insert(T2,tag,mark+1);
            
            mark--;
            x = 0;
        }

        if(x != -1)
            insert(ML,0,mark);
        
    }
    return ;
}

void out(lptr ML, int mark){

    if(ML != NULL){

        if(ML->mark == mark)
            cout<< ML->data << " ";
        
        if(ML->dlink != NULL)
            out(ML->dlink, mark);
        

        out(ML->next, mark);
    }
}

void remark(lptr ML, int mark){
    if(ML != NULL){
        
        ML->mark = mark;

        if(ML->dlink != NULL)
            remark(ML->dlink, mark+1);
        

        remark(ML->next, mark);
    }
}

void count_max(lptr ML, int &max){

    if(ML != NULL){

        if(ML->mark > max)
            max = ML->mark;

        if(ML->dlink != NULL)
            count_max(ML->dlink, max);

        count_max(ML->next, max);
    }
}

void print(lptr ML){

    int count=0, max = 0;
    lptr T = ML;
    count_max(T, max);
    
    while(count <= max){
        out(ML, count);
        count++;
    }

}

void print2(lptr ML){

    if(ML != NULL){
        
        cout<< ML->data << " ";

        if(ML->dlink != NULL)
            print2(ML->dlink);
        

        print2(ML->next);
    }
}

void reverse_print(lptr ML){
    if(ML != NULL){
        
        lptr temp = ML->next;
        ML->next = ML->dlink;
        ML->dlink = temp;

        if(ML->next != NULL)
            reverse_print(ML->next);
        

        reverse_print(ML->dlink);
    }
}

int main(){
    lptr ML = new multi_ll;
    int tag;
    char ch;

    ML->data = 0;
    ML->next = NULL;
    ML->dlink = NULL;

    tag = 0;
    insert(ML,tag,0);
    ML = ML->next;
    reverse_print(ML);
    remark(ML,0);
    print(ML);
    cout<< endl;
    print2(ML);
    cout<< endl;

    return 0;
}
