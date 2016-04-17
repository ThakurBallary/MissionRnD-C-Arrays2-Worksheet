/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

/*
	date < ArrDate, returns -1
	date == ArrDate, returns 0
	date > ArrDate, returns 1
*/
int compareDate(char *ArrDate, char* date) { 
	int i;
	// year
	i = 6;
	while (i < 10) {
		if (date[i] < ArrDate[i]) {
			return -1;
		}
		else if (ArrDate[i] < date[i]) {
			return 1;
		}
		i++;
	}
	// month
	i = 3;
	while (i < 5) {
		if (date[i] < ArrDate[i]) {
			return -1;
		}
		else if (ArrDate[i] < date[i]) {
			return 1;
		}
		i++;
	}
	// date
	i = 0;
	while (i < 2) {
		if (date[i] < ArrDate[i]) {
			return -1;
		}
		else if (ArrDate[i] < date[i]) {
			return 1;
		}
		i++;
	}
	return 0;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int count = 0, low = 0, high = len - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int dateStatus = compareDate(Arr[mid].date, date);
		if (dateStatus == 1) {
			low = mid + 1;
		}
		else if (dateStatus == 0) {
			count = len - 1 - mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return count;
}
