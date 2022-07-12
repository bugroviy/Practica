#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

struct Circle
{
	double pointX;
	double pointY;
	double radius;
};

typedef struct Circle circle;

//отримати відстань між центрами кіл (коло 1, коло 2)
double getDinstance(const circle c1, const circle c2);

//отримати площу кола (коло)
double getSquareOfCircle(const circle c);

//отримати косинус кута трикутника (протилежна сторона, довільна сторона 1, довільна сторона 2)
double getCosOfAngle(const double a, const double b, const double c);

//отримати площу сектора (радіус кола, кут в градусах)
double getSector(const double radius, const double angle);

//отримати площу трикутника (довільна сторона 1, довільна сторона 2, довільна сторона 3)
double getSquareOfTriangle(const double a, const double b, const double c);

//отримати катет прямокутного трикутника через сінус (гіпотенуза, значення протилежного кута в радіанах)
double getLegViaSin(const double hypotenuse, const double angleRad);

//конвертувати радіани в градуси (значення кута в радіанах)
double convertRadToDeg(const double rad);

//отримати катет прямокутного трикутника через косинус (гіпотенуза, значення прилеглого кута в радіанах)
double getLegViaCos(const double hypotenuse, const double angleRad);
