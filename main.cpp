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

//맵 그리기
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

//플레이어가 위치한 배열 인덱스 저장 변수
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
	//플레이어 좌표 저장 변수
	/*int x, y;*/


	//맵 시작 위치 랜덤
	int MapLacationX, MapLacationY;
	srand(static_cast<unsigned int>(time(nullptr)));
	MapLacationX = rand() % 8 + 1;
	MapLacationY = rand() % 8 + 1;




	//맵 출력 및 플레이어 주소값 넘김. 
	
	Draw(Player, MapLacationX, MapLacationY);

	SetLocation(Player.x , Player.y);



	//루프
	while (bRunning)
	{

		//키입력받기 (_getch = 입력받자마자 아스키코드를 즉시반환 ==enter키 없이 바로 출력됨)

		int Key = _getch();

		//받은 키로 어디로 이동할지 구현

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

//커서 숨기기
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//플레이어 위치(지정된 좌표값을 수정해줌)
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
		//플레이어 현재 위치로 가서 공백출력(플레이어 지우기)
		SetLocation(PlayerLocation.x, PlayerLocation.y);
		cout << ' ';

		//이동한위치로 플레이어 출력

		SetLocation(PlayerLocation.x + AddX, PlayerLocation.y + AddY);
		cout << 'P';


		//이동한 위치 좌표값을 현재 위치로 적용
		PlayerLocation.x += AddX;
		PlayerLocation.y += AddY;

		PlayerLocation.yIndex += AddY;
		PlayerLocation.xIndex += AddX;

	}

}

void Draw(GameData &PlayerLocation, int MapLocationX, int MapLocationY)
{



	//맵이동을 얼마나 했는지 값을 미리 저장. 이후에 값이 변하기때문
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

				//인덱스 값 저장
				PlayerLocation.xIndex = X;
				PlayerLocation.yIndex = Y;


				//변경한 맵 위치만큼 플레이어 위치값 변경
				PlayerLocation.x = X + MapLocationX;
				PlayerLocation.y = Y + MapLocationY;
				


				cout << 'P';
			}



		}

		cout << endl;
	}

}