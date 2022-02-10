
#include <iostream>

using namespace std;

struct gtnode{
    char data;
    int cno;
    int i;
    gtnode *fc;
    gtnode *ns;
};

typedef gtnode* gtptr;

void insert(gtptr &GT, char ch, int n){
    if(GT == NULL){
        GT = new gtnode;
        GT->data = ch;
        GT->cno = n;
        GT->i = 0;
        GT->fc = GT->ns = NULL;
        if(n == 0)
            return;
    }
    cin>>ch>>n;
    if(n != 0){
        GT->i++;
        insert(GT->fc,ch,n);
        n = 0;
    }  
    if(n == 0){
        if(GT->fc == NULL){
            insert(GT->fc,ch,n);
            GT->i++;
        }
        
        while(GT->i <= GT->cno){
            cin>>ch>>n;
            GT->i++;
            gtptr temp = GT->fc;
            while(temp != NULL)
                temp = temp->ns;
            insert(temp,ch,n);
        }
        return;
    }
}

// Serialisation
void print_serial(gtptr GT){
    if(GT != NULL){
        cout<< GT->data;
        print_serial(GT->fc);
        print_serial(GT->ns);
    }
    else
        cout<< ".";
}

int main(){

    char ch;
    gtptr GT = NULL;
    int n;
    cin>> ch >> n;
    if(ch != '.')
        insert(GT, ch,n);
    print_serial(GT);
    cout<< endl;

    return 0;
}