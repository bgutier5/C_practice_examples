#include <iostream>
using namespace std;
 
int main () {
   const size_t n = 3;
   int matrix[n][n] = {{1,2,3},  // you cannot change the size of matrix dimension
		       {4,5,6},  // unless you specify it with const 
		       {7,8,9}
                      };
   // for loop execution
   for( int i = 0; i < n; i = i + 1 ) {
	for (int j = 0; j < n; j = j + 1){
		cout << "M[" << i << ']' << '['<< j << "] = " << matrix[i][j] << endl;
        }
   }
 
   return 0;
}
