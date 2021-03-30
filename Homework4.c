#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);//이중포인터를 이용해 행과 열을 받아 행렬을 생성하는 함수
void print_matrix(int** matrix, int row, int col);//매개변수 이중포인터,행,열을 받아 행렬을 출력하는 함수
int free_matrix(int** matrix, int row, int col);//행렬을 초기화 해주는 함수
int fill_data(int** matrix, int row, int col);//매개변수 이중포인터, 행, 열을 받아 행렬의 값을 채우는 함수
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);//이중포인터를 이용하여 matrix_a와 matrix_b의 이차원 배열과 행,열의 값을 받아 matrix_a와 matrix_b를 더해주는 함수
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);//이중포인터를 이용하여 matrix_a와 matrix_b의 이차원 배열과 행,열의 값을 받아 matrix_a와 matrix_b를 빼주는 함수
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);//matrix에 들어가는 이차원 배열을 전치하여 matrix_t에 들어가는 배열에 대입해주는 함수
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);//matrix_a의 값과 전치된 배열 matrix_t를 곱하는 함수

int main()
{

	char command;//문자열 변수 command 생성
	printf("[----- [정세연]  [2018038027] -----]\n");

	int row, col;//정수형 변수 row,col생성(행과 열을 저장)
	srand(time(NULL));//rand함수 사용 시 나오는 값을 예측 가능하지 못하게 현재의 시각을 주어 시작점을 만들어 주는 함수

	printf("Input row and col : ");
	fflush(stdout);//버퍼 초기화
	scanf("%d %d", &row, &col);
	int** matrix_a = create_matrix(row, col);//이중포인터 matrix_a의 이차원 배열 형식의 행과 열을 만들어줌
	int** matrix_b = create_matrix(row, col);//이중포인터 matrix_b의 이차원 배열 형식의 행과 열을 만들어줌
	int** matrix_a_t = create_matrix(col, row);//이중포인터 matrix_a_t의 이차원 배열 형식의 행과 열을 만들어줌


	printf("Matrix Created.\n");

	if (matrix_a == NULL || matrix_b == NULL) { return -1; }//만약 matrix_a 또는 matrix_b의 값이 NULL값을 갖는다면 -1반환

	do {//matrix manipulation 즉 메뉴를 생성하고 출력하는 조건문
		printf("----------------------------------------------------------------\n");
		printf("                     Matrix Manipulation                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Matrix   = z           Print Matrix        = p \n");
		printf(" Add Matrix          = a           Subtract Matrix     = s \n");
		printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
		printf(" Quit                = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		fflush(stdout);
		scanf(" %c", &command);//command 값을 입력

		switch (command) {//입력받은 command 값에 따라 다른 값을 출력하는 조건문
		case 'z': case 'Z'://'z'또는'Z'를 입력한다면
			printf("Matrix Initialized\n");
			fill_data(matrix_a, row, col);//fill_data함수에 매개변수를 입력받아 이차원 배열 matrix_a에 값을 입력
			fill_data(matrix_b, row, col);//fill_data함수에 매개변수를 입력받아 이차원 배열 matrix_b에 값을 입력
			break;//조건문을 빠져나옴
		case 'p': case 'P'://'p'또는'P'를 입력한다면
			printf("Print matrix\n");
			printf("matrix_a\n");
			print_matrix(matrix_a, row, col);//matrix_a와 row와 col의 값을 받아 행렬을 출력
			printf("matrix_b\n");
			print_matrix(matrix_b, row, col);//matrix_b와 row와 col의 값을 받아 행렬을 출력
			break;//조건문을 빠져나옴
		case 'a': case 'A'://'a'또는'A'를 입력한다면
			printf("Add two matrices\n");
			addition_matrix(matrix_a, matrix_b, row, col);//matrix_a와 matrix_b와 row와 col의 값을 받아 행렬의 합을 해주는 함수
			break;//조건문을 빠져나옴
		case 's': case 'S'://'s'또는'S'를 입력한다면
			printf("Subtract two matrices \n");
			subtraction_matrix(matrix_a, matrix_b, row, col);//matrix_a와 matrix_b와 row와 col의 값을 받아 행렬의 차을 해주는 함수
			break;//조건문을 빠져나옴
		case 't': case 'T'://'t'또는'T'를 입력한다면
			printf("Transpose matrix_a \n");
			transpose_matrix(matrix_a, matrix_a_t, col, row);//matrix_a의 채워진 값과 matrix_a_t의 생성된 행렬과 row와 col의 값을 받아 matrix_a의 전치행렬을 구하는 함수
			print_matrix(matrix_a_t, col, row);//matrix_a_t와 row와 col의 값을 받아 행렬을 출력
			printf("matrix_a\n");
			print_matrix(matrix_a, row, col);//matrix_a와 row와 col의 값을 받아 행렬을 출력
			break;//조건문을 빠져나옴
		case 'm': case 'M'://'m'또는'M'를 입력한다면
			printf("Multiply matrix_a with transposed matrix_a \n");
			transpose_matrix(matrix_a, matrix_a_t, col, row);//matrix_a의 채워진 값과 matrix_a_t의 생성된 행렬과 row와 col의 값을 받아 matrix_a의 전치행렬을 구한다
			multiply_matrix(matrix_a, matrix_a_t, row, col);//matrix_a와 matrix_a_t와 row와 col의 값을 받아 두 행렬의 곱을 구한다
			break;//조건문을 빠져나옴
		case 'q': case 'Q'://'q'또는'Q'를 입력한다면
			printf("Free all matrices..\n");
			free_matrix(matrix_a_t, col, row);//matrix_a_t의 값과 col,row의 값을 받아 matrix_a_t행렬을 해제해준다.
			free_matrix(matrix_a, row, col);//matrix_a의 값과 col,row의 값을 받아 matrix_a_t행렬을 해제해준다.
			free_matrix(matrix_b, row, col);//matrix_b의 값과 col,row의 값을 받아 matrix_a_t행렬을 해제해준다.
			break;//조건문을 빠져나옴
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;//조건문을 빠져나옴
		}

	} while (command != 'q' && command != 'Q');//command값이 q,Q가 아니라면 조건문을 반복

	return 1;//프로그램 종료
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)//이중포인터를 이용해 행과 열을 받아 행렬을 생성하는 함수
{
	/* check pre conditions */
	if(row <= 0 || col <= 0)//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
	{
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	int** matrix = (int**)malloc(sizeof(int*) * row);//**matrix에 동적할당을 이용하여 row개의 정수형 배열을 생성(행에 해당하는 배열생성)

	for (int x = 0; x < row; x++)//for문을 이용하여 0부터 row-1의 값까지 1씩 증가하며 반복
	{
		matrix[x] = (int*)malloc(sizeof(int) * col);//matrix[x]에 동적할당을 이용하여 col개의 정수형 배열을 생성(행 하나에 col개의 정수형 배열 생성)
	}

	if(matrix == NULL)
	{//matrix에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
	   printf("The worng value!\n");
	   return -1;
	}

	return matrix;//matrix를 반환
}
	/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)//매개변수 이중포인터,행,열을 받아 행렬을 출력하는 함수
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
	 printf("Check the sizes of row and col!\n");
	 return -1;
	}

	int x, y;//정수형 변수 x,y 생성

	for (x = 0; x < row; x++)//1씩 증가하며 row번 반복
	{
		for (y = 0; y < col; y++)//1씩 증가하며 col번 반복
		{
			printf("%5d", matrix[x][y]);//반복문을 실행하며 matrix[x][y]에 해당하는 값을 출력
		}
		printf("\n");
	}

	if(matrix == NULL)//matrix에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
	{
	printf("The worng value!\n");
	return -1;
	}

}


	/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)//행렬을 초기화 해주는 함수
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
	  printf("Check the sizes of row and col!\n");
	  return -1;
	}

	int x;//정수형 변수 x를 생성

	for (x = 0; x < row; x++)//1씩 증가하며 row번 반복
	{
		free(matrix[x]);//동적할당으로 생성된 열에 해당하는 배열들을 반복문을 이용하여 해제
	}

	free(matrix);//동적할당으로 생성된 행에 해당하는 배열들을 해제

	if(matrix == NULL)
	{//matrix에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
	  printf("The worng value!\n");
	  return -1;
	}

	return 0;
}



