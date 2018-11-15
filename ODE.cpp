#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

/*defino ctes*/

const double c = 0.2;
const double m = 0.2;
const double g = 10.0;



/*Definir las funciones para evaluar el metodo de Runge Kutta de cuarto orden*/


double dxdt (double t,double x, double y, double vx, double vy)
{
	return vx;
}

double dydt (double t,double x, double y, double vx, double vy)
{
	return vy;
}

double dvxdt (double t,double x, double y, double vx, double vy)
{
	return -c*(vx*vx+vy*vy)/m*vx/sqrt(vx*vx+vy*vy);
}

double dvydt (double t,double x, double y, double vx, double vy)
{
	return -g-c*(vx*vx+vy*vy)/m*vy/sqrt(vx*vx+vy*vy);
}


int main ()
{

	cout<<dvxdt(0.0,0.0,0.0,10.0,9.0)<<endl;



	return 0;
}


