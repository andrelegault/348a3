#include <stdio.h>
 #include <math.h>
 #include <stdlib.h>

 int factorial(unsigned int n) {
     if(n == 0) return 1;
     return n * factorial(n-1);
 }

 double compute_ln(double x, unsigned int n) {
     if(n == 1) return x;
     else {
         double value = pow(x, n) / n;
         if(n % 2 == 0) return compute_ln(x, n-1) - value;
         else return compute_ln(x, n-1) + value;
     }
 }

 double compute_e(double x, unsigned int n) {
     if(n == 0) return 1;
     else if(n == 1) return x;
     else {
         return compute_e(x, n-1) + (pow(x, n)/factorial(n));
     }
 }


 double compute_trig(double x, unsigned int s, unsigned int n) {
     if(s == 1) {
         return compute_e(x, n);
     } else if(s == 2) {
         if(x > 1 || x < -1) {
             fprintf(stderr, "Wrong value for x, exiting.");
             exit(EXIT_FAILURE);
         }
         return compute_ln(x, n);
     } else {
         fprintf(stderr, "Wrong value for s, exiting.");
         exit(EXIT_FAILURE);
     }
 }


 int main(void) {
     double d = compute_trig(4, 1, -15);
     double d1 = compute_trig(0.5, 2, 10);
     printf("%f", d1);
     return 0;
}