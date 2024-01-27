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
	m1 = m2 = m3 = -1; // 초기화 용도
	x2 = y2 = x3 = y3 = 0;
	float r2, r3;
	r2 = r3 = 0.0;

	struct circle ls[M];

	srand((unsigned)time(NULL));

	
	
	

	while (m < M)
	{
		if (m == 0)
		{
			nx = coord();		// x좌표 (1 ~ 1000000 인 정수)
			ny = coord();		// y좌표 (1 ~ 1000000 인 정수)
			nr = radius();		// 반지름 (0.05 ~ 100.00 인 실수)
			ls[0].x = nx;
			ls[0].y = ny;
			ls[0].r = nr;
			rmin = ls[0].r;
			m++;
		}
		start:
		
		nx = coord();		// x좌표 (1 ~ 1000000 인 정수)
		ny = coord();		// y좌표 (1 ~ 1000000 인 정수)
		nr = radius();		// 반지름 (0.05 ~ 100.00 인 실수)

		for (i = 0; i < m; i++)
		{
			if (nx == ls[i].x && ny == ls[i].y)			// 반지름의 좌표가 일치한다면...
			{
				goto start;	// 좌표가 일치하면 다른 원 생성
			}
		}
		
		//

			for (j = 0; j < m; j++)
			{
				if ((pow(((double)ls[j].x - (double)nx), 2.0) + pow(((double)ls[j].y - (double)ny), 2.0)) - (pow((ls[j].r + nr), 2.0)) <= 0)	// 원이 겹치면...
				{
					
					goto start;		// 원이 겹치면 다른 원 생성
				}
			distance = sqrt(pow(((double)ls[j].x - (double)nx), 2.0) + pow(((double)ls[j].y - (double)ny), 2.0)) - (ls[j].r + nr); // 새로 생성된 원과 기존 원들 사이의 거리 계산

				if (dmin > distance)
				{
					dmin = distance;	// 최소 거리 원 2개의 정보 출력용
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


			
			if (rmin > ls[m].r)		// 최소 반지름 출력용
			{
				rmin = ls[m].r;
				m1 = m;
			}
						

			m++;
		}
		
	
	printf("가장 작은 원 (위치, 반지름): %d, %f\n", m1, rmin);
	printf("가장 가까운 원 2개: %d and %d \n (%d,%d) 반지름 %f   (%d,%d) 반지름 %f 거리는 %f \n", m2, m3, x2, y2, r2, x3, y3, r3, dmin);
	
	return 0;
}

int coord()
{
	return  1 + ((rand() % 10000) * 100 + (rand() % 100));	// 좌표 (1 ~ 1000000 인 정수)  //  1 + 9999*100 + 99
}
float radius()
{
	return 0.05 + ((rand() % 9996) / 100.0);	// 반지름 (0.05 ~ 100.00 인 실수)   // 0.05 + 99.95
}

//testing for git commit / push