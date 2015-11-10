#include <iostream>
#include <complex>

using namespace std;

int main(){

  // Example how to declare a single complex variable:
  //complex<double> c;
  // d = 1 + 2i 
  //complex<double> d = complex<double>(1.0, 2.0); 
  
  complex<double> z0;
  complex<double> z1;
  int i = 0;
  
  for(double re = -2; re <=2; re+=0.005){
    for(double im = -2; im<=2; im+=0.005){
      z0 = complex<double>(re,im);
      z1 = z0 - (z0*z0*z0-1.0)/(3.0*z0*z0);
      i=0;
      while ( (abs(z1-z0)>1e-8) && (i<200) ){
	z0 = z1;
	z1 -= (z1*z1*z1-1.0)/(3.0*z1*z1);
	i++;
      }
      cout << re << "\t" << im << "\t" << i << endl;
    }
  }

  return 0;
}