#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"

const double T= 40;
const double rho= 0.01;
const double c= sqrt(T/rho);
const double c_p= c;
void init(double *psi, int n_x);
void print(double *psi, int n_x);
void copy(double *recibe, double *entrega, int n_x);
void evolve(double *psi_new, double *psi_old, double *psi_mold, double delta_t, double delta_x, int n_x);


int main(int argc, char **argv)
{
    double xmax= 1.0;
    int Nx= 100;
    double delta_x= xmax/Nx;
    double delta_t= delta_x/c;
    double y_oldmatrix[Nx][Nx];
    double y_mold[Nx];
    double y_old[Nx];
    double y[Nx];
    init(y,Nx);
    print(y, Nx);
    for(int i=1;i<Nx;i++)
    {
        copy(y_old, y, Nx);
        for(int j=1;j<Nx;j++)
        {
            y_oldmatrix[i][j]=y_old[j];
        }
        if(i>1)
        {
            for(int k=1;k<Nx;k++)
            {
                y_mold[k]=y_oldmatrix[i-1][k];
            }
        }
		evolve(y, y_old, y_mold,delta_t, delta_x, Nx);
        print(y, Nx);
    }
    return 0;
}


void evolve(double *psi_new, double *psi_old, double *psi_mold,double delta_t, double delta_x, int n_x){
  int i;
  for(i=1;i<n_x-1;i++){
    psi_new[i] = psi_old[i];
    psi_new[i] += (2*psi_old[i])-(psi_mold[i])+(psi_old[i+1]+psi_old[i-1]-(2*psi_old[i]));
  }
  
}

void copy(double *recibe, double *entrega, int n_x){
  int i;
  for (i=0;i<n_x;i++){
    recibe[i] = entrega[i];
  }
}

void init(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    psi[i] = (1/10000)*sin(2*3.14159*i);
  }
}

void print(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    std::cout << psi[i] << " ";
  }
  std::cout << "\n";
}
