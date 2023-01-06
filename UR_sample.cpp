#include "pch.h"
#include "UR.h"
#include "img.h"
#include "Ch_timer.h"

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
//class
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
UR ur;
Ch_timer tm;
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
//変数
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
int flg_u = 99;
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
//スレッド
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
void Robot_control()
{
	while (1)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case '1'://x+
				ur.movel_add(0.10, 0, 0, 0, 0, 0, 1);
				break;
			case 'q'://x-
				ur.movel_add(-0.10, 0, 0, 0, 0, 0, 1);
				break;
			case '2'://y+
				ur.movel_add(0, 0.10, 0, 0, 0, 0, 1);
				break;
			case 'w'://y-
				ur.movel_add(0, -0.10, 0, 0, 0, 0, 1);
				break;
			case '3'://z+
				ur.movel_add(0, 0, 0.10, 0, 0, 0, 1);
				break;
			case 'e'://z-
				ur.movel_add(0, 0, -0.10, 0, 0, 0, 1);
				break;
			case '4'://a+
				ur.movel_add(0, 0, 0, 10, 0, 0, 1);
				break;
			case 'r'://a-
				ur.movel_add(0, 0, 0, -10, 0, 0, 1);
				break;
			case '5'://b+
				ur.movel_add(0, 0, 0, 0, 10, 0, 1);
				break;
			case 't'://b-
				ur.movel_add(0, 0, 0, 0, -10, 0, 1);
				break;
			case '6'://c+
				ur.movel_add(0, 0, 0, 0, 0, 10, 1);
				break;
			case 'y'://c-
				ur.movel_add(0, 0, 0, 0, 0, -10, 1);
				break;
			case 'a'://動作1
				flg_u = 1;
				break;
			case 'b'://動作2
				flg_u = 2;
				break;
			case 'c'://動作3
				flg_u = 3;
				break;
			case 'd'://動作4
				flg_u = 4;
				break;
			case 'p':// 終了
				flg_u = 10;
				break;
			default:
				break;
			}
		}
		ur.read();
		if (flg_u == 1)
		{
			ur.movel(0.132, -0.352, 0.30, 0, 180, 0, 10);
			flg_u = 99;
		}
		if (flg_u == 2)
		{
			ur.movel(0.132, -0.352, 0.20, 0, 180, 0, 10);
			flg_u = 99;
		}
		if (flg_u == 3)
		{
			ur.movel(0.232, -0.352, 0.20, 0, 180, 0, 10);
			flg_u = 99;
		}
		if (flg_u == 4)
		{
			ur.movel(0.132, -0.252, 0.30, 0, 180, 0, 10);
			flg_u = 99;
		}
		if (flg_u == 10)
		{
			break;
		}
		std::cout << flg_u << "\t" << ur.da.pose.x << std::endl;
	}
}
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

int main()
{
	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	//	設定
	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	std::cout << "press Enter" << std::endl;
	getchar();
	std::cout << "Start" << std::endl;
	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	//	スレッド
	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	std::thread th_Ur(Robot_control);
	th_Ur.join();
	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	//	終了
	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	std::cout << "End" << std::endl;
	return 0;
	//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━   

}

