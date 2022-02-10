#include <iostream>

using namespace std;

struct coordinates{
    int i;
    int j;
};

struct queue{
    int size;
    int f;
    int r;
    coordinates elements[80];
};

void enqueue(queue &q, coordinates c){
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

coordinates dequeue(queue &q){
    coordinates c;
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        c.i = c.j= -1;
        return c;
    }
    else{
        c.i = q.elements[q.f].i;
        c.j = q.elements[q.f].j;

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return c;
    }
}

void move(queue &q, int &count, coordinates end){
    
        coordinates c;
        c = dequeue(q);

        int flag = 0;
    if( c.i < end.i && c.j< end.j){
        coordinates temp;
        temp.i = c.i + 1;
        temp.j = c.j + 2;
        if((temp.i > -1 && temp.i < 8) && (temp.j > -1 && temp.j < 8)){
            enqueue(q,temp); 
            flag = 1;
        }
    }
    
    else if( c.i > end.i && c.j > end.j){
        coordinates temp;
        temp.i = c.i - 1;
        temp.j = c.j - 2;
        if((temp.i > -1 && temp.i < 8) && (temp.j > -1 && temp.j < 8)){
            enqueue(q,temp); 
            flag = 1;
        }
    }

    else if( c.i < end.i && c.j > end.j){
        coordinates temp;
        temp.i = c.i + 2;
        temp.j = c.j - 1;
        if((temp.i > -1 && temp.i < 8) && (temp.j > -1 && temp.j < 8)){
            enqueue(q,temp); 
            flag = 1;
        }
    }

    else if( c.i > end.i && c.j < end.j){
        coordinates temp;
        temp.i = c.i - 2;
        temp.j = c.j + 1;
        
        if((temp.i > -1 && temp.i < 8) && (temp.j > -1 && temp.j < 8)){
            enqueue(q,temp); 
            flag = 1;
        }
    }
    
    if(flag == 1)
        count++;

}

bool if_discovered(coordinates c, queue dis){

    bool a = false;
    coordinates temp1;

    while(dis.f != -1){
        temp1 = dequeue(dis);
        if(temp1.i == c.i && temp1.j == c.j)
            a = true;
    }
    return a;    
}

void mark_discovered(coordinates c, queue &dis){
    enqueue(dis,c);
}

int main(){
    coordinates start, end;
    cin>>start.i;
    cin>>start.j;

    cin>>end.i;
    cin>>end.j;

    queue q;
    q.f = q.r = -1;
    q.size = 64;
    enqueue(q, start);
    int A[8][8];
    int count = 0;
    
    while(q.f != -1){

        coordinates c = dequeue(q);
        if(c.i == end.i && c.j == end.j){
            
            break;
        }
        else{
            enqueue(q,c);
            move(q,count,end);
        }
    }
    cout<< count <<endl;
    return 0;
}