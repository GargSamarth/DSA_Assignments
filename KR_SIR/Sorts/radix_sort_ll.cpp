#include <iostream>

using namespace std;

struct multi_ll{
    int tag;
    union {
        int idata;
        multi_ll *dlink;
    }data;
    multi_ll *next;
};

//type_define
typedef multi_ll *lptr;

void insert(lptr ML, int k){

    lptr T = new multi_ll;
    T->tag = 1;
    T->data.idata = k;

    lptr P = ML;
    while(P->next != NULL)
        P = P->next;

    P->next = T;
    T->next = NULL;
}


int max_term2(lptr ML){

    int max = ML->data.idata;

    while(ML != NULL){
        if(ML->data.idata > max)
            max = ML->data.idata;
        ML = ML->next;
    }
    return max;

}

void print(lptr ML){

    if(ML != NULL){
        cout<< ML->data.idata << " ";
        print(ML->next);
    }
}

void bucket_sort(lptr &ML, int denom){

    lptr bucket[10];

    for(int i=0;i<10;i++){
        bucket[i] = new multi_ll;
        bucket[i]->next = NULL;
        bucket[i]->tag = 1;
    }

    for(int j=0;j<10;j++){

        lptr TML = ML;
        lptr TML2 = NULL;

        while(TML != NULL){

            if( (TML->data.idata/denom)%10 == j ){
                //cout<< TML->data.idata << " : data"<<endl;

                lptr T1 = bucket[j];

                while(T1->next != NULL)
                    T1 = T1->next;
                
                if(TML2 != NULL){
                    TML2->next = TML->next;
                    T1->next = TML;
                    TML->next = NULL;
                    TML = TML2->next;
                }
                else{
                    ML = ML->next;
                    T1->next = TML;
                    TML->next = NULL;
                    TML = ML;
                }
                
            }

            else{
            TML2 = TML;
            TML = TML->next;
            }

        }
    }

        int flag = 0;
        for(int j=0 ;j<10 ; j++){

            if(bucket[j]->next != NULL){

                if(flag == 0){
                    ML = bucket[j]->next;
                    //cout<< bucket[j]->next->data.idata << "-------";
                    bucket[j]->next = NULL;
                    flag = 1;
                }

                else{

                    lptr TML = ML;

                    //cout<< TML->data.idata << " :dbg--";
                    while(TML->next != NULL){
                        TML = TML->next;
                    //cout<< TML->data.idata << " :dbg--";
                    }

                    TML->next = bucket[j]->next;
                    //cout<< bucket[j]->next->data.idata << "-------";
                    bucket[j]->next = NULL;

                }
            }
        }
}

void radix_sort(lptr &ML){

    lptr TML = ML;

    int max = max_term2(TML)*10;
    //cout<< max << " : max" << endl;
    int denom = 1;

    while(max > 0){

        bucket_sort(ML,denom);
        denom*=10;
        max = max/10;
    }
}

int main(){
    int n;
    cin>>n;

    lptr ML = new multi_ll;
    ML->next = NULL;
    ML->tag = 1;

    int x;
    cin>>x;
    ML->data.idata = x;

    for(int i=0;i<n-1;i++){
        cin>>x;
        insert(ML,x);
    }
    radix_sort(ML);
    print(ML);
    cout<< endl;

    return 0;
}