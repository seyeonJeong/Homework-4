#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);//���������͸� �̿��� ��� ���� �޾� ����� �����ϴ� �Լ�
void print_matrix(int** matrix, int row, int col);//�Ű����� ����������,��,���� �޾� ����� ����ϴ� �Լ�
int free_matrix(int** matrix, int row, int col);//����� �ʱ�ȭ ���ִ� �Լ�
int fill_data(int** matrix, int row, int col);//�Ű����� ����������, ��, ���� �޾� ����� ���� ä��� �Լ�
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);//���������͸� �̿��Ͽ� matrix_a�� matrix_b�� ������ �迭�� ��,���� ���� �޾� matrix_a�� matrix_b�� �����ִ� �Լ�
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);//���������͸� �̿��Ͽ� matrix_a�� matrix_b�� ������ �迭�� ��,���� ���� �޾� matrix_a�� matrix_b�� ���ִ� �Լ�
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);//matrix�� ���� ������ �迭�� ��ġ�Ͽ� matrix_t�� ���� �迭�� �������ִ� �Լ�
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);//matrix_a�� ���� ��ġ�� �迭 matrix_t�� ���ϴ� �Լ�

int main()
{

	char command;//���ڿ� ���� command ����
	printf("[----- [������]  [2018038027] -----]\n");

	int row, col;//������ ���� row,col����(��� ���� ����)
	srand(time(NULL));//rand�Լ� ��� �� ������ ���� ���� �������� ���ϰ� ������ �ð��� �־� �������� ����� �ִ� �Լ�

	printf("Input row and col : ");
	fflush(stdout);//���� �ʱ�ȭ
	scanf("%d %d", &row, &col);
	int** matrix_a = create_matrix(row, col);//���������� matrix_a�� ������ �迭 ������ ��� ���� �������
	int** matrix_b = create_matrix(row, col);//���������� matrix_b�� ������ �迭 ������ ��� ���� �������
	int** matrix_a_t = create_matrix(col, row);//���������� matrix_a_t�� ������ �迭 ������ ��� ���� �������


	printf("Matrix Created.\n");

	if (matrix_a == NULL || matrix_b == NULL) { return -1; }//���� matrix_a �Ǵ� matrix_b�� ���� NULL���� ���´ٸ� -1��ȯ

	do {//matrix manipulation �� �޴��� �����ϰ� ����ϴ� ���ǹ�
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
		scanf(" %c", &command);//command ���� �Է�

		switch (command) {//�Է¹��� command ���� ���� �ٸ� ���� ����ϴ� ���ǹ�
		case 'z': case 'Z'://'z'�Ǵ�'Z'�� �Է��Ѵٸ�
			printf("Matrix Initialized\n");
			fill_data(matrix_a, row, col);//fill_data�Լ��� �Ű������� �Է¹޾� ������ �迭 matrix_a�� ���� �Է�
			fill_data(matrix_b, row, col);//fill_data�Լ��� �Ű������� �Է¹޾� ������ �迭 matrix_b�� ���� �Է�
			break;//���ǹ��� ��������
		case 'p': case 'P'://'p'�Ǵ�'P'�� �Է��Ѵٸ�
			printf("Print matrix\n");
			printf("matrix_a\n");
			print_matrix(matrix_a, row, col);//matrix_a�� row�� col�� ���� �޾� ����� ���
			printf("matrix_b\n");
			print_matrix(matrix_b, row, col);//matrix_b�� row�� col�� ���� �޾� ����� ���
			break;//���ǹ��� ��������
		case 'a': case 'A'://'a'�Ǵ�'A'�� �Է��Ѵٸ�
			printf("Add two matrices\n");
			addition_matrix(matrix_a, matrix_b, row, col);//matrix_a�� matrix_b�� row�� col�� ���� �޾� ����� ���� ���ִ� �Լ�
			break;//���ǹ��� ��������
		case 's': case 'S'://'s'�Ǵ�'S'�� �Է��Ѵٸ�
			printf("Subtract two matrices \n");
			subtraction_matrix(matrix_a, matrix_b, row, col);//matrix_a�� matrix_b�� row�� col�� ���� �޾� ����� ���� ���ִ� �Լ�
			break;//���ǹ��� ��������
		case 't': case 'T'://'t'�Ǵ�'T'�� �Է��Ѵٸ�
			printf("Transpose matrix_a \n");
			transpose_matrix(matrix_a, matrix_a_t, col, row);//matrix_a�� ä���� ���� matrix_a_t�� ������ ��İ� row�� col�� ���� �޾� matrix_a�� ��ġ����� ���ϴ� �Լ�
			print_matrix(matrix_a_t, col, row);//matrix_a_t�� row�� col�� ���� �޾� ����� ���
			printf("matrix_a\n");
			print_matrix(matrix_a, row, col);//matrix_a�� row�� col�� ���� �޾� ����� ���
			break;//���ǹ��� ��������
		case 'm': case 'M'://'m'�Ǵ�'M'�� �Է��Ѵٸ�
			printf("Multiply matrix_a with transposed matrix_a \n");
			transpose_matrix(matrix_a, matrix_a_t, col, row);//matrix_a�� ä���� ���� matrix_a_t�� ������ ��İ� row�� col�� ���� �޾� matrix_a�� ��ġ����� ���Ѵ�
			multiply_matrix(matrix_a, matrix_a_t, row, col);//matrix_a�� matrix_a_t�� row�� col�� ���� �޾� �� ����� ���� ���Ѵ�
			break;//���ǹ��� ��������
		case 'q': case 'Q'://'q'�Ǵ�'Q'�� �Է��Ѵٸ�
			printf("Free all matrices..\n");
			free_matrix(matrix_a_t, col, row);//matrix_a_t�� ���� col,row�� ���� �޾� matrix_a_t����� �������ش�.
			free_matrix(matrix_a, row, col);//matrix_a�� ���� col,row�� ���� �޾� matrix_a_t����� �������ش�.
			free_matrix(matrix_b, row, col);//matrix_b�� ���� col,row�� ���� �޾� matrix_a_t����� �������ش�.
			break;//���ǹ��� ��������
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;//���ǹ��� ��������
		}

	} while (command != 'q' && command != 'Q');//command���� q,Q�� �ƴ϶�� ���ǹ��� �ݺ�

	return 1;//���α׷� ����
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)//���������͸� �̿��� ��� ���� �޾� ����� �����ϴ� �Լ�
{
	/* check pre conditions */
	if(row <= 0 || col <= 0)//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
	{
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	int** matrix = (int**)malloc(sizeof(int*) * row);//**matrix�� �����Ҵ��� �̿��Ͽ� row���� ������ �迭�� ����(�࿡ �ش��ϴ� �迭����)

	for (int x = 0; x < row; x++)//for���� �̿��Ͽ� 0���� row-1�� ������ 1�� �����ϸ� �ݺ�
	{
		matrix[x] = (int*)malloc(sizeof(int) * col);//matrix[x]�� �����Ҵ��� �̿��Ͽ� col���� ������ �迭�� ����(�� �ϳ��� col���� ������ �迭 ����)
	}

	if(matrix == NULL)
	{//matrix�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
	   printf("The worng value!\n");
	   return -1;
	}

	return matrix;//matrix�� ��ȯ
}
	/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)//�Ű����� ����������,��,���� �޾� ����� ����ϴ� �Լ�
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
	 printf("Check the sizes of row and col!\n");
	 return -1;
	}

	int x, y;//������ ���� x,y ����

	for (x = 0; x < row; x++)//1�� �����ϸ� row�� �ݺ�
	{
		for (y = 0; y < col; y++)//1�� �����ϸ� col�� �ݺ�
		{
			printf("%5d", matrix[x][y]);//�ݺ����� �����ϸ� matrix[x][y]�� �ش��ϴ� ���� ���
		}
		printf("\n");
	}

	if(matrix == NULL)//matrix�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
	{
	printf("The worng value!\n");
	return -1;
	}

}


	/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)//����� �ʱ�ȭ ���ִ� �Լ�
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
	  printf("Check the sizes of row and col!\n");
	  return -1;
	}

	int x;//������ ���� x�� ����

	for (x = 0; x < row; x++)//1�� �����ϸ� row�� �ݺ�
	{
		free(matrix[x]);//�����Ҵ����� ������ ���� �ش��ϴ� �迭���� �ݺ����� �̿��Ͽ� ����
	}

	free(matrix);//�����Ҵ����� ������ �࿡ �ش��ϴ� �迭���� ����

	if(matrix == NULL)
	{//matrix�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
	  printf("The worng value!\n");
	  return -1;
	}

	return 0;
}



