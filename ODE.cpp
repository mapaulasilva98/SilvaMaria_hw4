#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

/*defino ctes*/

const double c = 0.2;
const double m = 0.2;
const double g = 10.0;
const double dt = 0.001;
const double v = 300.0;


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


double GradosToRadianes (double angulo)
{
	return 3.14159*angulo/180.0;
}

int ordenar (double *vector, int tamanio)
{
	int i , j, temporal2;
	double temporal;

	double indicex[tamanio];

	for (i=1;i<tamanio; i++)
	{
		indicex[i]=i;
	}

	for (i=1;i<tamanio;i++)
	{
		for (j=0; j<tamanio-i;j++)
		{
			if(vector[j]>vector[j+1])
			{
				temporal =vector[j], temporal2=indicex[j];
				vector[j]=vector[j+1], indicex[j]=indicex[j+1];
				vector[j+1]=temporal, indicex[j+1]=temporal2;
			}
		}
	}

	return indicex[tamanio-1];
}


int main ()
{
	ofstream data;
	data.open("datos1.txt");
	double x=0.0;
	double y=0.0;
	double vx=v*cos(GradosToRadianes(45.0));
	double vy=v*sin(GradosToRadianes(45.0));	

	for (double t=0; t<10; t+=dt)
	{
		pasoRK(t,x,y,vx,vy);
		data << t <<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
		if (y<=0.0 && t>0.0)
		{
			cout << x <<" m"<<endl;
			break;
		}
	}

	data.close();







/*segunda parte */

	ofstream data2;
	data2.open ("datos2.txt");

	double distancias[7];
	double angulos[7]={10.0,20.0,30.0,40.0,50.0,60.0,70.0};

	for (int i=0; i<7; i++)
	{
		x=0.0, y=0.0, vx=v*cos(GradosToRadianes(angulos[i])), vy=v*sin(GradosToRadianes(angulos[i]));

		for (double t=0; t<10; t+=dt)
		{
			pasoRK(t,x,y,vx,vy);

			data2 << t <<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
			
			if (y<=0.0 && t>0.0)
			{
			/*cout <<"alcance maximo para"<<angulos[i]<< " " << x <<" m"<<endl;*/
			distancias[i]=x;

			break;
			}
		} 

	}

	int indice = ordenar(distancias,7);

	cout << "la mayor dsitancia es para el angulo "<< angulos[indice]<< endl;

	return 0;
}


