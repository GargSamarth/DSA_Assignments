#include <iostream>

using namespace std;

struct RPLL{
    int data;
    RPLL *next[2];
};

typedef RPLL *lptr;

void insert(lptr ML, int *prev_ran, int i){

    int x, next_x, random;
    cin>>x >>next_x >>random;

    if(next_x != 0 || random != 0){

        lptr T = new RPLL;
        T->next[0] = T->next[1] = NULL;
        T->data = x;

        lptr TML = ML;

        while(TML->next[0] != NULL)
            TML = TML->next[0];
                
        TML->next[0] = T;

        if(random == 0)
            insert(ML,prev_ran,i);
  
        else{
            prev_ran[i++] = x;  
            prev_ran[i++] = next_x; 
            prev_ran[i++] = random;
        }
    }

    else{

            lptr TML = ML;
            while(TML->next[0] != NULL)
                TML = TML->next[0];

            lptr T = new RPLL;
            T->next[0] = T->next[1] = NULL;
            T->data = x;                
            TML->next[0] = T;
    }
    
    link(prev_ran, ML, i);
}

void link(int *prev_ran, lptr ML, int n){

    lptr TML;
    lptr T;
    for(int i=1;i<n;i+=3){
        
        TML = ML;
        T = NULL;
        while(TML->data != prev_ran[i]){
            T = TML;
            TML = TML->next[0];
        }
        T->next[1] = TML->next[0];
    }
}