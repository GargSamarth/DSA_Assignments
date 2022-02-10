#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[50];
};

void enqueue(queue &q, int s){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = s;
    }
}

int dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return 0;
    }
    else{
        int s = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return s;
    }
}

int evaluate(int opr1,int opr2, char oprd){
    switch(oprd){
        case '+': return opr1+opr2;
                break;
        case '-': return opr1-opr2;
                break;
        case '*': return opr1*opr2;
                break;
        case '/': return opr1/opr2;
                break;
        default: return -12365;
                break;
    }
}

int evaluate_prefix(char *ch, int n){
    
    queue q;
    q.r = q.f = -1;

    q.size = n;

    for(int i=0;i<n;i++){
        enqueue(q,ch[i]);
    }

    int j=0,flag = 1;
    char a,b,c;

    while(q.r != q.f){

        
        if( flag == 1){
            a = dequeue(q);
            b = dequeue(q);
            c = dequeue(q);
        }
        else if(flag == 0)
            c = dequeue(q);

        if( ((int(a) > 47) && (int(a) < 58)) && ((int(b) > 47) && (int(b) < 58)) && ((int(a) > 41) && (int(a) < 48)) ){

            int temp1 = evaluate(int(a)-48, int(b)-48, c) + 48;
            char temp2 = (char)temp1;
            enqueue(q,temp2);
            flag = 1;

        }

        else if( ((int(a) > 41) && (int(a) < 48)) && ((int(b) > 47) && (int(b) < 58)) && ((int(a) > 47) && (int(a) < 58)) ){

            int temp1 = evaluate(int(b)-48, int(c)-48, a) + 48;
            char temp2 = (char)temp1;
            enqueue(q,temp2);
            flag = 1;
        }
            
        else{
            flag = 0;
            enqueue(q,a);
            a = b;
            b = c;
        }
    }

    int ans = int(dequeue(q))-48;
    return ans;
}

 int main(){
    
    char *A = new char [30];

    int j=0;

    while(A[j-1] != '#')
        cin>> A[j++];


    int ans = evaluate_prefix(A,j-1);

    cout<< ans << endl;
    return 0;
 }