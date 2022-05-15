#include<iostream>
#include <conio.h>
#include<windows.h>

using namespace std;

//�� �׸���
char Map[10][10]{
	{'0','0','0','0','0','0','0','0','0','0'},
	{'0','1','1','1','1','1','1','1','1','0'},
	{'0','1','2','1','1','1','1','1','1','0'},
	{'0','1','1','1','1','1','0','1','1','0'},
	{'0','1','1','1','1','1','1','1','1','0'},
	{'0','1','1','0','1','1','1','1','1','0'},
	{'0','1','1','1','1','1','1','1','1','0'},
	{'0','1','1','1','1','1','1','1','1','0'},
	{'0','1','1','1','1','1','1','1','1','0'},
	{'0','0','0','0','0','0','0','0','0','0'},
};







void SetLocation(int x, int y);
void MovePlayer(int* PlayerX, int* PlayerY, int AddX, int AddY);
void Draw(int* x, int* y, int MapLacationX, int MapLacationY);

//�÷��̾ ��ġ�� �迭 �ε��� ���� ����
int xIndex;
int yIndex;




int main()
{


	bool bRunning = true;

	//�÷��̾� ��ǥ ���� ����
	int x, y;


	//�� ���� ��ġ ����
	int MapLacationX, MapLacationY;
	srand(static_cast<unsigned int>(time(nullptr)));
	MapLacationX = rand() % 8 + 1;
	MapLacationY = rand() % 8 + 1;




	//�� ��� �� �÷��̾� �ּҰ� �ѱ�. 
	Draw(&x, &y, MapLacationX, MapLacationY);


	SetLocation(x, y);



	//����
	while (bRunning)
	{

		//Ű�Է¹ޱ� (_getch = �Է¹��ڸ��� �ƽ�Ű�ڵ带 ��ù�ȯ ==enterŰ ���� �ٷ� ��µ�)

		int Key = _getch();

		//���� Ű�� ���� �̵����� ����

		switch (Key)
		{
		case'w':
		case'W':
			MovePlayer(&x, &y, 0, -1);
			break;
		case's':
		case'S':
			MovePlayer(&x, &y, 0, 1);
			break;
		case'd':
		case'D':
			MovePlayer(&x, &y, 1, 0);
			break;
		case'a':
		case'A':
			MovePlayer(&x, &y, -1, 0);
			break;
		case 27:
			bRunning = false;
			break;

		}


	}




	return 0;
}

//Ŀ�� �����
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//�÷��̾� ��ġ(������ ��ǥ���� ��������)
void SetLocation(int x, int y)
{
	COORD pos = { x , y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void MovePlayer(int* PlayerX, int* PlayerY, int AddX, int AddY)
{

	char TempMap = Map[yIndex + AddY][xIndex + AddX];
	if (TempMap == '1')
	{
		//�÷��̾� ���� ��ġ�� ���� �������(�÷��̾� �����)
		SetLocation(*PlayerX, *PlayerY);
		cout << ' ';

		//�̵�����ġ�� �÷��̾� ���

		SetLocation(*PlayerX + AddX, *PlayerY + AddY);
		cout << 'P';


		//�̵��� ��ġ ��ǥ���� ���� ��ġ�� ����
		*PlayerX += AddX;
		*PlayerY += AddY;

		yIndex += AddY;
		xIndex += AddX;

	}

}

void Draw(int* x, int* y, int MapLacationX, int MapLacationY)
{



	//���̵��� �󸶳� �ߴ��� ���� �̸� ����. ���Ŀ� ���� ���ϱ⶧��
	//int xTemp = MapLacationX;
	//int yTemp = MapLacationY;

	int TempX, TempY;


	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			char Temp = Map[Y][X];

			if (Temp == '0')
			{
				TempX = X + MapLacationX;
				TempY = Y + MapLacationY;
				SetLocation(TempX, TempY);
				cout << '#';
			}
			else if (Temp == '1')
			{
				TempX = X + MapLacationX;
				TempY = Y + MapLacationY;
				SetLocation(TempX, TempY);
				cout << ' ';
			}
			else if (Temp == '2')
			{
				TempX = X + MapLacationX;
				TempY = Y + MapLacationY;
				SetLocation(TempX, TempY);

				//�ε��� �� ����
				xIndex = X;
				yIndex = Y;


				//������ �� ��ġ��ŭ �÷��̾� ��ġ�� ����
				*x = X + MapLacationX;
				*y = Y + MapLacationY;
				


				cout << 'P';
			}



		}

		cout << endl;
	}

}