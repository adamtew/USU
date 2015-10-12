/*If a scientist knows the wavelength of an electromagnetic wave she can determine
what type of radiation it is. Write a program that asks for the wavelength in meters
of an electromagnetic wave and then displays what that wave is according to the 
following chart. (For example, a wave with a wavelength of 1E-10 meters would 
be an X-ray.)

		1*10^-11 1*10^-8      4*10^-7        7*10^-7    1*10^-3   1*10^-2
		   |       |             |               |          |            |  
<------------------------------------------------------------------------------------>
Gamma Rays / XRays / Ultraviolet / Visible Light / Infrared / Microwaves / Radio Waves
*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const double wLen1 = 1 * pow(10, -11), wLen2 = 1 * pow(10, -8), 
				wLen3 = 4 * pow(10, -7), wLen4 = 7 * pow(10, -7), 
				wLen5 = 1 * pow(10, -3), wLen6 = 1 * pow(10, -2);
	double wavelength;

	cout << "\n\n******************";
	cout << "\nSpectral Analysis";
	cout << "\n******************";
	cout << "\n\n\tWavelength in meters: ";
	cin >> wavelength;

	if(wavelength <= wLen1)cout << "\n\tGamma Ray";
	if(wavelength <= wLen2 && wavelength > wLen1)cout << "\n\tX Ray";
	if(wavelength <= wLen3 && wavelength > wLen2)cout << "\n\tUltraviolet";
	if(wavelength <= wLen4 && wavelength > wLen3)cout << "\n\tVisible Light";
	if(wavelength <= wLen5 && wavelength > wLen4)cout << "\n\tInfrared";
	if(wavelength <= wLen6 && wavelength > wLen5)cout << "\n\tMicrowave";
	if(wavelength > wLen6)cout << "\n\tRadio Waves";
	cout << "\n";
	
	return 0;
}