/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)//매개변수 이중포인터, 행, 열을 받아 행렬의 값을 채우는 함수
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
	printf("Check the sizes of row and col!\n");
	return -1;
	}

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			matrix[x][y] = rand() % 20;//반복문을 이용하여 0~19까지의 숫자 중에서 무작위 숫자를 matrix[x][y]에 대입
		}
	}

	if(matrix == NULL)
	{//matrix에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
	   printf("The worng value!\n");
	   return -1;
	}

	return 0;

}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)//matrix_a와 matrix_b의 이차원 배열과 행,열의 값을 받아 matrix_a와 matrix_b를 더해주는 함수
{

	/* check pre conditions */
   if(row <= 0 || col <=0)
   {//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
	printf("Check the sizes of row and col!\n");
	return -1;
   }

	int** matrix_addition = create_matrix(row, col);//이중 포인터 matrix_addition에 create_matrix함수의 값을 반환받아 대입(이차원 배열 생성)

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			matrix_addition[x][y] = matrix_a[x][y] + matrix_b[x][y];//반복문을 이용하여 matrix_a[x][y]와 matrix_b[x][y]를 더해주고 matrix_addition[x][y]에 값을 대입
		}
	}
	if(matrix_addition == NULL)
	{//matrix_addition에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
		printf("The worng value!");
		return -1;
	}


	print_matrix(matrix_addition, row, col);//matrix_addition과 row, col의 값을 대입하여 matrix_addition를 출력
	free_matrix(matrix_addition, row, col);//matrix_addition과 row,col의 값을 대입하여 matrix_addition을 해제

	return 0;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)//matrix_a와 matrix_b의 이차원 배열과 행,열의 값을 받아 matrix_a와 matrix_b를 빼주는 함수
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
       printf("Check the sizes of row and col!\n");
	   return -1;
	}
	int** matrix_sub = create_matrix(row, col);//이중 포인터 matrix_addition에 create_matrix함수의 값을 반환받아 대입(이차원 배열 생성)
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			matrix_sub[x][y] = matrix_a[x][y] - matrix_b[x][y];//반복문을 이용하여 matrix_a[x][y]와 matrix[x][y]를 빼주고 matrix__sub[x][y]에 값을 대입
		}
	}
	if(matrix_sub == NULL)
	{//matrix_sub에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
	  printf("The worng value!\n");
	  return -1;
	}
	print_matrix(matrix_sub, row, col);//matrix_sub과 row, col의 값을 대입하여 matrix_sub를 출력
	free_matrix(matrix_sub, row, col);//matrix_sub과 row, col의 값을 대입하여 matrix_sub를 출력

	return 0;

}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)//matrix에 들어가는 이차원 배열을 전치하여 matrix_t에 들어가는 배열에 대입해주는 함수
{
	if(row <= 0 || col <=0)
	{//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
	  printf("Check the sizes of row and col!\n");
	  return -1;
    }

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col;y++)
		{
			matrix_t[x][y] = matrix[y][x];//matrix[y][x]에 해당하는 값을 matrix_t[x][y]에 대입.(행렬의 전치 = 각 원소의 행과 열의 위치를 바꿈)
		}
	}

	if(matrix == NULL || matrix_t == NULL)
	{//matrix와 matrix_t에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
		printf("The worng value!\n");
		return -1;
	}


	return 0;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)//matrix_a의 값과 전치된 배열 matrix_t를 곱하는 함수
{
	if(row <= 0 || col <=0)
	{//row 와 col의 값이 0보다 작다면 경고문구 출력 후 -1을 반환
	  printf("Check the sizes of row and col!\n");
	  return -1;
	}
	int** matrix_multiple = create_matrix(row, row);//이중 포인터 matrix_multiple에 create_matrix함수의 값을 반환받아 대입(이차원 배열 생성)
	int x, y, i;//정수형 변수 x,y,i 생성
	int tmp = 0;//정수형 변수 tmp를 생성 후 0을 대입.

	for (x = 0; x < row; x++)
	{
		for (y = 0; y < row; y++)
		{
			tmp = 0;//tmp정수를 초기화
			for (i = 0; i < col; i++)
			{
				tmp += matrix_a[x][i] * matrix_t[i][y];//matrix_a[x][i]에 해당하는 값과 matrix_t[i][y]의 값을 곱한 후 반복문을 이용하여 tmp에 더해준다.
			}
			matrix_multiple[x][y] = tmp;//tmp에 저장된 값을 matrix_multiple[x][y]에 대입

		}
	}
	if(matrix_a == NULL || matrix_t == NULL)
	{//matrix_a와 matrix_t에 값이 들어있지 않다면 경고문구를 출력 후 -1을 반환
		printf("The wrong value!\n");
		return -1;
	}

	print_matrix(matrix_multiple, row, row);//matrix_multiple과 row, row를 print_matrix 함수에 대입(행렬을 출력),행렬의 곱의 정의에 의해 row x row 행렬이되므로 col값이 아닌 row값을 대입
	free_matrix(matrix_multiple, row, row);//matrix_multiple과 row,row를 free_matrix함수에 대입하여 행렬을 해제

	return 0;
}
