// name: Adam Tew
// A number: A01952442
// section number: 1400-601

#include <iostream>
#include <cmath>

using namespace std;

// This function determines the drawlength. 
//  Insert your code between the start and end comments *only*
float GetX(float distance, float theta){
	float drawlength;
	//TODO: write your code here
	//start of your code
	drawlength = sqrt(0.065 * 9.8 * distance / 25 * (1/sin(2 * theta * 3.1415926 / 180)));
	//end of your code

	return drawlength;
}
	

// make no changes here
int main(){
	float dist,theta;

	dist = 100;
	theta = 1;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 15;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 30;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 45;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 60;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 75;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 89;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;


	return 0;
}
