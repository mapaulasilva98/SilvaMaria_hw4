#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

/*defino ctes*/

const double c = 0.2;
const double m = 0.2;
const double g = 10.0;
const double dt = 0.001;


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


/*cada paso de RK llamara tiempo x, y velocidad en x y en y*/

void pasoRK (double &t, double &x, double &y, double &vx, double &vy)
{
	double paso1_1,paso1_2,paso1_3,paso1_4;
	paso1_1=dt*dxdt(t, x, y, vx, vy);
	paso1_2=dt*dydt(t, x, y, vx, vy);
	paso1_3=dt*dvxdt(t, x, y, vx, vy);
	paso1_4=dt*dvydt(t, x, y, vx, vy);

	double paso2_1,paso2_2,paso2_3,paso2_4;
	paso2_1=dt*dxdt(t+0.5*dt, x+0.5*paso1_1, y+0.5*paso1_2, vx+0.5*paso1_3, vy+0.5*paso1_4);
	paso2_2=dt*dydt(t+0.5*dt, x+0.5*paso1_1, y+0.5*paso1_2, vx+0.5*paso1_3, vy+0.5*paso1_4);
	paso2_3=dt*dvxdt(t+0.5*dt, x+0.5*paso1_1, y+0.5*paso1_2, vx+0.5*paso1_3, vy+0.5*paso1_4);
	paso2_4=dt*dvydt(t+0.5*dt, x+0.5*paso1_1, y+0.5*paso1_2, vx+0.5*paso1_3, vy+0.5*paso1_4);

	double paso3_1,paso3_2,paso3_3,paso3_4;
	paso3_1=dt*dxdt(t+0.5*dt, x+0.5*paso2_1, y+0.5*paso2_2, vx+0.5*paso2_3, vy+0.5*paso2_4);
	paso3_2=dt*dydt(t+0.5*dt, x+0.5*paso2_1, y+0.5*paso2_2, vx+0.5*paso2_3, vy+0.5*paso2_4);
	paso3_3=dt*dvxdt(t+0.5*dt, x+0.5*paso2_1, y+0.5*paso2_2, vx+0.5*paso2_3, vy+0.5*paso2_4);
	paso3_4=dt*dvydt(t+0.5*dt, x+0.5*paso2_1, y+0.5*paso2_2, vx+0.5*paso2_3, vy+0.5*paso2_4);

	double paso4_1,paso4_2,paso4_3,paso4_4;
	paso4_1=dt*dxdt(t+1.0*dt, x+1.0*paso3_1, y+1.0*paso3_2, vx+1.0*paso3_3, vy+1.0*paso3_4);
	paso4_2=dt*dydt(t+1.0*dt, x+1.0*paso3_1, y+1.0*paso3_2, vx+1.0*paso3_3, vy+1.0*paso3_4);
	paso4_3=dt*dvxdt(t+1.0*dt, x+1.0*paso3_1, y+1.0*paso3_2, vx+1.0*paso3_3, vy+1.0*paso3_4);
	paso4_4=dt*dvydt(t+1.0*dt, x+1.0*paso3_1, y+1.0*paso3_2, vx+1.0*paso3_3, vy+1.0*paso3_4);

	t+=dt;
	x+=(paso1_1+2*(paso2_1+paso3_1)+paso4_1)*1/6.0;
	y+=(paso1_2+2*(paso2_2+paso3_2)+paso4_2)*1/6.0;
	vx+=(paso1_3+2*(paso2_3+paso3_3)+paso4_3)*1/6.0;
	vy+=(paso1_4+2*(paso2_4+paso3_4)+paso4_4)*1/6.0;


}



int main ()
{

	



	return 0;
}


