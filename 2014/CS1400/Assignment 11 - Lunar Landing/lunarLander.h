#ifndef LUNARLANDER_H
#define LUNARLANDER_H
#define PI 3.14159

using namespace std;

//Vector definition
struct Vect{
	double x;
	double y;
};


class Lander{
public:
	//constructors
	Lander();
	Lander(Vect iG, double iangle, Vect ivelocity, double ifuel,
                Vect iposition, double imax, bool icrashed, bool ilanded);

	//accessors
	double getAngle();
	Vect getVelocity();
	double getFuel();
	Vect getPosition();
	double getMTV();
	bool getCrashed();
	bool getLanded();

	//controls
	void rotateLeft(double rotateAngle);  //max rotation per sec is pi/12
					      //rotateAngle should be a 
					      //positive number.  This function
					      //affects only the variable
					      //rotatedThisTurn.

	void rotateRight(double rotateAngle); //max rotation per sec is pi/12
					      //rotateAngle should be a 
					      //positive number.  This function
					      //affects only the variable
					      //rotatedThisTurn.

	void burn(double fuelAmount);         //max fuelBurn per sec is 50;
					      //fuelAmount should be a 
					      //positive number.  This function
					      //affects only the variable
					      //fuelBurnedThisTurn

	void timeUpdate();		      //this function uses 
					      //rotatedThisturn and 
					      //fuelBurnedThisTurn to simulate
					      //the passage of 1 second of 
					      //time. this vunction updates
					      //angle, thrust, velocity,
					      //position, fuel, crashed, and
					      //landed.  it also resets
 					      //rotatedThisTurn and
					      //fuelBurnedThisTurn
	

private:
	Vect G;        // 1.622 m/s^2 on the moon
	double angle;  // radians.  0 radians is positive x direction
		       // straight up is pi/2 radians
	Vect thrust;   // m/s^2
	Vect velocity; // m/s
	double fuel;   //1 unit of fuel equals 1m/s^2 of acceleration
	Vect position; // meters
	double maxTouchdownVelocity; //do not exceed at landing
	bool crashed;  // becomes true if position.y <=0 and velocity.y
		       // is greater than maxTouchdownVelocity
	bool landed;  // becomes true if position.y <=0 and velocity.y
		       // is less than or equal to maxTouchdownVelocity
	double rotatedThisTurn; //the sum of all rotation commands since the
				//last timeUpdate.  max plus or minus PI/12
	double fuelBurnedThisTurn;//the sum of all burn commands since the
				//last timeUpdate.  max 50

};

#endif
