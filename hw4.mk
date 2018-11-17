all:
	# corro mi punto de ode
	g++ ODE.cpp -o aode
	./aode
	# corro mi punto de pde
	g++ PDE.cpp -o apde
	./apde
	#para correr mi python 
	python Plots_hw4.py
	pdflatex Resultados_hw4.tex

clean:
	rm *.txt *.png
