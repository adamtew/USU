#include "unit.h"
#include "dww.h"
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
*******

Unit::Unit(){ r=0; c=0; hp=0; dir=up; rank=infantry; dead=true; }

Unit::Unit(int ir,int ic,int ihp,Dir idir,Rank irank, bool idead, string itla){
r=ir; c=ic; hp=ihp; dir=idir; rank=irank; dead=idead; tla=itla;
}

*******

int getR();
int getC();
int getHp();
Dir getDir();
Rank getRank();
bool getDead();
string getTla();
void Turn(Dir newDir); // turn to the indicated direction
void Move(int dist);   // move exactly this dist with no error checking
int Attack();          // attack, return hits.  see offical rules for dice rolls
void Suffer(int hits); // reduce hp by hits, adjust dead if needed
virtual void Place(int minR,int maxR,
int minC,int maxC, SitRep sitrep); // put unit on board, inside the bounding
// box define by min r,c and max r,c.
// don't put two units in the same place
// use the sitrep to figure out what is
// there.
virtual Action Recommendation(SitRep sitrep); // tell someone what you want to do.
// return an action, as described above.
// for the first phase, this is given to you.
*/

// test for the getR() basic functionality
bool test01(){
	dww mydww(42, 16, 4, up, knight, false, "dww");
	int r = mydww.getR();
	if (r == 42){
		return true;
	}else{
		return false;
	}
}

// test for the move function
bool test02(){
	dww mydww(42, 16, 4, up, knight, false, "dww");
	mydww.Move(3);
	int r = mydww.getR();
	int c = mydww.getC();
	if (r == 39 && c == 16){
		return true;
	}else{
		return false;
	}
	return 1;
}


// test for the place function
bool test03(){
	dww mydww;
	SitRep s;
	int i, j;
	for (i = 0; i<ROWS; i++)for (j = 0; j<COLS; j++)s.thing[i][j].what = rock;
	s.thing[14][14].what = space;
	s.nearestEnemyCrown.r = 15;
	s.nearestEnemyCrown.c = 15;
	s.nearestEnemyCrown.dirFor = up;
	s.nearestEnemy.r = 16;
	s.nearestEnemy.c = 16;
	s.nearestEnemy.dirFor = dn;
	s.anyOpenSpace = lt;
	//s.turnNumber = 235;
	mydww.Place(12, 15, 12, 15, s);
	int r = mydww.getR();
	int c = mydww.getC();
	if (r == 14 && c == 14){
		return true;
	}else{
		return false;
	}

	return 1;
}

// place test : Test Number 4 :
bool test04(){
	SitRep s;
	int i, j;
	for (i = 0; i<ROWS; ++i)for (j = 0; j<COLS; ++j)s.thing[i][j].what = rock;
	s.thing[12][12].what = space;
	s.nearestEnemyCrown.r = 10;
	s.nearestEnemyCrown.c = 10;
	s.nearestEnemyCrown.dirFor = up;
	s.nearestEnemy.r = 16;
	s.nearestEnemy.c = 16;
	s.nearestEnemy.dirFor = up;
	s.anyOpenSpace = dn;
	//s.turnNumber = 125;

	dww mydww(10, 12, 4, up, archer, false, "dww");

	mydww.Place(9, 15, 9, 15, s);
	int r = mydww.getR();
	int c = mydww.getC();
	if (r == 12 && c == 12){
		return true;
	}else{
		return false;
	}
}


// r should never be less than 0 or greater than ROWS - 1.
bool test05(){
	dww mydww(15, 16, 4, up, knight, false, "dww");
	int r = mydww.getR();
	if (r >= 0 && r <= ROWS - 1){
		return true;
	}else{
		return false;
	}
}


// c should never be less than 0 or greater than COLS-1.
bool test06(){
	dww mydww(10, 16, 4, up, knight, false, "dww");
	int c = mydww.getC();
	if (c >= 0 && c <= ROWS - 1){
		return true;
	}else{
		return false;
	}
}

// hp should never be less tan 0.
bool test07(){
	dww mydww(10, 16, 4, up, knight, false, "dww");
	int hp = mydww.getHp();
	if (hp >= 0) {
		return true;
	}else{
		return false;
	}
}

// dir should always be up, dn, lt, or rt.
bool test08(){
	dww mydww(10, 16, 4, up, knight, false, "dww");
	Dir d = mydww.getDir();
	if (d == up || d == dn || d == lt || d == rt){
		return true;
	}else{
		return false;
	}
}

// rank should always be crown, knight, archer, or infantry.
bool test09(){
	dww mydww(10, 16, 4, up, knight, false, "dww");
	Rank r = mydww.getRank();
	if (r == crown || r == knight || r == archer || r == infantry){
		return true;
	}else{
		return false;
	}
}

// dead is true if and only if hp is 0.
bool test10(){
	dww mydww(10, 16, 0, up, knight, true, "dww");
	if (mydww.getDead() == true && mydww.getHp() == 0){
		return true;
	}else{
		return false;
	}
}

// The tla can be any three character string.
bool test11(){
	dww mydww(10, 16, 4, up, knight, false, "dww");
	string tla = mydww.getTla();
	if (tla.length() == 3){
		return true;
	}else{
		return false;
	}
	return true;
}

// int Attack(): Returns the number of hits generated by the unit in an attack.
// Roll one six-sided die per hp.  
// For archers, any time you roll a 1 or a 2, generate one hit.  
// For all other units, any time you roll a 2, 3, or 4, generate one hit.  
// Return the total number of hits.
bool test12(){
	dww mydww(10, 16, 4, up, knight, false, "dww");
	int a = mydww.Attack();
	if (a < 0 || a > mydww.getHp()){
		return false;
	}else{
		return true;
	}
}

// void Suffer(int hits): For infantry and archers, reduces the number of hp by hits.  
//For knights and crowns, reduce hp by hits/2.  
//if hp becomes 0 or less, set it back to zero and set dead to true
bool test13(){
	dww mydww(10, 16, 4, up, archer, false, "dww");
	mydww.Suffer(3);
	if (mydww.getHp() == 1){
		return true;
	}else{
		return false;
	}
}


	
int main(){

	if (!test01()){ cout << "failed test01.\n"; exit(1); }
	if (!test02()){ cout << "failed test02.\n"; exit(1); }
	if (!test03()){ cout << "failed test03.\n"; exit(1); }
	if (!test04()){ cout << "failed test04.\n"; exit(1); }
	if (!test05()){ cout << "failed test05.\n"; exit(1); }
	if (!test06()){ cout << "failed test06.\n"; exit(1); }
	if (!test07()){ cout << "failed test07.\n"; exit(1); }
	if (!test08()){ cout << "failed test08.\n"; exit(1); }
	if (!test09()){ cout << "failed test09.\n"; exit(1); }
	if (!test10()){ cout << "failed test10.\n"; exit(1); }
	if (!test11()){ cout << "failed test11.\n"; exit(1); }
	if (!test12()){ cout << "failed test12.\n"; exit(1); }
	if (!test13()){ cout << "failed test13.\n"; exit(1); }
	cout << "all tests passed.\n";

	return 0;
}