Ej32.png : Ej32.py data.dat
	python Ej32.py

data.dat : Ej32.x
	./Ej32.x > data.dat

Ej32.x : Ej32.cpp
	c++ Ej32.cpp -o Ej32.x
	
clean : 
	rm Ej32.x data.dat Ej32.png