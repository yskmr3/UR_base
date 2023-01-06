#pragma once

typedef struct
{
	double elv3;//138
	double elv2;//137
	double elv1;//136
} ELV;	  //Elbow velocity

typedef struct
{
	double elp3;//135
	double elp2;//134
	double elp1;//133
} ELP;	  //Elbow position

typedef struct
{
	double prst;//132
} PRST;	  //Program state

typedef struct
{
	double diot;//131
} DIOT;	  //Digital outputs

typedef struct
{
	double volac6;//130
	double volac5;//129
	double volac4;//128
	double volac3;//127
	double volac2;//125
	double volac1;//125
} VOLAC;	  //Actual joint voltages

typedef struct
{
	double allcur;//124
} ALLCUR;	  //Masterboard: Robot current

typedef struct
{
	double allvol;//123
} ALLVOL;	  //Masterboard: Robot voltage (48V)

typedef struct
{
	double volmain;//122
} VOLMAIN;  //Masterboard: Main voltage

typedef struct
{
	double uronly1_2;//121
	double uronly1_1;//120
} URONLY;	  //Used by Universal Robots software only

typedef struct
{
	double nclm;//119
} NCLM;	  //Norm of Cartesian linear momentum

typedef struct
{
	double sstl;//118
} SSTL;	  //Speed scaling of the trajectory limiter

typedef struct
{
	double uronly2_6;//117
	double uronly2_5;//116
	double uronly2_4;//115
	double uronly2_3;//114
	double uronly2_2;//113
	double uronly2_1;//112
} URONLY2;  //Used by Universal Robots software only

typedef struct
{
	double z_ac;//111
	double y_ac;//110
	double x_ac;//109
} TOOLAC;	  //Tool x,y and z accelerometer values (software version 1.7)

typedef struct
{
	double uronly3_6;//108
	double uronly3_5;//107
	double uronly3_4;//106
	double uronly3_3;//105
	double uronly3_2;//104
	double uronly3_1;//103
} URONLY3;  //Used by Universal Robots software only

typedef struct
{
	double safmode;//102
} SAFMODE;  //Safety mode

typedef struct
{
	double jntmode6;//101
	double jntmode5;//100
	double jntmode4;//99
	double jntmode3;//98
	double jntmode2;//97
	double jntmode1;//96
} JNTMODE;  //Safety mode

typedef struct
{
	double robomode;//95
} ROBOMODE; //Robot mode

typedef struct
{
	double testval;//94
} TESTVAL;  //A value used by Universal Robots software only

typedef struct
{
	double cltime;//93
} CLTIME;	  //Controller realtime thread execution time
	
typedef struct
{
	double m_temp6;//92
	double m_temp5;//91
	double m_temp4;//90
	double m_temp3;//89
	double m_temp2;//88
	double m_temp1;//87
} M_TEMP;	  //Temperature of each joint in degrees celsius

typedef struct
{
	double dis;//86
} DIS;	  //Current state of the digital inputs. NOTE: these are bits encoded as int64_t, e.g. a value of 5 corresponds to bit 0 and bit 2 set high

typedef struct
{
	double c_tcpst;//85
	double b_tcpst;//84
	double a_tcpst;//83
	double z_tcpst;//82
	double y_tcpst;//81
	double x_tcpst;//80
} TCPST;	  //Target speed of the tool given in Cartesian coordinates

typedef struct
{
	double c_t;//79
	double b_t;//78
	double a_t;//77
	double z_t;//76
	double y_t;//75
	double x_t;//74
} POSE_T;	  //Target speed of the tool given in Cartesian coordinates

typedef struct
{
	double c_f;//73
	double b_f;//72
	double a_f;//71
	double z_f;//70
	double y_f;//69
	double x_f;//68
} FORCE;	  //Generalised forces in the TCP

typedef struct
{
	double c_v;//67
	double b_v;//66
	double a_v;//65
	double z_v;//64
	double y_v;//63
	double x_v;//62
} POSE_V;	  //Actual speed of the tool given in Cartesian coordinates

typedef struct
{
	double c;//61
	double b;//60
	double a;//59
	double z;//58
	double y;//57
	double x;//56
} POSE;	  //Actual Cartesian coordinates of the tool: (x,y,z,rx,ry,rz), where rx, ry and rz is a rotation vector representation of the tool orientation

typedef struct
{
	double cur6_con;//55
	double cur5_con;//54
	double cur4_con;//53
	double cur3_con;//52
	double cur2_con;//51
	double cur1_con;//50
} CURRENT_CON;  //Joint control currents

typedef struct
{
	double cur6;//49
	double cur5;//48
	double cur4;//47
	double cur3;//46
	double cur2;//45
	double cur1;//44
} CURRENT;	  //Actual joint currents  

typedef struct
{
	double j6;//43
	double j5;//42
	double j4;//41
	double j3;//40
	double j2;//39
	double j1;//38
} JOINT_V;	  //Actual joint velocities

typedef struct
{
	double j6;//37
	double j5;//36
	double j4;//35
	double j3;//34
	double j2;//33
	double j1;//32
} JOINT;		  //Actual joint positions

typedef struct
{
	double tor6_t;//31
	double tor5_t;//30
	double tor4_t;//29
	double tor3_t;//28
	double tor2_t;//27
	double tor1_t;//26
} TOR_T;		  //Target joint moments (torques)

typedef struct
{
	double cur6;//25
	double cur5;//24
	double cur4;//23
	double cur3;//22
	double cur2;//21
	double cur1;//20
} CURRENT_T;	  //Target joint currents

typedef struct
{
	double j6_at;//19
	double j5_at;//18
	double j4_at;//17
	double j3_at;//16
	double j2_at;//15
	double j1_at;//14
} JOINT_A_T;	  //Target joint accelerations

typedef struct
{
	double j6_vt;//13
	double j5_vt;//12
	double j4_vt;//11
	double j3_vt;//10
	double j2_vt;//9
	double j1_vt;//8
} JOINT_V_T;	  //Target joint velocities

typedef struct
{
	double j6_t;//7
	double j5_t;//6
	double j4_t;//5
	double j3_t;//4
	double j2_t;//3
	double j1_t;//2
} JOINT_T;	  //Target joint positions

typedef struct
{
	double time;//1
} TIME;		  //Time elapsed since the controller was started

typedef struct 
{
	int mess1;
} MESSAGE;	  //Total message length in bytes

typedef struct 
{
	ELV elv;
	ELP elp;
	PRST prst;
	DIOT diot;
	VOLAC volac;
	ALLCUR allcur;
	ALLVOL allcol;
	VOLMAIN volmain;
	URONLY uronly;
	NCLM nclm;
	SSTL sstl;
	URONLY2 uronly2;
	TOOLAC toolac;
	URONLY3 uronly3;
	SAFMODE safmode;
	JNTMODE jntmode;
	ROBOMODE robomode;
	TESTVAL testval;
	CLTIME cltime;
	M_TEMP m_temp;
	DIS dis;
	TCPST tcpst;
	POSE_T pose_t;
	FORCE force;
	POSE_V pose_v;
	POSE pose;
	CURRENT_CON current_con;
	CURRENT current;
	JOINT_V jnt_v;
	JOINT jnt;
	TOR_T tor_t;
	CURRENT_T current_t;
	JOINT_A_T jnt_a_t;
	JOINT_V_T jnt_v_t;
	JOINT_T jnt_t;
	TIME tim;
	//MESSAGE mess;
}UR_COM;












