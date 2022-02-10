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

int max_term2(int *A, int n){
    int max = A[0];

    for(int i=1;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;    
}


void bucket_sort(lptr1 ML, int n, int num, int denom){
    
    lptr1 bucket[10];

    // for(int i=0;i<10;i++){
    //     bucket[i] = new list2;
    //     bucket[i]->dlink = NULL;
    // }

    lptr1 TML = ML;
    for(int j=1;j<=10;j++){
        for(int i=0;i<n;i++)
            if( (TML->data/denom)%num < j && (TML->data/denom)%num >= (j-1) )
                TML->next = bucket[j];
    }

        int i = 0;
        for(int j=0;j<10;j++){
            while(q[j].f != -1){
                A[i++] = dequeue(q[j]);
                //cout<<A[i-1]<<"--------A[i]"<<endl;
            }
        }
}

int *radix_sort(int *A, int n){

    int *B =new int [n];
    int max = max_term2(A,n)*10;
    int denom = 1, num = 10;

    while(max>0){
        bucket_sort(A,n,num,denom);
        denom*=10;
        max = max/10;
    }
    // for(int i=0;i<n;i++)
    //     B[i] = A[n-1-i];

    return A;
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