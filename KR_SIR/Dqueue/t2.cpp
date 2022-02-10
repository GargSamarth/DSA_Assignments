#include <iostream>

using namespace std;

union U{
    int x;
    char ch;
};


struct usng_tg{
    int tag;
    U un;
};

struct Dequeue{
    int size;
    int f;
    int r;
    usng_tg elements[50];
};

struct queue{
    int size;
    int f;
    int r;
    char elements[50];
};

void enqueue(queue &q, char s){
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
char dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return -1;
    }
    else{
        char s = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f++;

        return s;
    }
}

void enqueue_rear(Dequeue &q, usng_tg c){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = c;
    }
}

void enqueue_front(Dequeue &q, usng_tg c){
    if( ( q.size - 1 + (q.f) % q.size ) % q.size == q.r )
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f = q.r = q.size-1;
        }
        else{
            q.f = ( q.size - 1 + (q.f) % q.size ) % q.size;
        }
        q.elements[q.f] = c;
    }
}

usng_tg dequeue_front(Dequeue &q){
    usng_tg temp;
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
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

usng_tg dequeue_rear(Dequeue &q){
    usng_tg temp;
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return temp;
    }
    else{
        temp = q.elements[q.r];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.r = ( q.size - 1 + (q.r) % q.size ) % q.size;

        return temp;
    }
}

int main(){
    Dequeue dq;
    dq.r = dq.f = -1;
    dq.size = 10;

    int n = 10;
    //cin>>n;
    int count=0;
    string ch[10] = {"N","I","17","T","9","20","C","S","21","E"};


    for(int i=0;i<n;i++){
        
        usng_tg temp;

        if( (int(ch[i][0])>64 && int(ch[i][0])<91) || (int(ch[i][0])>96 && int(ch[i][0])<123) ){
            temp.tag = 0;
            temp.un.ch = ch[i][0];
            int samp = count;
            Dequeue q;
            q.r = q.f = -1;
            q.size = 10;
            while(samp--){
                enqueue_rear(q,dequeue_front(dq));
            }
            enqueue_front(dq,temp);
            while(q.f != -1){
                enqueue_front(dq,dequeue_rear(q));
            }
            count++;
        }
        else{
            temp.tag = 1;
            temp.un.x = stoi(ch[i]);
            enqueue_rear(dq,temp);
        }
    }

    queue q;
    q.f = q.r = -1;
    q.size = 20;

    while(count--){
        enqueue(q,dequeue_front(dq).un.ch);
    }

    while(q.f != -1){
        usng_tg spec;
        spec.tag = 0;
        spec.un.ch = dequeue(q);
        enqueue_rear(dq,spec);
    }

    for(int i=0;i<n;i++){
        usng_tg temp;
        temp = dequeue_front(dq);
        if(temp.tag == 1)
            cout<< temp.un.x<<" ";
        else
            cout<< temp.un.ch<< " ";
    }
    cout<< endl;
   

    return 0;

}