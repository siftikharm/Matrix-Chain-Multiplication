#pragma once
#include<iostream>
using namespace std;


void PrintOptimalParenthesization(int** S , int i , int j) {
	if (i == j)
		cout << "A" << i;
	else {
		cout << "(";
		PrintOptimalParenthesization(S, i, S[i][j]);
		PrintOptimalParenthesization(S, S[i][j] + 1 , j);
		cout << ")";
	}

}

void MatrixChain(int numMatrices , int* Dimensions) {

	// Two 2D Arrays for Cost(M) and Parenthesizing(S)
	int** M = new int* [numMatrices+ 1];
	int** S = new int* [numMatrices+ 1];
	for (int i = 0; i < numMatrices + 1 ; i++) {
		M[i] = new int[numMatrices + 1];
		S[i] = new int[numMatrices + 1];
	}

	// Arrays Initialized
	for (int i = 0; i < numMatrices + 1; i++) {
		for (int j = 0; j < numMatrices + 1 ; j++) {
			M[i][j] = 0; S[i][j] = 0;
		}
	}



	int j , Min , q;
	for (int diff = 1; diff < numMatrices ; diff++) { // Loop to calculate difference 
		for (int i = 1; i < ( numMatrices + 1) - diff ; i++ ) {
			j = i + diff; 
			
			 Min = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				q = M[i][k] + M[k + 1][j] + (Dimensions[i - 1] * Dimensions[k] * Dimensions[j]);

				if (q < Min) {
					Min = q;
					S[i][j] = k;
				}
			}

			M[i][j] = Min;
		}

	}

	// Printing Results
	cout << "Optimal Dynamic Array : " << endl;
	for (int i = 1; i < numMatrices + 1; i++) {
		for (int j = 1; j < numMatrices + 1; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "Matrix for Parenthesizing : " << endl;
	for (int i = 1; i < numMatrices + 1 ; i++) {
		for (int j = 1; j < numMatrices + 1 ; j++) {
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "\nOptimal Number of Multiplications : " <<  M[1][numMatrices];
	cout << "\nOptimal Parenthesizing : "; PrintOptimalParenthesization(S, 1, numMatrices);


	// Free up the memory
	for (int i = 0; i < numMatrices + 1; ++i) {
		delete[] M[i];
		delete[] S[i];
	}

	delete[] M;
	delete[] S;
}



