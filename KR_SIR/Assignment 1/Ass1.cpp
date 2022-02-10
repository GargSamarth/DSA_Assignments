#include <iostream>

using namespace std;

struct S10{
  int y;
  S10 *z;
};

struct S9{
    int x;
    S9 *w;
};

struct S8{
    int u;
    S9 *t;
    S10 *v;
};

struct S7{
    int n;
    char o;
    S8 *p;
};

struct S6{
    int r;
    S7* q;
    S6* s;
};

struct S5{
    int l;
    S6 *m;
};

struct S4{
    S7 *j;
    S5 *k;
};

struct S3{
    S5 *i;
    S4 *g;
    S3 *h;
};

struct S2{
    char e;
    S3 *f;
};

struct S1{
    int b;
    S1 *a;
    S1 *d;
    S2 *c;
};

int main(){
    S1 *p1;
    
    p1 = new S1;
    p1->c = new S2;
    p1->c->f = new S3;
    p1->c->f->g = new S4;
    p1->c->f->i = new S5;
    p1->c->f->g->j = new S7;
    p1->c->f->i->m = new S6;
    p1->c->f->g->j->p = new S8;
    p1->c->f->g->j->p->t = new S9;
    p1->c->f->g->j->p->v = new S10;
    
    //input from user
    cin>> p1->c->f->g->j->n >> p1->c->f->i->m->r >> p1->c->f->g->j->p->u;
    int u1 = p1->c->f->g->j->p->u, 
        n1 = p1->c->f->g->j->n,
        r1 = p1->c->f->i->m->r;     ;

    //main logic
    if(u1 % 2 ==0 ){
        p1->c->f->g->j->p->t->x = n1;
        p1->c->f->g->j->p->v->y = r1;
    }

    else{
        p1->c->f->g->j->p->v->y = n1;
        p1->c->f->g->j->p->t->x = r1;
    }

    //output

    cout<< p1->c->f->g->j->n << " " 
        << p1->c->f->i->m->r << " " 
        << p1->c->f->g->j->p->u << " " 
        << p1->c->f->g->j->p->t->x << " " 
        << p1->c->f->g->j->p->v->y << endl;

    return 0;
}
