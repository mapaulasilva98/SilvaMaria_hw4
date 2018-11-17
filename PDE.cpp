#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

const int N=100;
const double L=50.0;

const double h=N/L;

const double dt=0.01;

const double k=1.62;
const double cp=820.0;
const double p=2.71;
const double v=k/(cp*p);

const double wx=v*dt/(h*h);
const double wy=v*dt/(h*h);

const double dx=-2.0+h*h/(2.0*v*dt);
const double dy=-2.0+h*h/(2.0*v*dt);

// defino mi funcion de la evolucion temporar de la temperatura de la varilla
// doble apuntador para pasar matrices la direccion de memoria fisica donde esta guardad aesa variable 

void evoluciontemp(double** t0, double** t)
{

	for (int i=1;i<N-1;i++)
	{
		for (int j=1;j<N-1;j++)
		{
			t[i][j]=wx*(t0[i-1][j]+t0[i+1][j]*t0[i][j]*dx)+wy*(t0[i][j-1]+t0[i][j+1]*t0[i][j]*dy);
		}
	}
}


int main ()
{
	cout << v << endl;

	return 0;
}