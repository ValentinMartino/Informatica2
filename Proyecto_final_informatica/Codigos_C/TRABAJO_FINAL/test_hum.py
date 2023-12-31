import sys
import pylab as pl

arguments = len(sys.argv) - 1
print ("Grafico abierto correctamente")

datos = []
for argument in sys.argv[1:]:
	datos.append(float(argument))
pl.ylabel("humedad %")
pl.xlabel("tiempo en min")
pl.title("HUMEDAD")
tiempo = pl.arange(0, 10*len(datos), 10)
pl.plot(tiempo, datos, '.-')

pl.grid()
pl.show()
