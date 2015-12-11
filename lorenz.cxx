#include <iostream>
#include <cmath>

using namespace std;

void f(double* gt, double* g, const double a, const double b, const double c);

int main(){
const double a=10.0;
const double b=28.0;
const double c=8.0/3.0;
const double dt= 0.1;
const double N = 100.0/dt;


double k1[3];
double k2[3];
double k3[3];
double k4[3];
double g[3];
double gtemp[3];





//Startwerte
g[0]=1;    //x-Wert
g[1]=1;    //y-Wert
g[2]=1;    //z-Werte

cout << 0 << "\t" << g[0] << "\t" << g[1] << "\t" << g[2] << endl;


for (int i=0; i<N ;i++){

f(k1, g, a, b, c);

gtemp[0]=g[0]+ 0.5*dt*k1[0];
gtemp[1]=g[1]+ 0.5*dt*k1[1];
gtemp[2]=g[2]+ 0.5*dt*k1[2];



f(k2, gtemp, a, b, c);
gtemp[0]=g[0]+0.5*dt*k2[0];
gtemp[1]=g[1]+0.5*dt*k2[1];
gtemp[2]=g[2]+0.5*dt*k2[2];

f(k3, gtemp, a, b, c);

gtemp[0]=g[0]+ dt*k3[0];
gtemp[1]=g[1]+ dt*k3[1];
gtemp[2]=g[2]+ dt*k3[2];


f(k4, gtemp, a, b, c);

g[0]=g[0]+(dt/6.0)*(k1[0]+2.0*k2[0]+2.0*k3[0]+k4[0]);
g[1]=g[1]+(dt/6.0)*(k1[1]+2.0*k2[1]+2.0*k3[1]+k4[1]);
g[2]=g[2]+(dt/6.0)*(k1[2]+2.0*k2[2]+2.0*k3[2]+k4[2]);

cout << i*dt+dt << "\t" << g[0] << "\t" << g[1] << "\t" << g[2] << endl;
}



return 0;

}

void f(double* gt, double* g, const double a, const double b, const double c){
gt[0]=a*(g[1]-g[0]);
gt[1]=g[0]*(b-g[2])-g[1];
gt[2]=g[0]*g[1]-c*g[2];
}

