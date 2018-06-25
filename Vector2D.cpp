#include "Vector2D.h"

Vector2d::Vector2d()
{
	x = 0.0;
	y = 0.0;
}

Vector2d::Vector2d(double sourceX, double sourceY)
{
	x = sourceX;
	y = sourceY;
}

Vector2d Vector2d::operator+(const Vector2d &v) const
{
	return Vector2d(x + v.x, y + v.y);
}

Vector2d Vector2d::operator-(const Vector2d &v) const
{
	return Vector2d(x - v.x, y - v.y);
}

Vector2d Vector2d::operator*(const Vector2d &v) const
{
	return Vector2d(x*v.x, y*v.y);
}

Vector2d Vector2d::operator/(const Vector2d &v) const
{
	return Vector2d(x / v.x, y / v.y);
}

bool Vector2d::operator==(const Vector2d &v) const
{
	return ((x == v.x) && (y == v.y));
}

bool Vector2d::operator>(const Vector2d &v) const
{
	return (x*x + y*y) > (v.x*v.x + v.y*v.y);
}

bool Vector2d::operator<(const Vector2d &v) const
{
	return (x*x + y*y) < (v.x*v.x + v.y*v.y);
}

bool Vector2d::operator>=(const Vector2d &v) const
{
	return (x*x + y*y) > (v.x*v.x + v.y*v.y) ||
		(x*x + y*y) == (v.x*v.x + v.y*v.y);
}

bool Vector2d::operator<=(const Vector2d &v) const
{
	return (x*x + y*y) < (v.x*v.x + v.y*v.y) ||
		(x*x + y*y) == (v.x*v.x + v.y*v.y);
}
Vector2d Vector2d::operator-() const
{
	return Vector2d(-x, -y);
}

Vector2d Vector2d::operator*(const float& scalar) const
{
	return Vector2d(x*scalar, y*scalar);
}

Vector2d Vector2d::operator/(const float& scalar) const
{
	return Vector2d(x / scalar, y / scalar);
}

double Vector2d::DotProduct(const Vector2d &a, const Vector2d &b)
{
	return ((a.x * b.x) + (a.y * b.y));
}

double Vector2d::CrossProduct(const Vector2d &a, const Vector2d &b)
{
	return ((a.x * b.y) - (a.y * b.x));
}

double Vector2d::Magnitude(const Vector2d &v)
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}

Vector2d Vector2d::Normal(const Vector2d &v)
{
	double magnitude = Magnitude(v);
	return Vector2d(v.x / magnitude, v.y / magnitude);
}

Vector2d Vector2d::Perpendicular(const Vector2d &v)
{
	return Vector2d(v.y, -v.x);
}

bool Vector2d::Intersect(const Vector2d &aa, const Vector2d &ab, const Vector2d &ba, const Vector2d &bb)
{
	Vector2d p = aa;
	Vector2d r = ab - aa;
	Vector2d q = ba;
	Vector2d s = bb - ba;

	double t = CrossProduct((q - p), s) / CrossProduct(r, s);
	double u = CrossProduct((q - p), r) / CrossProduct(r, s);

	return (0.0 <= t && t <= 1.0) &&
		(0.0 <= u && u <= 1.0);
}

Vector2d Vector2d::GetIntersect(const Vector2d &aa, const Vector2d &ab, const Vector2d &ba, const Vector2d &bb)
{
	double pX = (aa.x*ab.y - aa.y*ab.x)*(ba.x - bb.x) -
		(ba.x*bb.y - ba.y*bb.x)*(aa.x - ab.x);
	double pY = (aa.x*ab.y - aa.y*ab.x)*(ba.y - bb.y) -
		(ba.x*bb.y - ba.y*bb.x)*(aa.y - ab.y);
	double denominator = (aa.x - ab.x)*(ba.y - bb.y) -
		(aa.y - ab.y)*(ba.x - bb.x);

	return Vector2d(pX / denominator, pY / denominator);
}
