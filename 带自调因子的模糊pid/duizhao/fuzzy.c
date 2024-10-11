#include "fuzzy.h"
double fuzzy_pid(double Ma, double e, double e1, double  N, double  a, double  b, double  k2, double  ku, double  as, double  ao,double kp,double ki)
{
	static  double y = 0,ed=0,E=0,E1=0,EC=0,EC1=0,a1=0,y1=0,y2=0,error_interl=0;
ed = e - e1;
E = -(2 * N) * (e * k2 - (a + b)) / (b - a);
E1 = E;
EC = -(2 * N) * (ed - (a + b)) / (b - a);
EC1 = 270 * EC;
a1 = (1.0 / N) * (as - ao) * fabs(E1) + ao;
y1 = (-(a1 * E1 + (1 - a1) * EC1) / 2);
y2 = y1 * ku;
y = y2 * Ma;

//if (fabs(e) <= 0.05)
//{
//	error_interl += e;
//	y = kp * e + ki * error_interl;
//	y = y * Ma;
//}
return y;
}

double weizhi_pid(double Ma,double error,double kp, double ki)
{
	static  double error_interl = 0, y=0;
	error_interl += error;
	y = kp * error + ki * error_interl;
	y = y * Ma;
	return y;
}


double zengliang_pid(double Ma, double error, double kp, double ki)
{
	static  double last_error = 0, y = 0;
	
	y += (kp * error + ki *( error- last_error)) * Ma;
	last_error = error;
	return y;
}