#include <iostream>

using namespace std;

union U
{
    char cno[10];
    int hno;
};


struct st{
    int rno;
    int tag;
    U adr;
};

int main(){

    st *S[5];

    for(int i=0;i<5;i++){

        S[i] = new st;
        cout<< "Enter the value of rno: ";
        cin>> S[i]->rno;
        cout<< endl << "Enter 0 for char and 1 for int: ";
        cin>> S[i]->tag;
        cout<< endl;
        
        if(S[i]->tag == 0){
            for(int j=0;j<10;j++)
                cin>>S[i]->adr.cno[j];
        }            

        else
            cin>>S[i]->adr.hno;
    }

    //output
    cout<< "---------------------output------------------------------"<<endl;

    for(int i=0;i<5;i++){
        cout<< S[i]->rno << " ";
        
        if(S[i]->tag == 0){
            for(int j=0;j<10;j++)
                cout<<S[i]->adr.cno[j];
        }            

        else
            cout<<S[i]->adr.hno;
        
        cout<< endl;
    }

 return 0;   
}