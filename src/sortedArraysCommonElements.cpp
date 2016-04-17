/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int commonDates(char *A_date, char *B_date) {
	int i;
	// year
	i = 6;
	while (i < 10 ) {
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

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen < 1 || BLen < 1) {
		return NULL;
	}
	struct transaction *commonElements = (struct transaction *) malloc(sizeof(struct transaction) * (ALen < BLen ? ALen : BLen));
	int i = 0, j = 0, k = 0;
	while (i < ALen && j < BLen) {
		int date = commonDates(A[i].date, B[j].date);
		if (date == -1) {
			i++;
		}
		else if (date == 1) {
			j++;
		}
		else {
			commonElements[k] = A[i];
			k++;
			i++;
			j++;
		}
	}
	if (k == 0) {
		return NULL;
	}
	return commonElements;
}