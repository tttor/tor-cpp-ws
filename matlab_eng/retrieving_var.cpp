/* $Revision: 1.1.6.2 $ */
/*
 *	engdemo.cpp
 *
 *	This is a simple program that illustrates how to call the MATLAB
 *	Engine functions from a C++ program.
 *
 * Copyright 1984-2007 The MathWorks, Inc.
 * All rights reserved
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#define  BUFSIZE 256

#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()

{
	Engine *ep;

	/*
	 * Start the MATLAB engine locally by executing the string
	 * "matlab"
	 *
	 * To start the session on a remote host, use the name of
	 * the host as the string rather than \0
	 *
	 * For more complicated cases, use any string with whitespace,
	 * and that string will be executed literally to start MATLAB
	 */
	if (!(ep = engOpen("\0"))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}
  
  // Retriving matrix values
  engEvalString(ep, "X = [1 2; 3 4]");
  
  printf("\nRetrieving X...\n");
  mxArray *X = NULL;
  if ((X = engGetVariable(ep,"X")) == NULL)
    printf("Oops! You didn't create a variable X.\n\n");
  else 
  {
    printf("X is class %s\t\n", mxGetClassName(X));
    printf("Number of rows in array= %d\t\n", mxGetM(X));
    printf("Number of cols in array= %d\t\n", mxGetN(X));
    printf("Number of elements in array= %d\t\n", mxGetNumberOfElements(X));
    
    double* val_arr_ptr;
    val_arr_ptr = mxGetPr(X);
    
    double val_arr[mxGetNumberOfElements(X)];
    for(size_t i=0; i<mxGetNumberOfElements(X); ++i)
    {
      printf("%.3f ",*(val_arr_ptr+i));
      val_arr[i] = *(val_arr_ptr+i);
    }
    printf("\n");
    
    MatrixXd matX;
    matX = Map<MatrixXd>(val_arr,mxGetM(X),mxGetN(X));
    cout << matX << endl;
  }

  // Retriving vector values
  engEvalString(ep, "v = [5 6 7]");
  
  printf("\nRetrieving v...\n");
  mxArray *v = NULL;
  if ((v = engGetVariable(ep,"v")) == NULL)
    printf("Oops! You didn't create a variable v.\n\n");
  else 
  {
    printf("v is class %s\t\n", mxGetClassName(v));
    printf("Number of rows in array= %d\t\n", mxGetM(v));
    printf("Number of cols in array= %d\t\n", mxGetN(v));
    printf("Number of elements in array= %d\t\n", mxGetNumberOfElements(v));
    
    double* val_arr_ptr;
    val_arr_ptr = mxGetPr(v);
    
    double val_arr[mxGetNumberOfElements(v)];
    for(size_t i=0; i<mxGetNumberOfElements(v); ++i)
    {
      printf("%.3f ",*(val_arr_ptr+i));
      val_arr[i] = *(val_arr_ptr+i);
    }
    printf("\n");
    
    VectorXd vec_v;
    vec_v = Map<VectorXd>(val_arr,mxGetN(v));
    cout << vec_v << endl;
  }
  
	/*
	 * We're done! Free memory, close MATLAB engine and exit.
	 */
	printf("Done!\n");
	mxDestroyArray(X);
	engClose(ep);
	
	return EXIT_SUCCESS;
}







