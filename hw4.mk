# corro mi punto de ode
ODE:	ODE.cpp
	g++ ODE.cpp -o aode
	./aode

# corro mi punto de pde
PDE:	PDE.cpp
	g++ -O2 PDE.cpp -o apde
	./apde
	
plots:	Plots_hw4.py datos45.txt datosangulos.txt datosequilibrio1.txt datosequilibrio2.txt datosequilibrio3.txt datosinter1_1.txt datosinter1_2.txt datosinter2_1.txt datosinter2_2.txt datosinter3_1.txt datosinter3_2.txt datosmatrizinicial1.txt datosmatrizinicial2.txt datosmatrizinicial3.txt datospromedio1.txt datospromedio2.txt datospromedio3.txt
	python Plots_hw4.py

# para generar mi pdf de resultados 
latexpdf: Resultados_hw4.tex datos45.png datosangulos.png datosequilibrio1.png datosequilibrio2.png datosequilibrio3.png datosinter1_1.png datosinter1_2.png datosinter2_1.png datosinter2_2.png datosinter3_1.png datosinter3_2.png datosmatrizinicial1.png datosmatrizinicial2.png datosmatrizinicial3.png datospromedio1.png datospromedio2.png datospromedi3.png
	pdflatex Resultados_hw4.tex

clean:
	rm *.txt *.png

all:	ODE PDE	plots latexpdf