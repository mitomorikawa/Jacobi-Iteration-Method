#include <armadillo>
#include <cmath>
#include <exception>
using namespace std;

/* Exceptions are thrown if A doesn't meet the following assumptions: 
    1. None of the diagonal elements of A should be zero.
    2. A should be diagonally dominant.
*/
class ZerosInDiagonalException : public exception {
public:
    ZerosInDiagonalException(){};

    const char* what() const noexcept override {
        return "Zeros in the main diagonal.";
    }
}; 

class NotDiagonallyDominantException : public exception {
public:
    NotDiagonallyDominantException(){};

    const char* what() const noexcept override {
        return "A is not diagonally dominant.";
    }
};

arma::vec jacobi(arma::mat A, arma::vec b, int max_iter=1000, double eps=1e-5){
    // A must be diagonally dominant for the algorithm to converge.
    int n = size(b)[0];
    

    // 1. Check if A is diagonally dominant & no zeros on its main diagonal
    try{
        for (int i = 0; i < n; i++){
            double nonDiagElem = 0;
            double diag_i = abs(A(i, i));
            if (diag_i == 0) throw ZerosInDiagonalException();
            for (int j = 0; j < n; j++){
                nonDiagElem += abs(A(i, j));
            }
            nonDiagElem -= diag_i;
            
            if (diag_i < nonDiagElem) {
                throw NotDiagonallyDominantException();      
            }
        } 
    } catch(NotDiagonallyDominantException &e){
        cout << e.what();
    } catch(ZerosInDiagonalException &e){
        cout << e.what();
    }

    arma::mat D = arma::diagmat(A); // Diagonal component
    arma::mat R = A - D;            // Remainder

    int iterations = 0;

    arma::vec x = arma::vec(n).randn(); // Initialise x randomly
    arma::vec prev_x = arma::vec(n).fill(INT_MAX); // variable that saves x from the previous iteration to detect convergence

    // Update x iteratively
    while (iterations < max_iter && arma::norm(x - prev_x) >= eps) {
        prev_x = x;
        x = arma::inv(arma::diagmat(D)) * (b - R * x);
        iterations++;
        if (iterations%100 == 0) std::cout << iterations << " " << arma::norm(x - prev_x) << std::endl;
    } 
    std::cout << iterations << " " << arma::norm(x - prev_x) << std::endl;
    return x;
}