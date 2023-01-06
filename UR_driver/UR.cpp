#include "pch.h"
#include "UR.h"
UR::UR()
{
	std::cout << "UR constructor" << std::endl;
	this->open();
}

UR::~UR()
{
	this->close();
}

void UR::open()
{
	ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&server, 0, sizeof(server));
	server.sin_port = htons(30003);
	server.sin_family = AF_INET;
	server.sin_addr.S_un.S_addr = inet_addr("192.168.0.20");
	ret = connect(sock, (struct sockaddr*)&server, sizeof(server));
	if (ret == SOCKET_ERROR)
	{
		std::cout << "can not connect robot" << std::endl;
		closesocket(sock);
		WSACleanup();
		ret = 1000;
	}
}

void UR::close()
{
	ret = closesocket(sock);
	if (ret != 0)
	{
		std::cout << "can not close socket" << std::endl;
	}
	ret = WSACleanup();
	if (ret != 0)
	{
		std::cout << "can not cleanup WSA" << std::endl;
	}
}

void UR::movel(double x, double y, double z, double a, double b, double c, double tt)
{
	std::ostringstream P[9];
	double Posi[9] = { 0.0 };
	Posi[0] = x;
	Posi[1] = y;
	Posi[2] = z;
	Posi[3] = a * this->degtorad;
	Posi[4] = b * this->degtorad;
	Posi[5] = c * this->degtorad;
	Posi[6] = 20.00;//加速度
	Posi[7] = 2.000;//速度
	Posi[8] = tt;
	for (int i = 0; i < 9; i++)
	{
		P[i] << Posi[i];
	}
	//UR(TB内)構文
	std::string seq[7];
	seq[0] = "def myProg(): \n";
	seq[1] = "m = [" + P[3].str() + "," + P[4].str() + "," + P[5].str() + "] \n";
	seq[2] = "RPY = rpy2rotvec(m) \n";
	seq[3] = "L = p[" + P[0].str() + "," + P[1].str() + "," + P[2].str() + "," + "RPY[0],RPY[1],RPY[2]" + "] \n";
	seq[4] = "movel(L,";
	seq[5] = "a=" + P[6].str() + "," + "v=" + P[7].str() + "," + "t=" + P[8].str() + ") \n";
	seq[6] = "end \n";
	std::string out;
	for (int i = 0; i < 7; i++)
	{
		out += seq[i];
	}
	std::cout << out << std::endl;
	while (1)
	{
		ret = send(sock, out.c_str(), (int)out.size(), 0);
		std::cout << ret << std::endl;
		if (ret != -1)
		{
			break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		P[i].str(""); // バッファをクリアする。
		P[i].clear(std::stringstream::goodbit);
	}
}

void UR::movej(double j1, double j2, double j3, double j4, double j5, double j6, double tt)
{
	std::ostringstream P[9];
	double Posi[9] = { 0.0 };
	Posi[0] = j1 * this->degtorad;
	Posi[1] = j2 * this->degtorad;
	Posi[2] = j3 * this->degtorad;
	Posi[3] = j4 * this->degtorad;
	Posi[4] = j5 * this->degtorad;
	Posi[5] = j6 * this->degtorad;
	Posi[6] = 1.4;//加速度
	Posi[7] = 1.05;//速度
	Posi[8] = tt;
	for (int i = 0; i < 9; i++)
	{
		P[i] << Posi[i];
	}
	//UR(TB内)構文
	std::string seq[7];
	seq[0] = "def myProg(): \n";
	seq[1] = "movej([" + P[0].str() + "," + P[1].str() + "," + P[2].str() + "," + P[3].str() + "," + P[4].str() + "," + P[5].str() + "],";
	seq[2] = "a=" + P[6].str() + "," + "v=" + P[7].str() + "," + "t=" + P[8].str() + ") \n";
	seq[3] = "end \n";
	std::string out;
	for (int i = 0; i < 4; i++)
	{
		out += seq[i];
	}
	std::cout << out << std::endl;
	while (1)
	{
		ret = send(sock, out.c_str(), (int)out.size(), 0);
		std::cout << ret << std::endl;
		if (ret != -1)
		{
			break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		P[i].str(""); // バッファをクリアする。
		P[i].clear(std::stringstream::goodbit);
	}
}

void UR::movel_add(double x, double y, double z, double a, double b, double c, double tt)
{
	std::ostringstream P[12];
	double Posi[12] = { 0.0 };
	Posi[0] = x + da.pose.x;
	Posi[1] = y + da.pose.y;
	Posi[2] = z + da.pose.z;
	Posi[3] = a * this->degtorad;
	Posi[4] = b * this->degtorad;
	Posi[5] = c * this->degtorad;
	Posi[6] = 1.40;//加速度
	Posi[7] = 1.04;//速度
	Posi[8] = tt;
	Posi[9] = da.pose.a;
	Posi[10] = da.pose.b;
	Posi[11] = da.pose.c;
	for (int i = 0; i < 12; i++)
	{
		P[i] << Posi[i];
	}
	//UR(TB内)構文
	std::string seq[9];
	seq[0] = "def myProg(): \n";
	seq[1] = "nq = [" + P[9].str() + "," + P[10].str() + "," + P[11].str() + "] \n";
	seq[2] = "BPY = rotvec2rpy(nq) \n";
	seq[3] = "m = [ BPY[0] +" + P[3].str() + "," + "BPY[1] + " + P[4].str() + ", " + "BPY[2] + " + P[5].str() + "] \n";
	seq[4] = "RPY = rpy2rotvec(m) \n";
	seq[5] = "L = p[" + P[0].str() + "," + P[1].str() + "," + P[2].str() + "," + "RPY[0],RPY[1],RPY[2]" + "] \n";
	seq[6] = "movel(L,";
	seq[7] = "a=" + P[6].str() + "," + "v=" + P[7].str() + "," + "t=" + P[8].str() + ") \n";
	seq[8] = "end \n";
	std::string out;
	for (int i = 0; i < 9; i++)
	{
		out += seq[i];
	}
	std::cout << out << std::endl;
	while (1)
	{
		ret = send(sock, out.c_str(), (int)out.size(), 0);
		std::cout << ret << std::endl;
		if (ret != -1)
		{
			break;
		}
	}
	for (int i = 0; i < 12; i++)
	{
		P[i].str(""); // バッファをクリアする。
		P[i].clear(std::stringstream::goodbit);
	}
}

void UR::read()
{
	int retry = 1;
	while (retry)
	{
		// ソケットを登録
		FD_ZERO(&readfds);
		FD_SET(sock, &readfds);
		sTimeOut.tv_sec = 2;
		status = select(0, &readfds, (fd_set*)NULL, (fd_set*)NULL, &sTimeOut);
		if (status == SOCKET_ERROR)
		{
			std::cout << "ソケットエラーretry" << std::endl;
		}
		if ((status > 0) && (FD_ISSET(sock, &readfds) != 0))
		{
			numrcv = recvfrom(sock, revTxt1, sizeof(revTxt1), 0, NULL, NULL);
			if (numrcv == SOCKET_ERROR)
			{
				std::cerr << "ERROR: recvfrom unsuccessful" << std::endl;
				status = closesocket(sock);
				if (this->status == SOCKET_ERROR)
					std::cerr << "ERROR: closesocket unsuccessful" << std::endl;
				status = WSACleanup();
				if (status == SOCKET_ERROR)
					std::cerr << "ERROR: WSACleanup unsuccessful" << std::endl;
			}
			for (int i = 0; i < 1108; i++) //unsigned への変換
			{
				revTxt2[i] = revTxt1[i];
			}
			for (int i = 0; i < 1104; i++) //文字列の逆転とintの排除
			{
				revTxt3[i] = revTxt2[1107 - i];
			}
			memset(&da, 0, sizeof(UR_COM)); //構造体の初期化
			memcpy(&da, revTxt3, sizeof(UR_COM));
			// 受信ループを抜ける
			retry = 0;
		}
		else
		{
			// 受信タイムアウト
			std::cout << "... Receive Timeout! <Push [Enter] to stop the program>" << std::endl;
		}
	}
}


