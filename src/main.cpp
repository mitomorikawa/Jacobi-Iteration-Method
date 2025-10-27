#include <armadillo>
#include "jacobi.h"
#include <iostream>

using namespace std;

int main(){ // Example usage of the Jacobi method implementation
    arma::vec x1 = jacobi(arma::mat("3 2; 1 5"), arma::vec("5 6")); 
    arma::cout << x1 << arma::endl;

    arma::vec x2 = jacobi(arma::mat("4 2 -1; 1 5 3; 3 3 -7"), arma::vec("15 -61 85"));
    arma::cout << x2 << arma::endl;

    arma::vec x3 = jacobi(arma::mat("14 -1 0 0 3 6 0 0 0 0;"
                                    "0 5 1 1 0 0 1 0 0 -1;" 
                                    "0 0 -3 0 0 0 0 1 2 0;"
                                     "0 0 0 4 1 0 0 2 0 0;" 
                                     "2 0 2 0 7 0 0 0 0 -2;"
                                     "0 2 0 0 0 -6 0 0 0 0;"
                                     "0 0 0 0 0 0 2 0 1 0;"
                                     "7 0 0 0 0 0 0 8 0 0;"
                                     "1 1 1 1 1 1 1 1 10 0;"
                                     "0 0 0 0 0 3 0 0 0 -4;"), 
                          arma::vec("-14 -1 -12 -1 29 22 -1 0 -30 -4"));
    arma::cout << x3 << arma::endl; 

}