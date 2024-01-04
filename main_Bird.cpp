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
const int MAX_PART  = 500;
const float FRICT = 0.6;



struct Classe{

    int Attaque,Puissance,Armure,RM,Vie,Soin,CSC,CSD,VA,Portee;  //CSC = Critical Strike Chance; CSD = Critical Strike Damage; VA = Vitesse d'attaque; RM = Resistance Magique
    string nomclasse;

};

struct Attribut{

    int Attaque,Puissance,Armure,RM,Vie,Soin,CSC,VA;  //CSC = Critical Strike Chance; VA = Vitesse d'attaque; RM = Resistance Magique

};

struct Perso{

    Classe C;
    Attribut A;
    float posX,posY;

};

struct Vague{

    int nbs;
    int nbv;

};

struct EnnemieSbire{

    int Attaque,Vie;
    float posX,posY;

};


void SetBaseAttribut(Attribut& A){

    A.Armure = 0;
    A.Attaque = 0;
    A.CSC = 0;
    A.Puissance = 0;
    A.RM = 0;
    A.Soin = 0;
    A.VA = 0;
    A.Vie = 0;

}

void DefTank(Classe& D){

    D.Armure = 50;
    D.Attaque = 10;
    D.CSC = 0;
    D.CSD = 2;
    D.Portee = 13;
    D.Puissance = 0;
    D.RM = 50;
    D.Soin = 0;
    D.VA = 5;
    D.Vie = 200;

    D.nomclasse = "Tank";

}

void DefBerserker(Classe& D){

    D.Armure = 20;
    D.Attaque = 25;
    D.CSC = 0;
    D.CSD = 2;
    D.Portee = 18;
    D.Puissance = 5;
    D.RM = 20;
    D.Soin = 0;
    D.VA = 10;
    D.Vie = 175;

    D.nomclasse = "Berserker";

}

void DefPaladin(Classe& D){

    D.Armure = 25;
    D.Attaque = 15;
    D.CSC = 0;
    D.CSD = 2;
    D.Portee = 13;
    D.Puissance = 0;
    D.RM = 25;
    D.Soin = 10;
    D.VA = 7;
    D.Vie = 100;

    D.nomclasse = "Paladin";

}

void DefArcher(Classe& D){

    D.Armure = 5;
    D.Attaque = 15;
    D.CSC = 10;
    D.CSD = 3;
    D.Portee = 158;
    D.Puissance = 0;
    D.RM = 5;
    D.Soin = 0;
    D.VA = 25;
    D.Vie = 75;

    D.nomclasse = "Archer";

}

void DefPyromancien(Classe& D){

    D.Armure = 7;
    D.Attaque = 1;
    D.CSC = 0;
    D.CSD = 1;
    D.Portee = 158;
    D.Puissance = 20;
    D.RM = 10;
    D.Soin = 0;
    D.VA = 10;
    D.Vie = 100;

    D.nomclasse = "Pyromancien";

}

void DefNecromancien(Classe& D){

    D.Armure = 7;
    D.Attaque = 1;
    D.CSC = 0;
    D.CSD = 1;
    D.Portee = 158;
    D.Puissance = 25;
    D.RM = 10;
    D.Soin = 0;
    D.VA = 10;
    D.Vie = 100;

    D.nomclasse = "Necromancien";

}

void DefAssassin(Classe& D){

    D.Armure = 7;
    D.Attaque = 10;
    D.CSC = 20;
    D.CSD = 4;
    D.Portee = 13;
    D.Puissance = 0;
    D.RM = 7;
    D.Soin = 0;
    D.VA = 20;
    D.Vie = 75;

    D.nomclasse = "Assassin";

}

void DefLancier(Classe& D){

    D.Armure = 10;
    D.Attaque = 20;
    D.CSC = 0;
    D.CSD = 2;
    D.Portee = 28;
    D.Puissance = 0;
    D.RM = 10;
    D.Soin = 0;
    D.VA = 10;
    D.Vie = 100;

    D.nomclasse = "Lancier";

}

void DefGuerrier(Classe& D){

    D.Armure = 15;
    D.Attaque = 25;
    D.CSC = 0;
    D.CSD = 2;
    D.Portee = 13;
    D.Puissance = 0;
    D.RM = 15;
    D.Soin = 0;
    D.VA = 7;
    D.Vie = 150;

    D.nomclasse = "Guerrier";

}

void DefClerc(Classe& D){

    D.Armure = 10;
    D.Attaque = 1;
    D.CSC = 0;
    D.CSD = 1;
    D.Portee = 208;
    D.Puissance = 7;
    D.RM = 10;
    D.Soin = 25;
    D.VA = 8;
    D.Vie = 200;

    D.nomclasse = "Clerc";

}

