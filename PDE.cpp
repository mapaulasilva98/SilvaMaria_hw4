#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

const int N=100;
const double L=50.0;
const double h=L/N;

const double dt=0.01;

const double k=1.62;
const double cp=820.0;
const double p=2.71;
//const double v=k/(cp*p);
const double v=0.01;

const double wx=v*dt/(h*h);
const double wy=v*dt/(h*h);

const double dx=-2.0+h*h/(2.0*v*dt);
const double dy=-2.0+h*h/(2.0*v*dt);

const int rreal= 5;
const int r=rreal*N/L;


void condicioninterna(double** t)
{

	for (int i=0; i<N; i++)
	{
		 for (int j=0; j<N; j++)
		 {
		 	if(pow(i-N/2,2)+pow(j-N/2,2)<=r*r)
		 	{
		 		t[i][j]=100.0;
		 	}
		 }
	}

}

//El el caso 1 considere que tiene condiciones de frontera fijas a 10 grados centigrados.

void condicionfrontera(double** t)
{

	for (int i=0; i<N; i++)
	{
		t[i][0]=10.0;
		t[0][i]=10.0;
		t[N-1][i]=10.0;
		t[i][N-1]=10.0;
	}


}

// defino mi funcion de la evolucion temporar de la temperatura de la varilla
// doble apuntador para pasar matrices la direccion de memoria fisica donde esta guarda esa variable 
// eps es la condicion de equilibrio donde comparo la temperatura actual con el aterior
// promedio es para generar el promedio de las tempreraturas 

void evoluciontemp(double** t0, double** t, double &eps, double &promedio)
{

	for (int i=1;i<N-1;i++)
	{
		for (int j=1;j<N-1;j++)
		{
			t[i][j]=wx*(t0[i-1][j]+t0[i+1][j]+t0[i][j]*dx)+wy*(t0[i][j-1]+t0[i][j+1]+t0[i][j]*dy);
		}
	}

	double diferencia = 0.0;


	for (int i=1; i<N-1; i++)
	{
		for (int j=1;j<N-1;j++)
		{
			diferencia = t0[i][j]-t[i][j];
			eps+=pow(diferencia,2);
			promedio+=t[i][j];
			t0[i][j]=t[i][j];
		}
	}

promedio/=N*N;

}


//este es para hacer las condiciones de frontera periodicas donde le primero me arregla mis problemas y el segundo realiza la evolucion 

int arreglarperiodico(int i)
{
	return (N+i%N)%N;
}

void evoluciontempperiodico(double** t0, double** t, double &eps, double &promedio)
{

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			t[i][j]=wx*(t0[arreglarperiodico(i-1)][j]+t0[arreglarperiodico(i+1)][j]+t0[i][j]*dx)+wy*(t0[i][arreglarperiodico(j-1)]+t0[i][arreglarperiodico(j+1)]+t0[i][j]*dy);
		}
	}

	double diferencia = 0.0;


	for (int i=1; i<N-1; i++)
	{
		for (int j=1;j<N-1;j++)
		{
			diferencia = t0[i][j]-t[i][j];
			eps+=pow(diferencia,2);
			promedio+=t[i][j];
			t0[i][j]=t[i][j];
		}
	}

promedio/=N*N;

}



double** crearmatriz(int N)
{
	double** mat;

	mat=new double*[N];

	for (int i=0; i<N; i++)
	{
		mat[i]=new double[N];

	}

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{

			mat[i][j]=0.0;
		}
	}


return mat;

}

void borrarmatriz(double** mat)
{
	for (int i=0; i<N; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}


void escribirarchivo(double** mat, string nombre)
{
	ofstream datos;
	datos.open(nombre);

	for (int i=0; i<N; i++)
	{
		for (int j=0;j<N;j++)
		{
			datos << mat[i][j] << "\t" ;
		}

		datos << endl ;

	}

datos.close();


}





int main ()
{
	
double** t0=crearmatriz(N);

double** t=crearmatriz(N);

double eps;
double promedio;
double T=0.0;


ofstream datospromedio;

// para el promedio de las t 
datospromedio.open("datospromedio1.txt");

condicioninterna(t0);
condicionfrontera(t0);


// para condiciones inciales caso 1 
escribirarchivo(t0,"datosmatrizinicial1.txt");


// para evolucion de frontera fija

for (int i=0; i<200000; i++)
{
	eps=0.0;
	promedio=0.0;
	condicioninterna(t0);
	condicionfrontera(t0);
	evoluciontemp(t0,t, eps, promedio);
	datospromedio << T << " " << promedio << endl;
	T+=dt;

// para condiciones intermedios caso 1 
	if( i==1000)
	{
		escribirarchivo(t,"datosinter1_1.txt");

	}

	if( i==5000)
	{
		escribirarchivo(t,"datosinter1_2.txt");

	}

	if(sqrt(eps<=0.01))
	{
		break;
	}
}

datospromedio.close();

// para equilibrio caso 1 
escribirarchivo(t,"datosequilibrio1.txt");
	
// aqui termina mi condicion de frontera fija



// aqui EMPIEZA cond frontera abierta  caso 2

T=0.0;
t0 = crearmatriz(N);
t=crearmatriz(N);
ofstream datospromedio2;

// para el promedio de las t 
datospromedio2.open("datospromedio2.txt");

condicioninterna(t0);


// para condiciones inciales caso 2 
escribirarchivo(t0,"datosmatrizinicial2.txt");


// para evolucion de frontera libre 2

for (int i=0; i<200000; i++)
{
	eps=0.0;
	promedio=0.0;
	condicioninterna(t0);
	evoluciontemp(t0,t, eps, promedio);
	datospromedio2 << T << " " << promedio << endl;
	T+=dt;
	

// para condiciones intermedios caso 2 
	if( i==1000)
	{
		escribirarchivo(t,"datosinter2_1.txt");

	}

	if( i==5000)
	{
		escribirarchivo(t,"datosinter2_2.txt");

	}

	if(sqrt(eps<=0.01))
	{
		break;
	}
}

datospromedio2.close();

// para equilibrio caso 2 
escribirarchivo(t,"datosequilibrio2.txt");

// aqui termina caso 2 


// aqui EMPIEZA cond frontera abierta  caso 3

T=0.0;
t0 = crearmatriz(N);
t=crearmatriz(N);
ofstream datospromedio3;

// para el promedio de las t del caso 3
datospromedio3.open("datospromedio3.txt");

condicioninterna(t0);


// para condiciones inciales caso 3 
escribirarchivo(t0,"datosmatrizinicial3.txt");



for (int i=0; i<200000; i++)
{
	eps=0.0;
	promedio=0.0;
	condicioninterna(t0);
	evoluciontempperiodico(t0,t, eps, promedio);
	datospromedio3 << T << " " << promedio << endl;
	T+=dt;
	

// para condiciones intermedios caso 3 
	if( i==1000)
	{
		escribirarchivo(t,"datosinter3_1.txt");

	}

	if( i==5000)
	{
		escribirarchivo(t,"datosinter3_2.txt");

	}

	if(sqrt(eps<=0.01))
	{
		break;
	}
}

datospromedio3.close();

// para equilibrio caso 3
escribirarchivo(t,"datosequilibrio3.txt");

// aqui termina caso 3




borrarmatriz(t0);
borrarmatriz(t);



	return 0;
}











