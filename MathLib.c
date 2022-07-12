#include "MathLib.h"

double getDinstance(const circle circle1, const circle circle2) {
	return sqrt(pow(circle1.pointX - circle2.pointX, 2) + pow(circle1.pointY - circle2.pointY, 2));
}

double getSquareOfCircle(const circle crcl) {
	return M_PI * pow(crcl.radius, 2);
}

double getCosOfAngle(const double a, const double b, const double c) {
	return (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);
}

double getSector(const double radius, const double angle) {
	return (M_PI * pow(radius, 2) * angle) / 360;
}

double getSquareOfTriangle(const double a, const double b, const double c) {
	const double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double getLegViaSin(const double hypotenuse, const double angleRad) {
	return fabs(hypotenuse * sin(angleRad));
}

double convertRadToDeg(const double rad) {
	return rad * 180 / M_PI;
}

double getLegViaCos(const double hypotenuse, const double angleRad) {
	return fabs(hypotenuse * cos(angleRad));
}
