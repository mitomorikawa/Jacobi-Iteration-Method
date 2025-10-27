# Jacobi Iterative Method (C++ with Armadillo) #
This projects implements the Jacobi iterative method using Armadillo. 

# Project structure #

├── src      ── main.cpp          # main() examples
├── include  –– jacobi.h          # Contains the Jacobi method implementation
├── lib      –– armadillo-15.0.3  # Armadillo source codes
└── README.md         

## Requirements ##
•armadillo-15.0.3 (Put the Armadillo source code inside a lib directory located at the same level as the src directory)

## How to run ##
```
g++ main.cpp -I../include -I../lib/armadillo-15.0.3/include -llapack -lblas -o main
./main
```

## How to try the function ##
Just modify the examples in main.cpp and run the programme!

