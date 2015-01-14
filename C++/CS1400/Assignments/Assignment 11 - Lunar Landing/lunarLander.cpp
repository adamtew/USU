#include <iostream>
#include <cmath>
#include "lunarLander.h"
#include <stdlib.h>

using namespace std;

Lander::Lander(){

	G.x = 0.0;
	G.y = -1.622;
	angle = PI;
	velocity.x = 20;
	velocity.y = 0.0;
	fuel = 200.0;
	position.x = 100.0;
	position.y = 300.0;
	maxTouchdownVelocity = 5.0;
	crashed = false;
	landed = false;
	thrust.x = 0.0;
	thrust.y = 0.0;
	fuelBurnedThisTurn = 0;
	rotatedThisTurn = 0;
}

Lander::Lander(Vect iG, double iangle, Vect ivelocity, double ifuel,
	Vect iposition, double imax, bool icrashed, bool ilanded){

	G.x = iG.x;
	G.y = iG.y;
	if (iangle < 0 || iangle > 2 * PI){
		angle = PI;
	}else{
		angle = iangle;
	}
	velocity.x = ivelocity.x;
	velocity.y = ivelocity.y;
	if (ifuel < 0){
		fuel = 200.0;
	}else{
		fuel = ifuel;
	}
	position.x = iposition.x;
	if (iposition.y < 0){
		position.y = 0.0;
	}
	else{
		position.y = iposition.y;
	}
	if (imax < 0){
		maxTouchdownVelocity = 5.0;
	}
	else{
		maxTouchdownVelocity = imax;
	}
	if (crashed && landed){
		crashed = false;
		landed = false;
	}else{
		crashed = icrashed;
		landed = ilanded;
	}
	thrust.x = 0.0;
	thrust.y = 0.0;
	fuelBurnedThisTurn = 0;
	rotatedThisTurn = 0;
}


double Lander::getAngle(){
	return angle;
}

Vect Lander::getVelocity(){
	return velocity;
}

double Lander::getFuel(){
	return fuel;
}

Vect Lander::getPosition(){
	return position;
}

double Lander::getMTV(){
	return maxTouchdownVelocity;
}

bool Lander::getCrashed(){
	return crashed;
}

bool Lander::getLanded(){
	return landed;
}


void Lander::rotateLeft(double rotateAngle){
	if (rotateAngle < 0){
		rotateAngle = abs(rotateAngle);
	}
	if (rotateAngle > PI / 12){
		rotateAngle = PI / 12;
	}
	rotatedThisTurn += (rotateAngle);
}
	
										//max rotation per sec is pi/12
										//rotateAngle should be a 
										//positive number.  This function
										//affects only the variable
										//rotatedThisTurn.

void Lander::rotateRight(double rotateAngle){
	if (rotateAngle < 0){
		rotateAngle = abs(rotateAngle);
	}
	if (rotateAngle > PI / 12){
		rotateAngle = PI / 12;
	}
	
	rotatedThisTurn -= abs(rotateAngle);
}
										//max rotation per sec is pi/12
										//rotateAngle should be a 
										//positive number.  This function
										//affects only the variable
										//rotatedThisTurn.

void Lander::burn(double fuelAmount){
	if (fuelAmount > 0 && fuel > 0 && fuelBurnedThisTurn < 50){
		fuelBurnedThisTurn += fuelAmount;
	}
}
									//max fuelBurn per sec is 50;
									//fuelAmount should be a 
									//positive number.  This function
									//affects only the variable
									//fuelBurnedThisTurn

void Lander::timeUpdate(){
	angle += rotatedThisTurn;
	if (angle < 0){
		angle = (2 * PI) + angle;
	}
	if (angle > (2 * PI)){
		angle = angle - (2 * PI);
	}
	fuel -= fuelBurnedThisTurn;
	thrust.x = cos(angle)*fuelBurnedThisTurn;
	thrust.y = sin(angle)*fuelBurnedThisTurn;
	velocity.x = velocity.x + thrust.x + G.x;
	velocity.y = velocity.y + thrust.y + G.y;
	position.x += velocity.x + (0.5 * thrust.x);
	position.y += velocity.y + (0.5 * thrust.x);
	fuelBurnedThisTurn = 0;
	rotatedThisTurn = 0;
	thrust.x = 0;
	thrust.y = 0;
	if (position.y < 0 && abs(velocity.y) > maxTouchdownVelocity){
		crashed = true;
		landed = false;
	}
	if (position.y < 0 && abs(velocity.y) <= maxTouchdownVelocity){
		crashed = false;
		landed = true;
	}
}		      
								//this function uses 
								//rotatedThisturn and 
								//fuelBurnedThisTurn to simulate
								//the passage of 1 second of 
								//time. this function updates
								//angle, thrust, velocity,
								//position, fuel, crashed, and
								//landed.  it also resets
								//rotatedThisTurn and
								//fuelBurnedThisTurn