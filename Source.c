#include <stdio.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include < malloc.h > // ��� ������������ ������� ���������� �������� ���'�� 
#include <conio.h> // ��� ��������� ��������� ���������
#include <time.h>   

#define size 8 //����� ������

void printArray( int[], int); // �� ��������� ���� ������� �������� �������� �������� ������
int search_Max(int[], int); // ������� � ��� ������� ����� � ����� ������, ������� ����������� �������� �������� ����� ������
int search_Min(int[], int);

void search_Max2(int[], int, int * pMax, int * pIndex); // pMax- ������ ������ �쳳��� Max2, pIndex- ������ ������ ���� index 

void sort_1D(int *z, int S); //���������� ���������� ������ z, S - ����� ������


int ArrayBFunc(int[size], int); // ����� ���������� �� 4 ��������


//void printArray2(int*, int);

//void printArray3(int*, int);

int main()

{

	int num1; 
	//___________________________________________
	int* a;  // �������� �� �����
	int i, j, n, m; // �������:  � - �������� �� �����, m - ������� ��������  i - ������ �����  j ������ �������
	system("chcp 1251");
	system("cls");
	printf("Number of lines: ");
	scanf_s("%d", &n);
	printf("Number of columns: ");
	scanf_s("%d", &m);
	
	//malloc - ������� ��� ���������� ������ ������ � ������ 
	// int sizeof() - ��� ������� ���������� ������ ��������
	// �������� ���'��
	a = (int*)malloc(n * m * sizeof(int));// n�m�(����� ��������)- ��'�� ���'� ���������� ��� ��������� ����������� ������

	//printf("%d ����� ������\n\t = ", a);
 
	// ������ ����� ������� ������
	for (i = 0; i < n; i++)  // ���� �� ������
	{
		for (j = 0; j < m; j++)  // ���� �� ��������
		{
			printf("a[%d][%d] = ", i, j);//index = i*m+j;
			scanf_s("%d", (a + i * m + j)); // � - �������� �� �����, m - ������� ��������  i - ������ �����  j ������ �������
		}
	}
	// ������� ����� ������� ������
	for (i = 0; i < n; i++)  // ���� �� ������
	{
		for (j = 0; j < m; j++) //  ���� �� ��������
		{
			//*(a + i * m + j) ��������� �� �������� index = i*m+j; // ����� �����
			printf("%5d ", *(a + i * m + j)); // ���� ������� 5 ������� �� ������ ������
		}
		printf("\n");
	}

	int ArrayA = *(a + i * m + j);


	num1 = *(a + 0 * m + 1); // ������� � �� j ����� ��������� ���� ���� ������� ������

	printf("\nTransposed matrix A\n");
	for (i = 0; i < n; i++)// ��������� �������, ��� ��������� ���������� � �������
	{
		for (j = 0; j < m; j++)

		{
			int ArrayAT = *(a + j * m + i);
			printf("\t %d ", ArrayAT);
		}
		printf("\n");
	}

	printf("\t\n");


	//printf("����� = \n%5d   ", num1);

//	free(a);
	//getchar();   getchar();
	//-------------------------------------------------------






	int* b;  // �������� �� �����


	// �������� ���'��
	//malloc - ������� ��� ���������� ������ ������ � ������ 
	// int sizeof() - ��� ������� ���������� ������ ��������
	// �������� ���'��
	b = (int*)malloc(n * m * sizeof(int));// n�m�(����� ��������) - ��'�� ���'� ���������� ��� ��������� ����������� ������

	//printf("%d ����� ������\n\t = ", a);
	// ������ ����� ������� ������

	for (i = 0; i < n; i++)  // ���� �� ������
	{
		for (j = 0; j < m; j++)  // ���� �� ��������
		{
			printf("b[%d][%d] = ", i, j);//index = i*m+j;
			scanf_s("%d", (b + i * m + j)); // � - �������� �� �����, m - ������� ��������  i - ������ �����  j ������ �������
		}
	}
	printf("\nmatrix B\t\n ");
	// ������ ����� ������� ������
	for (i = 0; i < n; i++)  // �� ������
	{
		for (j = 0; j < m; j++) //  ���� �� ��������
		{
			//*(a + i * m + j) ��������� �� �������� index = i*m+j; // ����� �����
			printf("%5d ", *(b + i * m + j)); // ���� ������� 5 ������� �� ������ ������
		}
		printf("\n ");
	}
	int ArrayB = *(b + i * m + j);







	//�������� �������
	//(ArrayA) (ArrayB);
	int* c;
	c = (int*)malloc(n * m * sizeof(int));
	int k;
	for (i = 0; i < n; i++)// ��������� �������, ��� ��������� ���������� � �������
	{
		for (j = 0; j < m; j++)

		{

			for (k = 0; k < m; k++) // ������� �������� � ����� ��������
			{
				*(c + i * m + j) = 0;
				/*int tmp2 = (*(b + k * m + j));
				int tmp3 = (*(a + i * m + k));*/


				*(c + i * m + j) += (*(a + k * m + i)) * (*(b + k * m + j));
				/**(c + i * m + j) = (*(a + i * m + k )) * (*(b + k * m + j));*/
				//int nk = (*(a + k * m + i)) * (*(b + k * m + j));
				//printf("\n%d - [%d][%d]", &nk, i,j);
			   // printf("\n%d - [%d][%d]", *(c + i * m + j), i,j);

			}


		}

	}
	printf("\nmultiplication Matrix Result � * �( A transpoed )\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%5dc ", *(c + i * m + j));
		printf("\n");
	}

	/*int ArrayAxB=* (c + 1 * m + 1) = (*(a + 1 * m + 1)) * (*(b + 1 * m + 1));
	printf("%5dC ", ArrayAxB);*/
	//------------------------------------------------------------------------
	// ��������� �������

	int* d;
	d = (int*)malloc(n * m * sizeof(int));

	printf("\n sum of matrics � + � = \n");
	for (i = 0; i < n; i++)// ��������� �������, ��� ��������� ���������� � �������
	{
		for (j = 0; j < m; j++)

		{
			*(d + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
			printf("\t %5d ", *(d + i * m + j));
		}
		printf("\n");
	}

	printf("\t\n");
	//____________________________________________________

	// ���� ������ ������������ �� ���������� �������� ������� � 

	int MinNum, MaxNum;
	MinNum = MaxNum = *(a + 0 * m + 0);
	for (i = 0; i < n; i++)
	{
		// ��������� ������ �������� ������ �
		for (j = 0; j < m; j++)
		{
			//���������� ����� ������� ������ � ����������
			if (*(a + j * m + i) > MaxNum)
			{
				MaxNum = *(a + j * m + i);


			}
			if (*(a + j * m + i) < MinNum)
			{
				MinNum = *(a + j * m + i);


			}

		}
	}
	
	printf("\t\nThe maximum element of the matrix � -  %d\n", MaxNum); //������� ������������ �������


	
	printf("\t\n smallest element of the matrix � - %d\n", MinNum); //������� ��������� �������



	//__________________________________________________________________________





	//���� ���������� ������� �� ���������� 
	int sort;
	
	printf("\n\tMatrix sorting � za zrostaniam ");
	sort = *(a + j * m + i);
	for (int k = 0; k < n * m; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (j != n - 1) {
					if (*(a + (j + 1) * m + i) < *(a + j * m + i)) {
						int tmp = *(a + (j + 1) * m + i);
						*(a + (j + 1) * m + i) = *(a + j * m + i);
						*(a + j * m + i) = tmp;
					}
				}
				else {
					if ((*(a + 0 * m + (i + 1)) < *(a + j * m + i)) && (i != n - 1)) {
						int tmp = *(a + 0 * m + (i + 1));
						*(a + 0 * m + (i + 1)) = *(a + j * m + i);
						*(a + j * m + i) = tmp;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("\t%d", *(a + j * m + i));



	}
	printf("\t\n\n");

	//_______________________________________________________________________________













	int z[size] = {24, 12, 4, 1, 30, 12, 23, 4}; // �� �������� �� ��������� ��� ������� �������� ������

	int max, min, Max2, index; //  Max2 ������ ����������� �������� �������� ������ � index ������ ����� ��������


	printArray(z, size); // �� ��������� ������� printArray, ���������� ������ ������� z

	max = search_Max(z, size);

	printf("\n\nmax=%d", max); //���� ���� max


	min = search_Min(z, size);

	printf("\n\nmin=%d", min);//���� ���� min

	search_Max2(z, size, &Max2, &index);

	printf("\n\nMax2=%d      index=%d \n\n", Max2, index);



	sort_1D(z, size); // ��� ���������� ������
	printf("\n\n\nSorted array:\n"); //��������� ������������� ������

	printArray(z, size);
	printf("\n");

	//printArray2( z, size); // z ������ ������� �������� ������, ����������� � ���� ������, size ����� ������
	//printf("\n");

	//printArray3(z, size); // z ������ ������� �������� ������, ����������� � ���� ������, size ����� ������
	//printf("\n");


	//int y[size] = { 1, 8, 12, 15 }; // �� �������� ���� 4 ������ ������ ����������� ����������
	//int r[size] = { 0 }; //��������� ��� �������� ������
	//int t[size] = { 4 };// ���� ������ ������� ������ ������ �������� 4, �� ���� ������ = 0
		return 0;
}


//____________________

void printArray(int *Z, int S ) // S �������� ����� ��� ������ �������� size
{
	int j;
	for (j = 0; j <= S - 1; j++) { // �������� ��� �� �������� �� ��� ������
		//for (j = S-1; j >= 0; j--)
	
		printf("%4d", Z[j] );
	}
}


//__________________________________

int search_Min( int *z, int S)
{
	int temp_min = z[0]; //����� temp_max ������ �������� ������� �������� ������

	int j;

	for (j = 1; j <= S - 1; j++) { // �������� ��� j �� ������� �� ��� ������, ����������� �������� ��� j �� S-1

		if (z[j] < temp_min) { //�������� ���� �� �������� ������� ������ z ����� ������ j
			temp_min = z[j];
			printf("\ntemp_max=%d", temp_min); // ���� �������� ���� temp_max ��� ������� ��������
			//getch();
		}
	}
	return temp_min;  //����������� � ����� ������� search_Max(z, size);
}

//_____________________________

int search_Max(int *z, int S)
{
	int temp_max = z[0]; //����� temp_max ������ �������� ������� �������� ������

	int j;

	for (j = 1; j <= S - 1; j++) { // �������� ��� j �� ������� �� ��� ������, ����������� �������� ��� j �� S-1

		if (z[j] > temp_max) { //�������� ���� �� �������� ������� ������ z ����� ������ j
			temp_max = z[j];
			printf("\ntemp_max=%d", temp_max); // ���� �������� ���� temp_max ��� ������� ��������
			//getch();
		}
	}
	return temp_max;  //����������� � ����� ������� search_Max(z, size);
}

//_____________________________________

void search_Max2( int *z, int S, int * pMax, int * pIndex)  // pMax- ������ ������ �쳳��� Max2, pIndex- ������ ������ ���� index
{
	int temp_max;
	int temp_index;
	int j;

	temp_max = z[0];
	temp_index = 0;

	for (j = 1; j <= S - 1; j++) {
		if (z[j] > temp_max) {
			temp_max = z[j];
			temp_index = j;
		}
	}
	*pMax = temp_max; // ���� ����� Max2
	*pIndex = temp_index; //���� ���� index
}

//___________________________________________________________________________________

void sort_1D(int *z, int S) // ���������� ������ �� ����������
{
	int pass;
	int j;
	int temp;

	for (pass = 1; pass <= S - 1; pass++) { // ����� pass ������ �������� 1, 2, 3
		for (j = 0; j <= S - 1; j++) {
			if (z[j] < z[j + 1]) {  // ������� j ���� ������ �� ������ ������� j+1, ��� � ����� ������� ������ �� ������
				temp = z[j];
				z[j] = z[j + 1];
				z[j + 1] = temp;

			}
		}

	}
}
//________________________________________________________________

//void printArray2(int* ptr, int S)
//{
//	int j;
//
//	for (j = 0; j <= S - 1; j++) {
//		printf("%5d", (ptr + j));
//	}
//}

//________________________________________________

//void printArray3(int* ptr, int S)
//{
//	int j;
//	printf("  ptr=%p\n", ptr);
//
//	for (j = 0; j <= S - 1; j++) {
//		printf("%5d", *(ptr++));
//		printf("\n\n");
//		printf("  ptr=%p\n", ptr);
//	}
//}




//int main()
//{
//	int a = 25;
//	int * p;
//	int ** p2;
//
//	p = &a;
//
//	p2 = &p;
//	printf("p=%p", p);
//
//	printf("\np2=%p", p2);
//
//	printf("\n&p2=%p", &p2);
//
//	**p2 = **p2 * **p2;
//
//	printf("\n\na=%d", a);
//
//	return 0;
//}