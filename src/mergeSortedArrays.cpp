/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compareDateForMerge(char *A_date, char* B_date) {
	int i;
	// year
	i = 6;
	while (i < 10) {
		if (A_date[i] < B_date[i]) {
			return -1;
		}
		else if (B_date[i] < A_date[i]) {
			return 1;
		}
		i++;
	}
	// month
	i = 3;
	while (i < 5) {
		if (A_date[i] < B_date[i]) {
			return -1;
		}
		else if (B_date[i] < A_date[i]) {
			return 1;
		}
		i++;
	}
	// date
	i = 0;
	while (i < 2) {
		if (A_date[i] < B_date[i]) {
			return -1;
		}
		if (B_date[i] < A_date[i]) {
			return 1;
		}
		i++;
	}
	return 0;
}

void insertIntoC(struct transaction *C, int *k, struct transaction *AorB, int *l) {
	C[*k] = AorB[*l];
	(*k)++;
	(*l)++;
}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen < 1 || BLen < 1) {
		return NULL;
	}
	struct transaction *C = (struct transaction *) malloc(sizeof(struct transaction) * (ALen + BLen));
	int i = 0, j = 0, k = 0;
	while (i < ALen && j < BLen) {
		int dateStatus = compareDateForMerge(A[i].date, B[j].date);	
		if (dateStatus == -1) {
			insertIntoC(C, &k, A, &i);
		}
		else if (dateStatus == 1) {
			insertIntoC(C, &k, B, &j);
		}
		else {
			insertIntoC(C, &k, A, &i);
			insertIntoC(C, &k, B, &j);
		}	
	}	
	while (i < ALen) {
		// remaining elements from A
		insertIntoC(C, &k, A, &i);
	}
	while (j < BLen) {
		//remaining elements from B
		insertIntoC(C, &k, B, &j);
	}

	return C;
}