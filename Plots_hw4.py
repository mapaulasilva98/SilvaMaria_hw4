import numpy as np
import matplotlib.pyplot as plt
import math

### PUNDO ODE ###

def info_bloque(nombre):
	with open(nombre,"r") as archivo:
		numbloques = 0
		longbloque = 0
		longbloques = []

		for linea in archivo:
			if linea.startswith("#"):
				numbloques += 1
				if longbloque > 0:  longbloques.append( longbloque )
				longbloque = 0
			else:
				longbloque += 1

		longbloques.append( longbloque )
		return longbloques

bloques = info_bloque("datosangulos.txt")
d = np.genfromtxt("datosangulos.txt")



lineainicio = 0
lineafin = 0

anuglos=[10,20,30,40,50,60,70]
i=0;

plt.figure()
plt.title("Trayectorias Diferentes Angulos")
for longbloque in bloques:
	lineafin += longbloque
	plt.plot( d[lineainicio:lineafin,1], d[lineainicio:lineafin,2], label=str(anuglos[i]) )
	i=i+1
	lineainicio = lineafin
plt.xlabel("x")
plt.ylabel("y")
plt.legend()	
plt.savefig("datosangulos.png")


datos45= np.genfromtxt("datos45.txt")

plt.figure()
plt.plot(datos45[:,1],datos45[:,2])
plt.title("Trayectoria de 45 Grados")
plt.xlabel("x")
plt.ylabel("y")	
plt.savefig("datos45.png")



#### POUNTO PDE #### 

###### CASO 1 ######

datosmatrizinicial1=np.genfromtxt("datosmatrizinicial1.txt")

plt.figure()
plt.imshow(datosmatrizinicial1,cmap="jet")
plt.title("condiciones iniciales caso 1")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosmatrizinicial1.png")


datospromedio1=np.genfromtxt("datospromedio1.txt")

plt.figure()
plt.plot(datospromedio1[:,0],datospromedio1[:,1])
plt.title("Temperatura Promedio")
plt.xlabel("tiempo")
plt.ylabel("temperatura promedio")
plt.savefig("datospromedio1.png")


datosinter1_1=np.genfromtxt("datosinter1_1.txt")

plt.figure()
plt.imshow(datosinter1_1)
plt.title("Estado intermedio del sistema 1_1")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosinter1_1.png")

datosinter1_2=np.genfromtxt("datosinter1_2.txt")

plt.figure()
plt.imshow(datosinter1_2)
plt.title("Estado intermedio del sistema 1_2")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosinter1_2.png")


datosequilibrio1=np.genfromtxt("datosequilibrio1.txt")

plt.figure()
plt.imshow(datosequilibrio1)
plt.title("Estado de equilibirio 1")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosequilibrio1.png")


###### CASO 2 ######

datosmatrizinicial2=np.genfromtxt("datosmatrizinicial2.txt")

plt.figure()
plt.imshow(datosmatrizinicial2,cmap="jet")
plt.title("condiciones iniciales caso 2")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosmatrizinicial2.png")


datospromedio2=np.genfromtxt("datospromedio2.txt")

plt.figure()
plt.plot(datospromedio2[:,0],datospromedio2[:,1])
plt.title("Temperatura Promedio")
plt.xlabel("tiempo")
plt.ylabel("temperatura promedio")
plt.savefig("datospromedio2.png")


datosinter2_1=np.genfromtxt("datosinter2_1.txt")

plt.figure()
plt.imshow(datosinter2_1)
plt.title("Estado intermedio del sistema 2_1")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosinter2_1.png")

datosinter2_2=np.genfromtxt("datosinter2_2.txt")

plt.figure()
plt.imshow(datosinter2_2)
plt.title("Estado intermedio del sistema 2_2")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosinter2_2.png")


datosequilibrio2=np.genfromtxt("datosequilibrio2.txt")

plt.figure()
plt.imshow(datosequilibrio2)
plt.title("Estado de equilibirio 2")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosequilibrio2.png")


###### CASO 3 ######

datosmatrizinicial3=np.genfromtxt("datosmatrizinicial3.txt")

plt.figure()
plt.imshow(datosmatrizinicial3,cmap="jet")
plt.title("condiciones iniciales caso 3")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosmatrizinicial3.png")


datospromedio3=np.genfromtxt("datospromedio3.txt")

plt.figure()
plt.plot(datospromedio3[:,0],datospromedio3[:,1])
plt.title("Temperatura Promedio")
plt.xlabel("tiempo")
plt.ylabel("temperatura promedio")
plt.savefig("datospromedi3.png")


datosinter3_1=np.genfromtxt("datosinter3_1.txt")

plt.figure()
plt.imshow(datosinter3_1)
plt.title("Estado intermedio del sistema 3_1")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosinter3_1.png")

datosinter3_2=np.genfromtxt("datosinter3_2.txt")

plt.figure()
plt.imshow(datosinter3_2)
plt.title("Estado intermedio del sistema 3_2")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosinter3_2.png")


datosequilibrio3=np.genfromtxt("datosequilibrio3.txt")

plt.figure()
plt.imshow(datosequilibrio3)
plt.title("Estado de equilibirio 3")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("datosequilibrio3.png")



