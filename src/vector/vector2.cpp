#include <lumina/vector/vector2.hpp>
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace lumina
{

template <typename T>
Vector2<T>::Vector2() : x(T(0)), y(T(0)) {}

template <typename T>
Vector2<T>::Vector2(const T scalar) : x(scalar), y(scalar) {}

template <typename T>
Vector2<T>::Vector2(const T x, const T y) : x(x), y(y) {}

// Arithmetic operators with another Vector2
template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2 &other) const
{
    return Vector2(x + other.x, y + other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2 &other) const
{
    return Vector2(x - other.x, y - other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(const Vector2 &other) const
{
    return Vector2(x * other.x, y * other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator/(const Vector2 &other) const
{
    return Vector2(x / other.x, y / other.y);
}

// Arithmetic operators with scalar
template <typename T>
Vector2<T> Vector2<T>::operator+(T scalar) const
{
    return Vector2(x + scalar, y + scalar);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(T scalar) const
{
    return Vector2(x - scalar, y - scalar);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(T scalar) const
{
    return Vector2(x * scalar, y * scalar);
}

template <typename T>
Vector2<T> Vector2<T>::operator/(T scalar) const
{
    return Vector2(x / scalar, y / scalar);
}

// Unary operators
template <typename T>
Vector2<T> Vector2<T>::operator+() const
{
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator-() const
{
    return Vector2(-x, -y);
}

// Compound assignment operators
template <typename T>
Vector2<T> &Vector2<T>::operator+=(const Vector2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
Vector2<T> &Vector2<T>::operator-=(const Vector2 &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
Vector2<T> &Vector2<T>::operator*=(const Vector2 &other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

template <typename T>
Vector2<T> &Vector2<T>::operator/=(const Vector2 &other)
{
    x /= other.x;
    y /= other.y;
    return *this;
}

// Comparison operators
template <typename T>
bool Vector2<T>::operator==(const Vector2 &other) const
{
    return x == other.x && y == other.y;
}

template <typename T>
bool Vector2<T>::operator!=(const Vector2 &other) const
{
    return !(*this == other);
}

// Array-style access
template <typename T>
T &Vector2<T>::operator[](int index)
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        throw std::out_of_range("Vector2 index out of range");
}

template <typename T>
const T &Vector2<T>::operator[](int index) const
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        throw std::out_of_range("Vector2 index out of range");
}

// Pointer access to data
template <typename T>
T *Vector2<T>::data()
{
    return &x;
}

template <typename T>
const T *Vector2<T>::data() const
{
    return &x;
}

// Vector properties
template <typename T>
Vector2<T> Vector2<T>::normalized() const
{
    T mag = magnitude();
    if (mag == T(0))
        return Vector2(0);
    return *this / mag;
}

template <typename T>
T Vector2<T>::magnitude() const
{
    return std::sqrt(x * x + y * y);
}

template <typename T>
T Vector2<T>::sqrMagnitude() const
{
    return x * x + y * y;
}

// Static predefined vectors
template <typename T>
Vector2<T> Vector2<T>::zero()
{
    return Vector2(0, 0);
}

template <typename T>
Vector2<T> Vector2<T>::one()
{
    return Vector2(1, 1);
}

template <typename T>
Vector2<T> Vector2<T>::up()
{
    return Vector2(0, 1);
}

template <typename T>
Vector2<T> Vector2<T>::down()
{
    return Vector2(0, -1);
}

template <typename T>
Vector2<T> Vector2<T>::left()
{
    return Vector2(-1, 0);
}

template <typename T>
Vector2<T> Vector2<T>::right()
{
    return Vector2(1, 0);
}

// Static vector operations
template <typename T>
T Vector2<T>::angle(const Vector2 &a, const Vector2 &b)
{
    T dotProduct = dot(a.normalized(), b.normalized());
    dotProduct = std::clamp(dotProduct, T(-1), T(1));
    return std::acos(dotProduct); // Radianes
}

template <typename T>
T Vector2<T>::distance(const Vector2 &a, const Vector2 &b)
{
    return (a - b).magnitude();
}

template <typename T>
T Vector2<T>::dot(const Vector2 &a, const Vector2 &b)
{
    return a.x * b.x + a.y * b.y;
}

template <typename T>
Vector2<T> Vector2<T>::lerp(const Vector2 &a, const Vector2 &b, T t)
{
    return a + (b - a) * t;
}

template <typename T>
Vector2<T> Vector2<T>::reflect(const Vector2 &vector, const Vector2 &normal)
{
    T dotProduct = dot(vector, normal);
    return vector - normal * (T(2) * dotProduct);
}

template <typename T>
Vector2<T> Vector2<T>::min(const Vector2 &a, const Vector2 &b)
{
    return Vector2(std::min(a.x, b.x), std::min(a.y, b.y));
}

template <typename T>
Vector2<T> Vector2<T>::max(const Vector2 &a, const Vector2 &b)
{
    return Vector2(std::max(a.x, b.x), std::max(a.y, b.y));
}

template <typename T>
Vector2<T> Vector2<T>::clamp(const Vector2 &vector, const Vector2 &minVec, const Vector2 &maxVec)
{
    return Vector2(
        std::clamp(vector.x, minVec.x, maxVec.x),
        std::clamp(vector.y, minVec.y, maxVec.y));
}

template <typename T>
Vector2<T> Vector2<T>::normalize(const Vector2 &vector)
{
    return vector.normalized();
}

template <typename T>
Vector2<T> Vector2<T>::abs(const Vector2 &vector)
{
    return Vector2(std::abs(vector.x), std::abs(vector.y));
}

} // namespace lumina
