#include <iostream>

using namespace std;

union U{
    int x;
    char ch;
};

struct for_tags{
    int tag;
    U un;
};

struct queue{
    int size;
    int f;
    int r;
    for_tags elements[50];
};

void enqueue(queue &q, for_tags ft){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = ft;
    }
}

for_tags dequeue(queue &q){
    for_tags temp;

    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        //temp.x = -1;    temp.ch = '-1';
        return temp;
    }
    else{
        temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
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

int evaluate_prefix(queue &q, int n){

    int j=0,flag = 1;
    for_tags a,b,c;

    while( 1>0){

        
        if( flag == 1){
            a = dequeue(q);
            b = dequeue(q);
            c = dequeue(q);
        }
        else if(flag == 0)
            c = dequeue(q);

        if( a.tag == 0 && b.tag == 1 && c.tag == 1 ){

            for_tags temp1; 
            temp1.tag = 1;
            temp1.un.x = evaluate(b.un.x, c.un.x, a.un.ch);
            //cout<< b.un.x << " -- " << c.un.x << " -- " << a.un.ch << " -- "<<endl;
            //cout<< temp1.un.x << "  --------------evaluation----------"<<endl;
            flag = 1;
            if(q.f == -1)
            flag = 8;
            enqueue(q,temp1);
            
        }
            
        else{
            flag = 0;
            enqueue(q,a);
            a = b;
            b = c;
        }

        if(flag == 8)
            break;
    }

    int ans = dequeue(q).un.x;
    //cout<< q.f << "= q.f" << q.r << "= q.r"<<endl;
    return ans;
}

 int main(){
    
    char *A = new char [30];

    int j=0;

    while(A[j-1] != '#')
        cin>> A[j++];

    queue q;
    q.r = q.f = -1;
    q.size = 20;

    for(int i=0;i<j-1;i++){
        for_tags temp;
        if( ((int(A[i]) > 47) && (int(A[i]) < 58)) ){
            temp.tag = 1;
            temp.un.x = int(A[i])-48;
        }
        else{
            temp.tag = 0;
            temp.un.ch = A[i];
        }
            enqueue(q,temp);
    }
    //cout<< q.f << "= q.f" << q.r << "= q.r"<<endl;

    cout<< evaluate_prefix(q,j-1) << endl;
    return 0;
 }