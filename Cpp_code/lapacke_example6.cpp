#include <iostream>

/*

Compiling and linking lapack commands (two steps)
g++ -O -c myprog.cc
g++ myprog.o -o myprog -L/usr/local/lib64 -llapack -lblas -lgfortran -lm

Compiling commands (one step)
g++ -O myprog.cc -o myprog -L/usr/local/lib64 -llapack -lblas -lgfortran -lm

*/

/* File description
 
This file already compiles, however the function dgegs obtains the eigenvalues of two given matrices. Therefore, not useful for my purposes.

*/



extern "C" {
     void dgegs_(char *jobvsl, char *jobvsr,  int *n, double *a, int  *lda, double *b, int *ldb, double *alphar,
             double *alphai, double *beta, double *vsl, int *ldvsl, double *vsr, int *ldvsr, double *work, int *lwork, int *info) ;  // double *vsl, (missing) 
}



#define MAX 10

int main(){

   // Values needed for dgegs
   char jobvsl = 'N';
   char jobvsr = 'N';
   int  n = 2;  
   int lda = MAX;
   //double a[lda][n];
   int ldb = MAX;
   double b[ldb][n];
   double alphar[n];
   double alphai[n];
   double beta[n];
   int ldvsl = n; 
   double vsl[ldvsl][n];
   int ldvsr = n;
   double vsr[ldvsr][n];
   int lwork =  4*n;   //2*n +n;
   double work[1][lwork];
   int info;

   // Declared matrices/arrays
   double a[MAX][MAX] = {{1,2,3},  
                         {2,3,4},   
                         {3,4,1}};

   //double b[1][MAX] = {-4,-1,-2}; 



   // Solve the linear system
   dgegs_(&jobvsl, &jobvsr, &n, &a[0][0], &lda, &b[0][0], &ldb, alphar, alphai, beta, &vsl[0][0], &ldvsl, &vsr[0][0], &ldvsr, &work[0][0], &lwork, &info);

   // Check for success
   if(info == 0)
   {
      // Write the answer
      std::cout << "The answer is\n";
      for(int i = 0; i < n; i++)
        std::cout << "b[" << i << "]\t" << beta[i] << "\n";
   }
   else
   {
      // Write an error message
      std::cerr << "dgesv returned error " << info << "\n";
   }
   return info;
}