/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)//�Ű����� ����������, ��, ���� �޾� ����� ���� ä��� �Լ�
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
	printf("Check the sizes of row and col!\n");
	return -1;
	}

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			matrix[x][y] = rand() % 20;//�ݺ����� �̿��Ͽ� 0~19������ ���� �߿��� ������ ���ڸ� matrix[x][y]�� ����
		}
	}

	if(matrix == NULL)
	{//matrix�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
	   printf("The worng value!\n");
	   return -1;
	}

	return 0;

}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)//matrix_a�� matrix_b�� ������ �迭�� ��,���� ���� �޾� matrix_a�� matrix_b�� �����ִ� �Լ�
{

	/* check pre conditions */
   if(row <= 0 || col <=0)
   {//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
	printf("Check the sizes of row and col!\n");
	return -1;
   }

	int** matrix_addition = create_matrix(row, col);//���� ������ matrix_addition�� create_matrix�Լ��� ���� ��ȯ�޾� ����(������ �迭 ����)

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			matrix_addition[x][y] = matrix_a[x][y] + matrix_b[x][y];//�ݺ����� �̿��Ͽ� matrix_a[x][y]�� matrix_b[x][y]�� �����ְ� matrix_addition[x][y]�� ���� ����
		}
	}
	if(matrix_addition == NULL)
	{//matrix_addition�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
		printf("The worng value!");
		return -1;
	}


	print_matrix(matrix_addition, row, col);//matrix_addition�� row, col�� ���� �����Ͽ� matrix_addition�� ���
	free_matrix(matrix_addition, row, col);//matrix_addition�� row,col�� ���� �����Ͽ� matrix_addition�� ����

	return 0;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)//matrix_a�� matrix_b�� ������ �迭�� ��,���� ���� �޾� matrix_a�� matrix_b�� ���ִ� �Լ�
{
	/* check pre conditions */
	if(row <= 0 || col <=0)
	{//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
       printf("Check the sizes of row and col!\n");
	   return -1;
	}
	int** matrix_sub = create_matrix(row, col);//���� ������ matrix_addition�� create_matrix�Լ��� ���� ��ȯ�޾� ����(������ �迭 ����)
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			matrix_sub[x][y] = matrix_a[x][y] - matrix_b[x][y];//�ݺ����� �̿��Ͽ� matrix_a[x][y]�� matrix[x][y]�� ���ְ� matrix__sub[x][y]�� ���� ����
		}
	}
	if(matrix_sub == NULL)
	{//matrix_sub�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
	  printf("The worng value!\n");
	  return -1;
	}
	print_matrix(matrix_sub, row, col);//matrix_sub�� row, col�� ���� �����Ͽ� matrix_sub�� ���
	free_matrix(matrix_sub, row, col);//matrix_sub�� row, col�� ���� �����Ͽ� matrix_sub�� ���

	return 0;

}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)//matrix�� ���� ������ �迭�� ��ġ�Ͽ� matrix_t�� ���� �迭�� �������ִ� �Լ�
{
	if(row <= 0 || col <=0)
	{//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
	  printf("Check the sizes of row and col!\n");
	  return -1;
    }

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col;y++)
		{
			matrix_t[x][y] = matrix[y][x];//matrix[y][x]�� �ش��ϴ� ���� matrix_t[x][y]�� ����.(����� ��ġ = �� ������ ��� ���� ��ġ�� �ٲ�)
		}
	}

	if(matrix == NULL || matrix_t == NULL)
	{//matrix�� matrix_t�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
		printf("The worng value!\n");
		return -1;
	}


	return 0;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)//matrix_a�� ���� ��ġ�� �迭 matrix_t�� ���ϴ� �Լ�
{
	if(row <= 0 || col <=0)
	{//row �� col�� ���� 0���� �۴ٸ� ����� ��� �� -1�� ��ȯ
	  printf("Check the sizes of row and col!\n");
	  return -1;
	}
	int** matrix_multiple = create_matrix(row, row);//���� ������ matrix_multiple�� create_matrix�Լ��� ���� ��ȯ�޾� ����(������ �迭 ����)
	int x, y, i;//������ ���� x,y,i ����
	int tmp = 0;//������ ���� tmp�� ���� �� 0�� ����.

	for (x = 0; x < row; x++)
	{
		for (y = 0; y < row; y++)
		{
			tmp = 0;//tmp������ �ʱ�ȭ
			for (i = 0; i < col; i++)
			{
				tmp += matrix_a[x][i] * matrix_t[i][y];//matrix_a[x][i]�� �ش��ϴ� ���� matrix_t[i][y]�� ���� ���� �� �ݺ����� �̿��Ͽ� tmp�� �����ش�.
			}
			matrix_multiple[x][y] = tmp;//tmp�� ����� ���� matrix_multiple[x][y]�� ����

		}
	}
	if(matrix_a == NULL || matrix_t == NULL)
	{//matrix_a�� matrix_t�� ���� ������� �ʴٸ� ������� ��� �� -1�� ��ȯ
		printf("The wrong value!\n");
		return -1;
	}

	print_matrix(matrix_multiple, row, row);//matrix_multiple�� row, row�� print_matrix �Լ��� ����(����� ���),����� ���� ���ǿ� ���� row x row ����̵ǹǷ� col���� �ƴ� row���� ����
	free_matrix(matrix_multiple, row, row);//matrix_multiple�� row,row�� free_matrix�Լ��� �����Ͽ� ����� ����

	return 0;
}
