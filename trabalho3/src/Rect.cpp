
#include "Rect.h"


Rect::Rect() {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Rect::somar(Vec2 v) {
	x += v.x;
	y += v.y;
}

void Rect::subtrair(Vec2 v) {
	x -= v.x;
	y -= v.y;
}

Vec2 Rect::centro() const {
	return Vec2(x + w/2, y + h/2);
}

float Rect::distanciaCentros(const Rect& outro) {
	Vec2 centro1 = this->centro();
	Vec2 centro2 = outro.centro();

	return centro1.distancia(centro2);
}

bool Rect::contemPonto(Vec2 ponto) const {
	return ( ponto.x >= x && ponto.x <= x + w && ponto.y >= y && ponto.y <= y+h );
}