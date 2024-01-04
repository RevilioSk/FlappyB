
#include <Grapic.h>
#include <math.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace grapic;
using namespace std;
const int DIMW = 800;
const int MAX_PART  = 800;
const float FRICT = 0.6;


struct Vect2
{
    float x;
    float y;
};

struct Particule
{
    Vect2 p;
    Vect2 v;
    Vect2 f;
    float m;
};

struct Monde
{
    Particule T[MAX_PART];
    int nb_part;
};

Vect2 operator+ (Vect2 a, Vect2 b)
{
    struct Vect2 z;
    z.x = a.x+b.x;
    z.y = a.y + b.y;
    return z;
}

Vect2 operator- (Vect2 a, Vect2 b)
{
    struct Vect2 z;
    z.x = a.x-b.x;
    z.y = a.y - b.y;
    return z;
}

Vect2 operator* (float lambda, Vect2 b)
{
    struct Vect2 z;
    z.x = lambda * b.x ;
    z.y = lambda * b.y ;
    return z;
}



Vect2 operator*(Vect2 a, Vect2 b)
{
    Vect2 z;
    z.x = a.x*b.x - a.y*b.y;
    z.y = a.x*b.y + a.y*b.x;
    return z;
}


Vect2 operator/ (Vect2 b, float lambda)
{
    struct Vect2 z;
    z.x = b.x / lambda;
    z.y = b.y / lambda;
    return z;
}


void AddForce(Particule& P, Vect2 force)
{
    P.f=P.f+force;
}

void UpdatePV(Particule& P,float dt)
{
    if(P.m>0)
    {
        P.v = dt*(P.f/P.m)+P.v;
        P.p = dt*P.v +P.p;
        P.f.x = 0;
        P.f.y = 0;
    }
    if(P.p.x<0)
    {
        P.p.x=DIMW;
    }
    if(P.p.y<64)
    {
        P.v.y=-P.v.y;
    }
    if(P.p.y>DIMW)
    {
        P.v.y=-P.v.y;
    }
    if(P.p.x>DIMW)
    {
        P.v.x=-P.v.x;
    }
}

/*void Force(Monde &m)
{
    int i;
    for(i=0;i<m.nb_part;i++)
    {
        m.T[i].f.x=0;
        m.T[i].f.y=-(m.T[i].m*9.81);
    }
}*/

void updatepart(Monde &m)
{
    int i;
    //Force(m);
    for(i=0;i<m.nb_part;i++)
    {
        UpdatePV(m.T[i],0.001);
    }
}

void drawpart(Monde m)
{
    int i,n;
    color(0,125,255);
    for(i=0;i<m.nb_part;i++)
    {
        circleFill(m.T[i].p.x,m.T[i].p.y,6);
    }
}

void drawp(Particule P)
{
    color(3,100,250);
    circleFill(P.p.x,P.p.y,10);
}

void initpart(Monde& m)
{
    int i;
    for(i=0;i<m.nb_part;i++)
    {
        m.T[i].p.x=100+rand()%150;
        m.T[i].p.y=100+rand()%150;
        m.T[i].v.x=-140+rand()%70;
        m.T[i].v.y=-70+rand()%140;
        m.T[i].m=1;
        m.T[i].f.x=0;
        m.T[i].f.y=0;
    }
}