void DefGardien(Classe& D){

    D.Armure = 30;
    D.Attaque = 1;
    D.CSC = 0;
    D.CSD = 1;
    D.Portee = 208;
    D.Puissance = 15;
    D.RM = 30;
    D.Soin = 0;
    D.VA = 8;
    D.Vie = 175;

    D.nomclasse = "Gardien";

}

void DefPorteEtendard(Classe& D){

    D.Armure = 15;
    D.Attaque = 1;
    D.CSC = 0;
    D.CSD = 1;
    D.Portee = 208;
    D.Puissance = 20;
    D.RM = 15;
    D.Soin = 0;
    D.VA = 8;
    D.Vie = 150;

    D.nomclasse = "Porte Etendard";

}

void DefArtificier(Classe& D){

    D.Armure = 10;
    D.Attaque = 5;
    D.CSC = 0;
    D.CSD = 3;
    D.Portee = 208;
    D.Puissance = 13;
    D.RM = 10;
    D.Soin = 0;
    D.VA = 7;
    D.Vie = 150;

    D.nomclasse = "Artificier";

}

void DefTrappeur(Classe& D){

    D.Armure = 10;
    D.Attaque = 5;
    D.CSC = 0;
    D.CSD = 3;
    D.Portee = 208;
    D.Puissance = 13;
    D.RM = 10;
    D.Soin = 0;
    D.VA = 7;
    D.Vie = 150;

    D.nomclasse = "Trappeur";

}

void DefAlchimiste(Classe& D){

    D.Armure = 10;
    D.Attaque = 5;
    D.CSC = 0;
    D.CSD = 3;
    D.Portee = 208;
    D.Puissance = 13;
    D.RM = 10;
    D.Soin = 0;
    D.VA = 7;
    D.Vie = 150;

    D.nomclasse = "Alchimiste";

}

void drawPerso(Perso& P)
{
    color(0,0,255);
    circleFill( P.posX, P.posY, 5);
    int n = P.C.nomclasse.length();
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, P.C.nomclasse.c_str());
    print(P.posX,P.posY+10,char_array);
}

void drawSbire(EnnemieSbire& E){

    color(255,0,0);
    circleFill( E.posX, E.posY, 3);

}

void setSbire(EnnemieSbire& E, int i, int nbs, Perso P1, Perso P2, Perso P3){

    E.Attaque = 1;
    E.Vie = 5;
    if(i<=nbs/3)E.posX = P1.posX;
    else if(i<=2*nbs/3&&i>nbs/3)E.posX = P2.posX;
    else E.posX = P3.posX;
    E.posY = i*10 + 450;


}

void updatesbire(EnnemieSbire& E){

    E.posY = E.posY-0.05;

}
/*void Stun (Perso P){



}*/


