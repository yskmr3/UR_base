#pragma once
class UR
{
//„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª
//		•Ï”
//„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª
public:
	UR_COM da;


private:
	WSADATA wsaData;
	sockaddr_in server;
	unsigned long destAddr;
	SOCKET sock;
	double VPosi[9] = { 0.0 };
	double BPosi[8] = { 0.0 };
	int ret;
	int ret2;
	int count = 0;
	char sendTxt[512] = {};
	char revTxt1[110800] = {};
	unsigned char revTxt2[1108] = {};
	unsigned char revTxt3[1104] = {};
	fd_set fds, readfds;
	timeval sTimeOut;
	int status;
	int numrcv;
	double radtodeg = 180 / 3.14;
	double degtorad = 3.14 / 180;
	int ct = 0;
//„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª
//		ŠÖ”
//„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª
public:
	UR();
	~UR();
	void movel(double x, double y, double z, double a, double b, double c, double tt);
	void movej(double j1, double j2, double j3, double j4, double j5, double j6, double tt);
	void movel_add(double x, double y, double z, double a, double b, double c, double tt);
	void read();

private:
	void open();
	void close();











};

