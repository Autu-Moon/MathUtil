#include"MathUtil.h"

double R8decode(const char* buff){
	double r;
	memcpy(&r, buff, 8);
	return r;
}
double Deg2Rad(const double& deg)						//角度转弧度
{
	return(deg / 180.0*M_PI);
}
double Rad2Deg(const double& rad)						//弧度转角度
{
	return(rad / M_PI * 180.0);
}
Eigen::Quaterniond EulerToQuaerntion(const Eigen::Vector3d &euler)
{
	double              roll = euler(0);
	double              pitch = euler(1);
	double              yaw = euler(2);
	Eigen::Quaterniond  quaterniond(
		cos(roll / 2.)*cos(pitch / 2.)*cos(yaw / 2.) + sin(roll / 2.)*sin(pitch / 2.)*sin(yaw / 2.),
		sin(roll / 2.)*cos(pitch / 2.)*cos(yaw / 2.) - cos(roll / 2.)*sin(pitch / 2.)*sin(yaw / 2.),
		cos(roll / 2.)*sin(pitch / 2.)*cos(yaw / 2.) + sin(roll / 2.)*cos(pitch / 2.)*sin(yaw / 2.),
		cos(roll / 2.)*cos(pitch / 2.)*sin(yaw / 2.) - sin(roll / 2.)*sin(pitch / 2.)*cos(yaw / 2.));
	return  quaterniond;
}

Eigen::Matrix3d Vec3dToSSymmeticMatrix(const Eigen::Vector3d &v3d)
{
	Eigen::Matrix3d matrix3d = Eigen::Matrix3d::Zero();                 //矩阵初始化
	matrix3d << 0, -v3d[2], v3d[1],
		v3d[2], 0, -v3d[0],
		-v3d[1], v3d[0], 0;
	return matrix3d;
}

Eigen::Matrix3d	EulerToDCM(const Eigen::Vector3d& euler)
{
	double              roll = euler(0);
	double              pitch = euler(1);
	double              yaw = euler(2);
	Eigen::Matrix3d		Cb_n = Eigen::Matrix3d::Zero();
	Cb_n << cos(pitch)*cos(yaw), -cos(roll)*sin(yaw) + sin(roll)*sin(pitch)*cos(yaw), sin(roll)*sin(yaw) + cos(roll)*sin(pitch)*cos(yaw),
		cos(pitch)*sin(yaw), cos(roll)*cos(yaw) + sin(roll)*sin(pitch)*sin(yaw), -sin(roll)*cos(yaw) + cos(roll)*sin(pitch)*sin(yaw),
		-sin(pitch), sin(roll)*cos(pitch), cos(roll)*cos(pitch);
	return Cb_n;
}

Eigen::Vector3d DCMToEuler210(const Eigen::Matrix3d &DCM)
{
	double roll = atan2(DCM(2, 1), DCM(2, 2));
	double pitch = atan(-DCM(2, 0) / sqrt(DCM(2, 1)*DCM(2, 1) + DCM(2, 2)*DCM(2, 2)));
	double yaw = atan2(DCM(1, 0), DCM(0, 0));
	Eigen::Vector3d eulerAngle(roll, pitch, yaw);
	return eulerAngle;
}