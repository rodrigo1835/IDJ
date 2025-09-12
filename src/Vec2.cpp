#include "Vec2.h"
#include <math.h>

Vec2::Vec2() {
	x = 0;
	y = 0;
}


void Vec2::somar(Vec2 v1) {
	x += v1.x;
	y += v1.y;
}

void Vec2::subtrair(Vec2 v1) {
	x -= v1.x;
	y -= v1.y;
}

void Vec2::multiplicacao(float k) {
	x *= k;
	y *= k;
}

float Vec2::magnitude() {
	return sqrt(pow(x,2) + pow(y,2));
}

void Vec2::normalizar() {
	float m = magnitude();
	x /= m;
	y /= m;
}

float Vec2::distancia(Vec2 v) {
	return sqrt(pow( (v.x - x), 2) + pow( (v.y - y), 2) );
}

float Vec2::inclinacaoX() {
	return atan2(y,x);
}

float Vec2::inclinacaoReta(Vec2 v) {
	Vec2 temp = *this;

	temp.subtrair(v);
	return temp.inclinacaoX();
}

void Vec2::rotacao(float theta) {
	float oldx = x, oldy = y;
	x = oldx * cos(theta) - oldy * sin(theta);
	y = oldy * cos(theta) + oldx * sin(theta);
}