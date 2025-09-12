#ifndef VEC2_H
#define VEC2_H


class Vec2{
	public:

	float x,y;
	Vec2();

	void somar(Vec2 v);
	void subtrair(Vec2 v);
	void multiplicacao(float k);
	float magnitude() const;
	void normalizar();
	float distancia(Vec2 v) const;
	float inclinacaoX() const;
	float inclinacaoReta(Vec2 v);
	void rotacao(float theta);
};


#endif