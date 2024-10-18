#ifndef VECTOR2_H__
#define VECTOR2_H__

// pour générer les mouvements

class Vector2
{
protected:


public:
	float x;
	float y;
	Vector2();
	Vector2(float x, float y);

	Vector2 operator+(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);

	Vector2 operator*(float scalar) const;
};


#endif // !VECTOR2_H__