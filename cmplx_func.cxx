#include <complex>
#include <cmath>
#include <iostream>

using namespace std;

complex<double> tang(double phi) {
  complex<double> ii = complex<double>(0.0, 1.0);
  return tan(phi*(1.0+ii));
}

int main(){
  
  complex<double> ii = complex<double>(0.0, 1.0);
  int N = 100;
  double phi[N];
  phi[0] = -M_PI;
  double d_phi = 2*M_PI/N;
  complex<double> f[N];
  for(int i=0; i<N; i++) {
    //f[i] = exp(phi[i]*ii);
    f[i] = tang(phi[i]);
    phi[i+1] = phi[i] + d_phi;
  }
  for(int i=0; i<N; i++) {
    cout <<phi[i]<< "\t" <<real(f[i])<< "\t" <<imag(f[i])<< "\t" <<abs(f[i])<< endl;
  }
  return 0;
}