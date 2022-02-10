#include <iostream>

using namespace std;

struct RPLL{
    int data;
    int mark;
    int num;
    RPLL *next[2];
};

typedef RPLL *lptr;

void link(int *prev_ran, lptr ML, int n);

void insert(lptr ML, int *prev_ran, int i){

    int x, next_x, random;
    cin>>x >>next_x >>random;

    if(next_x != 0 || random != 0){

        lptr T = new RPLL;
        T->next[0] = T->next[1] = NULL;
        T->data = x;
        T->mark = 0;
        T->num = 1;

        lptr TML = ML;

        while(TML->next[0] != NULL)
            TML = TML->next[0];
                
        TML->next[0] = T;

        if(random == 0)
            insert(ML,prev_ran,i);
  
        else{
            int j = i;

            prev_ran[j++] = x;  
            prev_ran[j++] = next_x; 
            prev_ran[j++] = random;

            insert(ML,prev_ran,j);
        }
    }

    else{

            lptr TML = ML;
            while(TML->next[0] != NULL)
                TML = TML->next[0];

            lptr T = new RPLL;
            T->next[0] = T->next[1] = NULL;
            T->data = x;    
            T->mark = 0;
            T->num = 1;            
            TML->next[0] = T;
    }
    link(prev_ran, ML, i);
}

void link(int *prev_ran, lptr ML, int n){

    lptr TML;
    lptr T;
    int l = 2;
    for(int i=1;i<n;i=i+3){
        
        TML = ML;
        T = NULL;
        while(TML->data != prev_ran[i]){
            T = TML;
            TML = TML->next[0];
        }
        T->next[1] = TML->next[0];
        T->num = l++;
    }
}

void print(lptr ML, int i){

    if(ML != NULL){

        cout<< ML->data << " ";

        if(ML->num == i)
            print(ML->next[1],i);
        
        else
            print(ML->next[0],i);

    }
}

void print1(lptr ML, int i){

    if(ML != NULL && i > 1){

        cout<< ML->data << " ";

        if((ML->num == i || ML->num == i+1 || ML->num == i+2))
            print1(ML->next[1],i);
        
        else
            print1(ML->next[0],i);

    }
}

void operate(lptr ML, int max){

    if(max > 1){
        cout<< endl;
        print(ML,max);
        cout<< endl;
        print1(ML,max-2);
        operate(ML,max-1);
    }
}

int main(){
    lptr ML = new RPLL;

    ML->data = 0;
    ML->next[0] = ML->next[0] = NULL;
    int *A = new int[30];

    int i = 0;
    insert(ML,A,0);
    ML = ML->next[0];
    
    operate(ML, 5);
    cout<< endl;
    
    return 0;
}