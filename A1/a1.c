#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define M 60000

struct circle
{
	int x;
	int y;
	double r;
};

int coord();
float radius();


int main()
{
	int i, j, nx, ny;
	int m = 0;
	double nr;
	float distance;
	float rmin; 
	float dmin = 1500000.0;

	int m1, m2, m3, x2, y2, x3, y3;
	m1 = m2 = m3 = -1; // �ʱ�ȭ �뵵
	x2 = y2 = x3 = y3 = 0;
	float r2, r3;
	r2 = r3 = 0.0;

	struct circle ls[M];

	srand((unsigned)time(NULL));

	
	
	

	while (m < M)
	{
		if (m == 0)
		{
			nx = coord();		// x��ǥ (1 ~ 1000000 �� ����)
			ny = coord();		// y��ǥ (1 ~ 1000000 �� ����)
			nr = radius();		// ������ (0.05 ~ 100.00 �� �Ǽ�)
			ls[0].x = nx;
			ls[0].y = ny;
			ls[0].r = nr;
			rmin = ls[0].r;
			m++;
		}
		start:
		
		nx = coord();		// x��ǥ (1 ~ 1000000 �� ����)
		ny = coord();		// y��ǥ (1 ~ 1000000 �� ����)
		nr = radius();		// ������ (0.05 ~ 100.00 �� �Ǽ�)

		for (i = 0; i < m; i++)
		{
			if (nx == ls[i].x && ny == ls[i].y)			// �������� ��ǥ�� ��ġ�Ѵٸ�...
			{
				goto start;	// ��ǥ�� ��ġ�ϸ� �ٸ� �� ����
			}
		}
		
		//

			for (j = 0; j < m; j++)
			{
				if ((pow(((double)ls[j].x - (double)nx), 2.0) + pow(((double)ls[j].y - (double)ny), 2.0)) - (pow((ls[j].r + nr), 2.0)) <= 0)	// ���� ��ġ��...
				{
					
					goto start;		// ���� ��ġ�� �ٸ� �� ����
				}
			distance = sqrt(pow(((double)ls[j].x - (double)nx), 2.0) + pow(((double)ls[j].y - (double)ny), 2.0)) - (ls[j].r + nr); // ���� ������ ���� ���� ���� ������ �Ÿ� ���

				if (dmin > distance)
				{
					dmin = distance;	// �ּ� �Ÿ� �� 2���� ���� ��¿�
					m2 = j;
					m3 = m;
					x2 = ls[j].x;
					y2 = ls[j].y;
					x3 = nx;
					y3 = ny;
					r2 = ls[j].r;
					r3 = nr;
				}
			}
			

			ls[m].x = nx;
			ls[m].y = ny;
			ls[m].r = nr;


			
			if (rmin > ls[m].r)		// �ּ� ������ ��¿�
			{
				rmin = ls[m].r;
				m1 = m;
			}
						

			m++;
		}
		
	
	printf("���� ���� �� (��ġ, ������): %d, %f\n", m1, rmin);
	printf("���� ����� �� 2��: %d and %d \n (%d,%d) ������ %f   (%d,%d) ������ %f �Ÿ��� %f \n", m2, m3, x2, y2, r2, x3, y3, r3, dmin);
	
	return 0;
}

int coord()
{
	return  1 + ((rand() % 10000) * 100 + (rand() % 100));	// ��ǥ (1 ~ 1000000 �� ����)  //  1 + 9999*100 + 99
}
float radius()
{
	return 0.05 + ((rand() % 9996) / 100.0);	// ������ (0.05 ~ 100.00 �� �Ǽ�)   // 0.05 + 99.95
}

//testing for git commit / push