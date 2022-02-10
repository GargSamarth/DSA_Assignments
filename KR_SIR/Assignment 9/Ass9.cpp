#include <iostream>

using namespace std;

int A[8][8] = {
                {0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,0},
                {0,1,0,1,0,0,0,0},
                {0,1,0,1,1,1,1,0},
                {0,0,0,0,0,0,1,0},
                {0,1,0,0,1,0,1,0},
                {0,1,1,1,1,0,1,0},
                {0,0,0,0,0,0,0,0}
            };
struct coordinates{
    int x;
    int y;
    bool tf;
};


struct stack{
    int size;
    int top;
    coordinates c[50];
};

void push(stack &s, coordinates x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.c[++s.top] = x;
}

coordinates pop(stack &s){
    coordinates temp;
    temp.x = temp.y = -1;
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return temp;
    }
    else
        return s.c[s.top--];
}

coordinates peek(stack &s){
    coordinates temp;
    temp.x = temp.y = -1;
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return temp;
    }
    else
        return s.c[s.top];
}

coordinates direction(int a, int b, int tag){
    coordinates c;
    //West
    if(A[a][b-1] == 1 && tag==1){
        c.x = a;
        c.y = b-1;
        c.tf = true;
        return c;
    }
    //East
    else if(A[a][b+1] == 1 && tag==2){
        c.x = a;
        c.y = b+1;
        c.tf = true;
        return c;
    }
    //Nort
    else if(A[a-1][b] == 1 && tag==3){
        c.x = a-1;
        c.y = b;
        c.tf = true;
        return c;
    }
    //South
    else if(A[a+1][b] == 1 && tag==1){
        c.x = a+1;
        c.y = b;
        c.tf = true;
        return c;
    }
    else{
        c.x = a;
        c.y = b;
        c.tf = false;
        return c;
    }
}

void maze(coordinates &c1, coordinates &c2){
    stack s;
    push(s,c1);
    while(s.top>-1){
        if(c1.x == c2.x && c1.y == c2.y){
            cout<< "Won";
            return;
        }

        if(direction(c1.x,c1.y,1).tf){
            c1 = direction(c1.x,c1.y,1);
            push(s,c1);
        }

        else if(direction(c1.x,c1.y,2).tf){
            c1 = direction(c1.x,c1.y,2);
            push(s,c1);
        }

        else if(direction(c1.x,c1.y,3).tf){
            c1 = direction(c1.x,c1.y,3);
            push(s,c1);
        }

        else if(direction(c1.x,c1.y,4).tf){
            c1 = direction(c1.x,c1.y,4);
            push(s,c1);
        }
    }
    cout<< "Loose" << endl;
    return;
}


int main(){
    coordinates c1,c2;
    cout<< "starting points: ";
    cin>>c1.x>>c1.y;
    cout<< endl<< "End points: ";
    cin>>c2.x>>c2.y;
    maze(c1,c2);
}