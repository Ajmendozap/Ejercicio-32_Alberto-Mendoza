import numpy as np
import matplotlib.pylab as plt

data= np.loadtxt('data.dat')

plt.figure(figsize=(14,4))
    
plt.subplot(1,3,1)
s = np.shape(data)
print(s)
n_x = s[1]
n_t = s[0]
plt.imshow(data, extent=[-1,1,1,0], aspect=2.0)
plt.colorbar(label="$\psi$")
plt.xlabel("Posicion")
plt.ylabel("Tiempo")
plt.title("Solución a la ecuación de onda")
plt.subplot(1,3,2)
x = np.linspace(-1,1,n_x)
delta_t = 1.0/n_t
for i in range(n_t):
    if i%(n_t//9) == 0:
        plt.plot(x, data[i,:], alpha=(i+1)/n_t, color='black', label="t={:.02f}".format(i*delta_t))
plt.legend(loc=1)
plt.xlabel("Posicion")
plt.ylabel("$\psi$")
plt.subplot(1,3,3)
t = np.linspace(0,1,n_t)
plt.plot(t, data[:,n_x//2], alpha=i/n_t, color='black')
plt.xlabel("Tiempo")
plt.ylabel("$\psi$(x=0)")
plt.savefig("Ej32.png", bbox_inches='tight')