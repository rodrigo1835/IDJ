#ifndef RECT_H
#define RECT_H

#include "Vec2.h"


class Rect{
public:
	float x,y,w,h;

	Rect();
	Rect(float x, float y, float w, float h);

	void somar(Vec2 v);
	void subtrair(Vec2 v);

	Vec2 centro() const;
	float distanciaCentros(const Rect& outro);
	bool contemPonto(Vec2 ponto) const;
};


#endif