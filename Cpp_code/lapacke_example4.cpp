#include <iostream>

// This one works
/*

Compiling commands (two steps)
g++ -O -c myprog.cc
g++ myprog.o -o myprog -L/usr/local/lib64 -llapack -lblas -lgfortran -lm

Compiling commands (one step)
g++ -O myprog.cc -o myprog -L/usr/local/lib64 -llapack -lblas -lgfortran -lm

*/


extern "C" {
     void dgesv_(int *n, int *nrhs,  double *a,  int  *lda,  
           int *ipivot, double *b, int *ldb, int *info) ;
}



#define MAX 10

int main(){
   // Values needed for dgesv
   int n;
   int nrhs = 1;
   double a[MAX][MAX];
   double b[1][MAX];
   int lda = MAX;
   int ldb = MAX;
   int ipiv[MAX];
   int info;
   // Other values
   int i,j;

   // Read the values of the matrix
   std::cout << "Enter n \n";
   std::cin >> n;
   std::cout << "On each line type a row of the matrix A followed by one element of b:\n";
   for(i = 0; i < n; i++){
     std::cout << "row " << i << " ";
     for(j = 0; j < n; j++)std::cin >> a[j][i];
     std::cin >> b[0][i];
   }

   // Solve the linear system
   dgesv_(&n, &nrhs, &a[0][0], &lda, ipiv, &b[0][0], &ldb, &info);

   // Check for success
   if(info == 0)
   {
      // Write the answer
      std::cout << "The answer is\n";
      for(i = 0; i < n; i++)
        std::cout << "b[" << i << "]\t" << b[0][i] << "\n";
   }
   else
   {
      // Write an error message
      std::cerr << "dgesv returned error " << info << "\n";
   }
   return info;
}
