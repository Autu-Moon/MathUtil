#pragma once
#include<iostream>
#include<Eigen/Dense>
const double Omega_e = 7.292115e-5;						//unit: rad/s
const double M_PI = 3.141592653589793;					//圆周率

double Deg2Rad(const double& deg);						//角度转弧度

double Rad2Deg(const double& rad);						//弧度转角度

double R8decode(const char* buff);

//姿态转换工具函数
Eigen::Quaterniond                  EulerToQuaerntion(const  Eigen::Vector3d& euler);				//欧拉角转四元数
Eigen::Matrix3d                     Vec3dToSSymmeticMatrix(const  Eigen::Vector3d& v3d);			//三维向量转反对称矩阵
Eigen::Matrix3d						EulerToDCM(const  Eigen::Vector3d& euler);						//欧拉角转DCM
Eigen::Vector3d						DCMToEuler210(const  Eigen::Matrix3d& DCM);						//DCM转欧拉角	