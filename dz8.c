#include <stdio.h>

#define maxsize 100

void task1(){

	int len,zamena,srav,peres;
	int massiv[maxsize];
	printf("How many elemts do you want in the list\n");
	scanf_s("%d", &len);


	for (int i = 0; i < len; i++) {
		printf("Please enter the %d st number you want in the array:\n",i+1);
		scanf_s("%d", &massiv[i]);
	}



	srav = 0;
	peres = 0;

	for (int a = 0; a < len-1; a++) {
		for (int b = 0; b < len - a-1 ; b++) {

			srav++;
			if (massiv[b] > massiv[b + 1]) {
				zamena = massiv[b];
				massiv[b] = massiv[b + 1];
				massiv[b + 1] = zamena;
				peres++;
			}

		}
	}
	printf("\n");
	printf("Sorted array is:\n");
	for (int x = 0; x < len; x++) {
		printf("%d\n", massiv[x]);
	}
	printf("Kolichestvo sravnenij: %d, kolichestvo perestonovok: %d\n", srav, peres);

}



void task2(){
	void qs(int massiv2[], int start, int end, int* pere, int* sravn);

	int len2,star,pere,sravn;
	int massiv2[maxsize];

	printf("How many elemts do you want in the list\n");
	scanf_s("%d", &len2);


	for (int i = 0; i < len2; i++) {
		printf("Please enter the %d st number you want in the array:\n", i + 1);
		scanf_s("%d", &massiv2[i]);
	}
	sravn = 0;
	pere = 0;
	star = 0;

	qs(massiv2, star, len2 - 1,&pere,&sravn);

	printf("\n");
	printf("Sorted array is:\n");
	for (int x = 0; x < len2; x++) {
		printf("%d\n", massiv2[x]);
	}

	printf("Kolichestvo sravnenij: %d, kolichestvo perestonovok: %d\n", sravn, pere);

}




int main() {
	int n = 1;
	while (n) {
		printf("\n\n");
		printf("Which task do you want to slove, task 1(bubble sort) or 2(quick sort). (Type 0 to exit):\n");
		scanf_s("%d", &n);
		printf("\n");
		switch (n) {
		case 1: task1(); break;
		case 2: task2(); break;

		}
	}


	return 0;
}


void qs(int massiv2[], int start, int end, int* pere, int* sravn) {



	int piv, i, j, zam;
	piv = end;
	i = start - 1;
	j = start;

	if (start < end) {


		for (int j = start; j < end; j++) {
			*sravn += 1;
			if (massiv2[j] < massiv2[piv]) {
				i++;
				if (i != j) {
					*pere += 1;
					zam = i;
					i = j;
					j = zam;
				}
			}
		}
		if (i + 1 != end) {
			*pere += 1;
			zam = massiv2[i + 1];
			massiv2[i + 1] = massiv2[end];
			massiv2[end] = zam;
		}
		//i+1
		qs(massiv2, start, i, &*pere, &*sravn);
		qs(massiv2, i + 2, end, &*pere, &*sravn);
	}



}