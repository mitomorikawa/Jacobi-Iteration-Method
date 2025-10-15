#include <armadillo>
#include "jacobi.h"
#include <iostream>

using namespace std;

int main(){
    arma::mat A = arma::mat("2.0 1.0 1.0; 1.0 3.0 -1.0; -1.0 1.0 2.0");
    arma::vec b = arma::vec("6.0 0.0 3.0");
    arma::vec x = jacobi(A, b);
    arma::cout << x << arma::endl;
}