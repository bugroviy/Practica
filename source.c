#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MathLib.h"

int main() {
	circle circle1, circle2;

	printf("Enter first circle (pointX pointY radius): ");
	scanf_s("%lf %lf %lf", &circle1.pointX, &circle1.pointY, &circle1.radius);
	printf("First circle is (x - %lf)^2 + (y - %lf)^2 = %lf\nSquare: %lf\n\n", 
		circle1.pointX, circle1.pointY, pow(circle1.radius, 2.0), getSquareOfCircle(circle1));

	printf("Enter second circle (pointX pointY radius): ");
	scanf_s("%lf %lf %lf", &circle2.pointX, &circle2.pointY, &circle2.radius);
	printf("First circle is (x - %lf)^2 + (y - %lf)^2 = %lf\nSquare: %lf\n\n\n", 
		circle2.pointX, circle2.pointY, pow(circle2.radius, 2.0), getSquareOfCircle(circle2));

	//incorrect input values
	if (circle1.radius <= 0 || circle2.radius <= 0) {
		printf("Square of Intersection of circles: 0");
		return 0;
	}

	//get distance between centres of circles
	const double distBeetwCentr = getDinstance(circle1, circle2);

	//if the centres of circles are in the same point
	if (distBeetwCentr == 0.0) {
		if (circle1.radius >= circle2.radius)
			printf("\n\nSquare of Intersection of circles: %lf\n", getSquareOfCircle(circle2));
		else
			printf("\n\nSquare of Intersection of circles: %lf\n", getSquareOfCircle(circle1));
		return 0;
	}
	
	//if circles haven't a common intersection
	else if (distBeetwCentr >= circle1.radius + circle2.radius) {
		printf("Square of Intersection of circles: 0");
		return 0;
	}

	//if circle2 is located in circle1
	else if (circle1.radius >= distBeetwCentr + circle2.radius) {
		printf("\n\nSquare of Intersection of circles: %lf\n", getSquareOfCircle(circle2));
		return 0;
	}

	//if circle1 is located in circle2
	else if (circle2.radius >= distBeetwCentr + circle1.radius) {
		printf("\n\nSquare of Intersection of circles: %lf\n", getSquareOfCircle(circle1));
		return 0;
	}

	const double halfOfAngleOfCircle1_inRad = acos(getCosOfAngle(circle2.radius, circle1.radius, distBeetwCentr));
	const double distBetwCentr1AndHord = getLegViaCos(circle1.radius, halfOfAngleOfCircle1_inRad);	
	
	const double halfOfAngleOfCircle2_inRad = acos(getCosOfAngle(circle1.radius, circle2.radius, distBeetwCentr));
	const double distBetwCentr2AndHord = getLegViaCos(circle2.radius, halfOfAngleOfCircle2_inRad);

	const double angleOfCrcl1_inDeg = 2 * convertRadToDeg(halfOfAngleOfCircle1_inRad);
	const double chord = 2 * getLegViaSin(circle1.radius, halfOfAngleOfCircle1_inRad);
	const double segmentOfCrcl1 = getSector(circle1.radius, angleOfCrcl1_inDeg) - getSquareOfTriangle(circle1.radius, circle1.radius, chord);

	const double angleOfCrcl2_inDeg = 2 * convertRadToDeg(halfOfAngleOfCircle2_inRad);
	const double segmentOfCrcl2 = getSector(circle2.radius, angleOfCrcl2_inDeg) - getSquareOfTriangle(circle2.radius, circle2.radius, chord);

	
	if (distBetwCentr1AndHord + distBetwCentr2AndHord == distBeetwCentr && distBetwCentr1AndHord != 0 && distBetwCentr2AndHord != 0)
		printf("\n\nSquare of Intersection of circles: %lf\n", segmentOfCrcl1 + segmentOfCrcl2);
	
	else 
		if (circle1.radius > circle2.radius)
			printf("\n\nSquare of Intersection of circles: %lf\n", getSquareOfCircle(circle2) - segmentOfCrcl2 + segmentOfCrcl1);
		else
			printf("\n\nSquare of Intersection of circles: %lf\n", getSquareOfCircle(circle1) - segmentOfCrcl1 + segmentOfCrcl2);
	
	return 0;
}