int main(int , char** )
{
    bool stop=false;
    bool jeu=false;
    bool menu=true;
    int i,sm,nbs;
    Menu m1;
    Menu m2;
    Menu m3;
    Menu m4;
    Menu m5;

    EnnemieSbire SE[200];

    float timer;
    float cda1,cda2,cda3,cda4,cda5;
    float bcda1,bcda2,bcda3,bcda4,bcda5;

    srand(time(NULL));
	winInit("Tower Def", DIMW, DIMW);
    backgroundColor( 0, 200, 200 );
    Perso P1;
    Perso P2;
    Perso P3;
    Perso P4;
    Perso P5;
    Vague V;
    menu_add( m1, "Tank");
    menu_add( m1, "Paladin");
    menu_add( m1, "Berserker");

    menu_add( m2, "Archer");
    menu_add( m2, "Pyromancien");
    menu_add( m2, "Necromancien");

    menu_add( m3, "Assassin");
    menu_add( m3, "Lancier");
    menu_add( m3, "Guerrier");

    menu_add( m4, "Clerc");
    menu_add( m4, "Gardien");
    menu_add( m4, "Porte Etendard");

    menu_add( m5, "Artificier");
    menu_add( m5, "Trappeur");
    menu_add( m5, "Alchimiste");
    V.nbs = 20;
    V.nbv = 1;

    sm=1;
    nbs=20;

    P1.posX=DIMW/2-5;
    P1.posY=200;

    P2.posX=DIMW/2-55;
    P2.posY=150;

    P3.posX=DIMW/2+45;
    P3.posY=150;

    P4.posX=DIMW/2-55;
    P4.posY=100;

    P5.posX=DIMW/2+45;
    P5.posY=100;





    for(i=0;i<=nbs;i++)
    {
        setSbire(SE[i],i,nbs,P1,P2,P3);
    }
	while( !stop )
    {

        if (menu==true)
        {
            winClear();

            if(sm==1){
                menu_draw(m1, DIMW/2-50,DIMW/2-100, DIMW/2+50, DIMW/2+100);
                switch(menu_select(m1))
                {
                    case 0 : DefTank(P1.C); break;
                    case 1 : DefPaladin(P1.C); break;
                    case 2 : DefBerserker(P1.C); break;
                    default: DefPaladin(P1.C); break;
                }
                if (isKeyPressed(SDLK_f))
                {
                    bcda1 = 50-P1.C.VA;
                    sm+=1;
                }
            }
            if(sm==2){
                menu_draw(m2, DIMW/2-50,DIMW/2-100, DIMW/2+50, DIMW/2+100);
                switch(menu_select(m2))
                {
                    case 0 : DefArcher(P2.C); break;
                    case 1 : DefPyromancien(P2.C); break;
                    case 2 : DefNecromancien(P2.C); break;
                    default: DefPaladin(P1.C); break;
                }
                if (isKeyPressed(SDLK_f))
                {
                    bcda2 = 50-P2.C.VA;
                    sm+=1;
                }
            }
            if(sm==3){
                menu_draw(m3, DIMW/2-50,DIMW/2-100, DIMW/2+50, DIMW/2+100);
                switch(menu_select(m3))
                {
                    case 0 : DefAssassin(P3.C); break;
                    case 1 : DefLancier(P3.C); break;
                    case 2 : DefGuerrier(P3.C); break;
                    default: DefPaladin(P1.C); break;
                }
                if (isKeyPressed(SDLK_f))
                {
                    bcda3 = 50-P3.C.VA;
                    sm+=1;
                }
            }
            if(sm==4){
                menu_draw(m4, DIMW/2-50,DIMW/2-100, DIMW/2+50, DIMW/2+100);
                switch(menu_select(m4))
                {
                    case 0 : DefClerc(P4.C); break;
                    case 1 : DefGardien(P4.C); break;
                    case 2 : DefPorteEtendard(P4.C); break;
                    default: DefPaladin(P1.C); break;
                }
                if (isKeyPressed(SDLK_f))
                {
                    bcda4 = 50-P4.C.VA;
                    sm+=1;
                }
            }
            if(sm==5){
                menu_draw(m5, DIMW/2-50,DIMW/2-100, DIMW/2+50, DIMW/2+100);
                switch(menu_select(m5))
                {
                    case 0 : DefArtificier(P5.C); break;
                    case 1 : DefTrappeur(P5.C); break;
                    case 2 : DefAlchimiste(P5.C); break;
                    default: DefPaladin(P1.C); break;
                }
                if (isKeyPressed(SDLK_f))
                {
                    bcda5 = 50-P5.C.VA;
                    sm+=1;
                }
            }
            if(sm==6){jeu=true;menu=false;}

            cda1=bcda1;
            cda2=bcda2;
            cda3=bcda3;
            cda4=bcda4;
            cda5=bcda5;

            stop = winDisplay();



        }


        if (jeu==true)
        {
            fontSize(12);
            setKeyRepeatMode(true);
            winClear();
            color(255,255,0);
            drawPerso(P1);
            drawPerso(P2);
            drawPerso(P3);
            drawPerso(P4);
            drawPerso(P5);
            for(i=0;i<=nbs;i++)
            {
                if(SE[i].Vie>0)
                {
                    //Dessine le rond des sbires et les déplace vers le bas
                    drawSbire(SE[i]);
                    updatesbire(SE[i]);

                    //Gère l'attaque sur les sbires et le cooldown d'attaque

                    if(abs(SE[i].posY-P1.posY)<=P1.C.Portee&&cda1==bcda1)
                    {
                        SE[i].Vie = SE[i].Vie - P1.C.Attaque+P1.A.Attaque;
                        if(SE[i].Vie<=0){--nbs;}
                        cda1=0;
                    }
                    if(abs(SE[i].posY-P2.posY)<=P2.C.Portee&&cda2==bcda2)
                    {
                        SE[i].Vie = SE[i].Vie - P2.C.Attaque+P2.A.Attaque;
                        if(SE[i].Vie<=0){--nbs;}
                        cda2=0;
                    }
                    if(abs(SE[i].posY-P3.posY)<=P3.C.Portee&&cda3==bcda3)
                    {
                        SE[i].Vie = SE[i].Vie - P3.C.Attaque+P3.A.Attaque;
                        if(SE[i].Vie<=0){--nbs;}
                        cda3=0;
                    }
                    if(abs(SE[i].posY-P4.posY)<=P4.C.Portee&&cda4==bcda4)
                    {
                        SE[i].Vie = SE[i].Vie - P4.C.Attaque+P4.A.Attaque;
                        if(SE[i].Vie<=0){--nbs;}
                        cda4=0;
                    }
                    if(abs(SE[i].posY-P5.posY)<=P5.C.Portee&&cda5==bcda5)
                    {
                        SE[i].Vie = SE[i].Vie - P5.C.Attaque+P5.A.Attaque;
                        if(SE[i].Vie<=0){--nbs;}
                        cda5=0;
                    }

                    // Rapproche les sbires du Heros le plus proche sur l'axe X

                    /*if(abs(SE[i].posX-P1.posX)<abs(SE[i].posX-P2.posX)&&abs(SE[i].posX-P1.posX)<abs(SE[i].posX-P3.posX)&&abs(SE[i].posX-P1.posX)<abs(SE[i].posX-P4.posX)&&abs(SE[i].posX-P1.posX)<abs(SE[i].posX-P5.posX)&&SE[i].posX-P1.posX!=0)
                    {
                        if(SE[i].posX-P1.posX>0)
                        {
                            SE[i].posX=SE[i].posX-0.01;
                        }
                        else if(SE[i].posX-P1.posX<0)
                        {
                            SE[i].posX=SE[i].posX+0.01;
                        }
                    }
                    if(abs(SE[i].posX-P2.posX)<abs(SE[i].posX-P1.posX)&&abs(SE[i].posX-P2.posX)<abs(SE[i].posX-P3.posX)&&SE[i].posX-P2.posX!=0)
                    {
                        if(SE[i].posX-P2.posX>0)
                        {
                            SE[i].posX=SE[i].posX-0.01;
                        }
                        else if(SE[i].posX-P2.posX<0)
                        {
                            SE[i].posX=SE[i].posX+0.01;
                        }
                    }
                    if(abs(SE[i].posX-P3.posX)<abs(SE[i].posX-P2.posX)&&abs(SE[i].posX-P3.posX)<abs(SE[i].posX-P1.posX)&&SE[i].posX-P3.posX!=0)
                    {
                        if(SE[i].posX-P3.posX>0)
                        {
                            SE[i].posX=SE[i].posX-0.01;
                        }
                        else if(SE[i].posX-P3.posX<0)
                        {
                            SE[i].posX=SE[i].posX+0.01;
                        }
                    }*/


                    //Arrete les sbires prets des héros

                    if(abs(SE[i].posY-P1.posY)<5&&abs(SE[i].posX-P1.posX)<2)
                    {
                        SE[i].posY=P1.posY+5;
                    }
                    if(abs(SE[i].posY-P2.posY)<5&&abs(SE[i].posX-P2.posX)<2)
                    {
                        SE[i].posY=P2.posY+5;
                    }
                    if(abs(SE[i].posY-P3.posY)<5&&abs(SE[i].posX-P3.posX)<2)
                    {
                        SE[i].posY=P3.posY+5;
                    }


                }


            }
            if(cda1<bcda1)
            {
                cda1 = cda1+0.12;
            }
            if(cda2<bcda2)
            {
                cda2 = cda2+0.12;
            }
            if(cda3<bcda3)
            {
                cda3 = cda3+0.12;
            }
            if(cda4<bcda4)
            {
                cda4 = cda4+0.12;
            }
            if(cda5<bcda5)
            {
                cda5 = cda5+0.12;
            }
            if(cda1>bcda1)
            {
                cda1 = bcda1;
            }
            if(cda2>bcda2)
            {
                cda2 = bcda2;
            }
            if(cda3>bcda3)
            {
                cda3 = bcda3;
            }
            if(cda4>bcda4)
            {
                cda4 = bcda4;
            }
            if(cda5>bcda5)
            {
                cda5 = bcda5;
            }

            print(10,100,cda1);
            print(50,100,cda2);
            print(100,100,cda3);
            print(150,100,cda4);
            print(200,100,cda5);

            print(10,200,bcda1);
            print(50,200,bcda2);
            print(100,200,bcda3);
            print(150,200,bcda4);
            print(200,200,bcda5);

            print(10,10,nbs);
            // print(80,10,j.score);
            timer=elapsedTime();
        }





        stop = winDisplay();
    }

	return 0;
}
