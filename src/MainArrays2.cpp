/*
Well Done for completing the first part of the C Course ,If you didnt finish 
Do complete them and come here again . 

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int main(){

	//Test countGreaterNumbers
	/*
	struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
	int count = countGreaterNumbers(Arr, 5, "03-03-2005");
	*/

	//Test findSingleOccurenceNumber
	/*
	int A[7] = { 2, 2, 2, 3, 6, 6, 6 };
	printf("%d ", findSingleOccurenceNumber(A, 7));
	*/

	//Test mergeSortedArray
	/*
	struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
	struct transaction *result = mergeSortedArrays(A, 3, B, 3);
	for (int i = 0; i < 6; i++) {
		printf("{ %d, %s, %s }\n", result[i].amount, result[i].date, result[i].description);
	}	
	printf("\n");
	*/

	//Test sortedArraysCommonElements
	/*
	struct transaction A[5] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" } };
	struct transaction B[3] = { { 10, "09-10-2009", "First" }, { 220, "18-01-2010", "22nd" }, { 320, "27-08-2015", "32nd" } };
	struct transaction *result = sortedArraysCommonElements(A, 3, B, 3);
	for (int i = 0; i < 3; i++) {
		printf("{ %d, %s, %s }\n", result[i].amount, result[i].date, result[i].description);
	}
	printf("\n");
	*/
	return 0;
}