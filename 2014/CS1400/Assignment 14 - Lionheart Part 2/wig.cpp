#include "wig.h"
Location myLoc, fLoc, enemyLoc;


class Soldier{
public:
    Soldier(SitRep sitrep, int r, int c, Dir dir, string tla, Rank rank);

    bool checkMeleeAttack();
    bool checkRangeAttack();
    bool checkForward();
    void defaultAction();
    void move();
    Location frontLoc();

    SitRep sitrep;
    int r, c;
    Dir dir;
    string tla;
    Rank rank;
    Action a;
    bool canMove, canAttack;
};

Location choosePlace(int minR,int maxR, int minC,int maxC, SitRep sitrep, bool l){
    Location loc;
    if(!l){
        for(int i = maxR - 4; i >= minR; i--){
            for(int j = maxC; j >= minC; j--){
                if(sitrep.thing[i][j].what == space){
                    loc.c = j;
                    loc.r = i;
                    return loc;
                }
            }
        }
    }else{
        for(int i = minR + 3; i <= maxR; i++){
            for(int j = minC; j <= maxC; j++){
                if(sitrep.thing[i][j].what == space){
                    loc.c = j;
                    loc.r = i;
                    return loc;
                }
            }
        }
    }
}

void wig::Place(int minR,int maxR, int minC,int maxC, SitRep sitrep){
    bool l = false;
    if(minC == 0)l = true;
    dir = lt;if(l)dir = rt;
    Location myLoc = choosePlace(minR, maxR, minC, maxC, sitrep, l);
    r = myLoc.r;
    c = myLoc.c;
}

Action wig::Recommendation(SitRep sitrep){ 
    Action in;
    if(rank == knight)in.maxDist = HORSESPEED;
    if(rank == archer || rank == infantry)in.maxDist = 1;
    Soldier dude(sitrep, r, c, dir, tla, rank);
    dude.defaultAction();
    if(rank == infantry){
        if(in.action == attack)cout << "\nattack";
        if(in.action == turn)cout << "\nturn";
        if(in.action == fwd)cout << "\nmove";
    }
    in.action = dude.a.action;
    in.dir = dude.a.dir;
    in.ar = dude.a.ar;
    in.ac = dude.a.ac;
    return in;
}

Soldier::Soldier(SitRep isitrep, int ir, int ic, Dir idir, string itla, Rank irank){
    sitrep = isitrep;
    r = ir;
    c = ic;
    dir = idir;
    tla = itla;
    rank = irank;
}

void Soldier::defaultAction(){

    if(rank == infantry || rank == knight)canAttack = checkMeleeAttack();
    if(rank == archer)canAttack = checkRangeAttack();
    if(canAttack){
        //cout << "\ncanattack";
        a.action = attack;
        a.ar = sitrep.nearestEnemy.r;
        a.ac = sitrep.nearestEnemy.c; 
    }else{
        //cout << "\ncanNotAttack";
        move();
    }
}

bool Soldier::checkMeleeAttack(){
    frontLoc();
    if(sitrep.thing[fLoc.r][fLoc.c].what == unit && sitrep.thing[fLoc.r][fLoc.c].tla != tla){
       //cout << "\nmeleetrue";
        return true;
    }else{
        //cout << "\nmeleefalse";
        return false;
    }
}

bool Soldier::checkRangeAttack(){
    if(sitrep.nearestEnemy.r > r) enemyLoc.r = sitrep.nearestEnemy.r - r;
    if(sitrep.nearestEnemy.c > c) enemyLoc.c = sitrep.nearestEnemy.c - c;
    if(r > sitrep.nearestEnemy.r) enemyLoc.r = r - sitrep.nearestEnemy.r;
    if(c > sitrep.nearestEnemy.c) enemyLoc.c = c - sitrep.nearestEnemy.c;
    if(enemyLoc.r < 4 && enemyLoc.c < 4){
        //cout << "\narchertrue";
        return true;
    }else{
        //cout << "\narcherfalse";
        return false;
    }
}

Location Soldier::frontLoc(){
    switch(dir){
        case up: fLoc.r = r--; break;
        case dn: fLoc.r = r++; break;
        case rt: fLoc.c = c++; break;
        case lt: fLoc.c = c--; break;
    }
}

void Soldier::move(){
    if(dir == sitrep.nearestEnemy.dirFor){
        //cout << "\nmove";
        a.action = fwd;
        a.maxDist=1;
    }else{
        //cout << "\narcherTurn";
        a.dir = sitrep.nearestEnemy.dirFor;
        a.action = turn;
        
    }
}