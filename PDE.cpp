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

// defino mi funcion de la evolucion temporar de la temperatura de la varilla
// doble apuntador para pasar matrices la direccion de memoria fisica donde esta guardad aesa variable 

void evoluciontemp(double** t0, double** t)
{

}


int main ()
{
	cout << v << endl;

	return 0;
}