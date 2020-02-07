        
/* Bessel's function of the first kind */
/*     Author: Shamsul Alam     */
/*      Date: September 30, 2018       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Fact(int n) {
  if (n==0) return 1;
  else return n*Fact(n-1);
}

double Bessel(int n, double x, int M) {
  double alpha=0.0;
  for (int m=0; m<=M-1; m++) {
    alpha += pow(-1.0, m) * pow(x/2.0, 2*m+n) / (Fact(m) * Fact(m+n));
  }
  return alpha;
}

double Evaluate(int n, double x, int M) {
  return pow(-1.0, M) * pow(x/2.0, 2*M+n) / (Fact(M) * Fact(M+n));
}
double absolute(double term){
	    if(term<0) term = term*-1;
	        return term;
}


int main() {
  int n=0, m=0;
  double x=0.0, term=0.0,eps=-0.0, alpha=0.0;

 label1:
  printf("Enter an index (n):") ;
  scanf("%d",&n) ;
  if (n<0) {
    printf( "Error: Invalid index! Expecting a non-negative integer...");
    goto label1;
  }
  printf( "n =%d ",n) ;
  printf( "Enter an argument (x):") ;
  scanf("%lf", &x);
  printf( "x =%lf ", x);
 label2:
  printf("Enter a tolerance (eps):") ;
  scanf(" %lf",&eps);
  if (eps<=0.0) {
    printf( "Error: Invalid tolerance! Expecting a positive number...");
    goto label2;
  }
  printf( "eps =%.10lf\n", eps );
  m=1;
  term = absolute(Evaluate(n,x,m));
  if (term<eps) {
    printf( "Error: Tolerance is too large! Expecting a smaller number...");
    goto label2;
  }
  else
    while (term>eps) {
      m++;
      term = absolute(Evaluate(n,x,m));
    };
  printf( "Evaluating only first M=%d  terms for the given tolerance...", m );
  alpha = Bessel(n,x,m);
  printf( "Jn(x) = %lf  for n = %d, x =  %lf , eps = %.10lf", alpha, n, x, eps);
  return 0;
}


    
