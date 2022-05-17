#include<iostream>
#include <conio.h>
#include<windows.h>

using namespace std;

class GameData
{
public:
	int x;
	int y;
	int xIndex;
	int yIndex;
};

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







void SetLocation(int xPlayerLocation, int yPlayerLocation);
void MovePlayer(GameData& PlayerLocation, int AddX, int AddY);
void Draw(GameData& PlayerLocation, int MapLocationX, int MapLocationY);

//�÷��̾ ��ġ�� �迭 �ε��� ���� ����
//int xIndex;
//int yIndex;




int main()
{


	bool bRunning = true;
	GameData Player;
	Player.x = 0;
	Player.y = 0;
	Player.xIndex = 0;
	Player.yIndex = 0;
	//�÷��̾� ��ǥ ���� ����
	/*int x, y;*/


	//�� ���� ��ġ ����
	int MapLacationX, MapLacationY;
	srand(static_cast<unsigned int>(time(nullptr)));
	MapLacationX = rand() % 8 + 1;
	MapLacationY = rand() % 8 + 1;




	//�� ��� �� �÷��̾� �ּҰ� �ѱ�. 
	
	Draw(Player, MapLacationX, MapLacationY);

	SetLocation(Player.x , Player.y);



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
			MovePlayer(Player, 0, -1);
			break;
		case's':
		case'S':
			MovePlayer(Player, 0, 1);
			break;
		case'd':
		case'D':
			MovePlayer(Player, 1, 0);
			break;
		case'a':
		case'A':
			MovePlayer(Player, -1, 0);
			break;
		case 27:
			bRunning = false;
			system("cls");
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
void SetLocation(int xPlayerLocation, int yPlayerLocation)
{
	COORD pos = { xPlayerLocation ,yPlayerLocation };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void MovePlayer(GameData& PlayerLocation, int AddX, int AddY)
{

	char TempMap = Map[PlayerLocation.yIndex + AddY][PlayerLocation.xIndex + AddX];
	if (TempMap == '1')
	{
		//�÷��̾� ���� ��ġ�� ���� �������(�÷��̾� �����)
		SetLocation(PlayerLocation.x, PlayerLocation.y);
		cout << ' ';

		//�̵�����ġ�� �÷��̾� ���

		SetLocation(PlayerLocation.x + AddX, PlayerLocation.y + AddY);
		cout << 'P';


		//�̵��� ��ġ ��ǥ���� ���� ��ġ�� ����
		PlayerLocation.x += AddX;
		PlayerLocation.y += AddY;

		PlayerLocation.yIndex += AddY;
		PlayerLocation.xIndex += AddX;

	}

}

void Draw(GameData &PlayerLocation, int MapLocationX, int MapLocationY)
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
				TempX = X + MapLocationX;
				TempY = Y + MapLocationY;
				SetLocation(TempX, TempY);
				cout << '#';
			}
			else if (Temp == '1')
			{
				TempX = X + MapLocationX;
				TempY = Y + MapLocationY;
				SetLocation(TempX, TempY);
				cout << ' ';
			}
			else if (Temp == '2')
			{
				TempX = X + MapLocationX;
				TempY = Y + MapLocationY;
				SetLocation(TempX, TempY);

				//�ε��� �� ����
				PlayerLocation.xIndex = X;
				PlayerLocation.yIndex = Y;


				//������ �� ��ġ��ŭ �÷��̾� ��ġ�� ����
				PlayerLocation.x = X + MapLocationX;
				PlayerLocation.y = Y + MapLocationY;
				


				cout << 'P';
			}



		}

		cout << endl;
	}

}