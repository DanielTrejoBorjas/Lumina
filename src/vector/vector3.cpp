
#include <lumina/vector/vector3.hpp>
#include <cmath>
#include <algorithm>
#include <stdexcept>


namespace lumina
{

template <typename T>
Vector3<T>::Vector3() : x(T(0)), y(T(0)), z(T(0)) {}

template <typename T>
Vector3<T>::Vector3(const T scalar) : x(scalar), y(scalar), z(scalar) {}

template <typename T>
Vector3<T>::Vector3(const T x, const T y, const T z) : x(x), y(y), z(z) {}

// Arithmetic operators with another Vector3
template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3 &other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3 &other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

template <typename T>
Vector3<T> Vector3<T>::operator*(const Vector3 &other) const
{
    return Vector3(x * other.x, y * other.y, z * other.z);
}

template <typename T>
Vector3<T> Vector3<T>::operator/(const Vector3 &other) const
{
    return Vector3(x / other.x, y / other.y, z / other.z);
}

// Arithmetic operators with scalar
template <typename T>
Vector3<T> Vector3<T>::operator+(T scalar) const
{
    return Vector3(x + scalar, y + scalar, z + scalar);
}

template <typename T>
Vector3<T> Vector3<T>::operator-(T scalar) const
{
    return Vector3(x - scalar, y - scalar, z - scalar);
}

template <typename T>
Vector3<T> Vector3<T>::operator*(T scalar) const
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

template <typename T>
Vector3<T> Vector3<T>::operator/(T scalar) const
{
    return Vector3(x / scalar, y / scalar, z / scalar);
}

// Unary operators
template <typename T>
Vector3<T> Vector3<T>::operator+() const
{
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator-() const
{
    return Vector3(-x, -y, -z);
}

// Compound assignment operators
template <typename T>
Vector3<T> &Vector3<T>::operator+=(const Vector3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Vector3<T> &Vector3<T>::operator-=(const Vector3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
Vector3<T> &Vector3<T>::operator*=(const Vector3 &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

template <typename T>
Vector3<T> &Vector3<T>::operator/=(const Vector3 &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

// Comparison operators
template <typename T>
bool Vector3<T>::operator==(const Vector3 &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

template <typename T>
bool Vector3<T>::operator!=(const Vector3 &other) const
{
    return !(*this == other);
}

// Array-style access operators
template <typename T>
T &Vector3<T>::operator[](int index)
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else if (index == 2)
        return z;
    else
        throw std::out_of_range("Vector3 index out of range");
}

template <typename T>
const T &Vector3<T>::operator[](int index) const
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else if (index == 2)
        return z;
    else
        throw std::out_of_range("Vector3 index out of range");
}

// Pointer access to data
template <typename T>
T *Vector3<T>::data()
{
    return &x;
}

template <typename T>
const T *Vector3<T>::data() const
{
    return &x;
}

// Vector properties
template <typename T>
Vector3<T> Vector3<T>::normalized() const
{
    T mag = magnitude();
    if (mag == T(0))
        return Vector3(0);
    return *this / mag;
}

template <typename T>
T Vector3<T>::magnitude() const
{
    return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
T Vector3<T>::sqrMagnitude() const
{
    return x * x + y * y + z * z;
}

// Static predefined vectors
template <typename T>
Vector3<T> Vector3<T>::zero()
{
    return Vector3(0, 0, 0);
}

template <typename T>
Vector3<T> Vector3<T>::one()
{
    return Vector3(1, 1, 1);
}

template <typename T>
Vector3<T> Vector3<T>::up()
{
    return Vector3(0, 1, 0);
}

template <typename T>
Vector3<T> Vector3<T>::down()
{
    return Vector3(0, -1, 0);
}

template <typename T>
Vector3<T> Vector3<T>::left()
{
    return Vector3(-1, 0, 0);
}

template <typename T>
Vector3<T> Vector3<T>::right()
{
    return Vector3(1, 0, 0);
}

template <typename T>
Vector3<T> Vector3<T>::forward()
{
    return Vector3(0, 0, 1);
}

template <typename T>
Vector3<T> Vector3<T>::back()
{
    return Vector3(0, 0, -1);
}

// Static vector operations
template <typename T>
T Vector3<T>::angle(const Vector3 &a, const Vector3 &b)
{
    T dotProduct = dot(a.normalized(), b.normalized());
    dotProduct = std::clamp(dotProduct, T(-1), T(1)); // Clamp for safety
    return std::acos(dotProduct); // Returns radians
}

template <typename T>
T Vector3<T>::distance(const Vector3 &a, const Vector3 &b)
{
    return (a - b).magnitude();
}

template <typename T>
T Vector3<T>::dot(const Vector3 &a, const Vector3 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename T>
Vector3<T> Vector3<T>::cross(const Vector3 &a, const Vector3 &b)
{
    return Vector3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
}

template <typename T>
Vector3<T> Vector3<T>::lerp(const Vector3 &a, const Vector3 &b, T t)
{
    return a + (b - a) * t;
}

template <typename T>
Vector3<T> Vector3<T>::reflect(const Vector3 &vector, const Vector3 &normal)
{
    // R = V - 2*(V·N)*N
    T dotProduct = dot(vector, normal);
    return vector - normal * (T(2) * dotProduct);
}

template <typename T>
Vector3<T> Vector3<T>::min(const Vector3 &a, const Vector3 &b)
{
    return Vector3(
        std::min(a.x, b.x),
        std::min(a.y, b.y),
        std::min(a.z, b.z));
}

template <typename T>
Vector3<T> Vector3<T>::max(const Vector3 &a, const Vector3 &b)
{
    return Vector3(
        std::max(a.x, b.x),
        std::max(a.y, b.y),
        std::max(a.z, b.z));
}

template <typename T>
Vector3<T> Vector3<T>::clamp(const Vector3 &vector, const Vector3 &minVec, const Vector3 &maxVec)
{
    return Vector3(
        std::clamp(vector.x, minVec.x, maxVec.x),
        std::clamp(vector.y, minVec.y, maxVec.y),
        std::clamp(vector.z, minVec.z, maxVec.z));
}

template <typename T>
Vector3<T> Vector3<T>::normalize(const Vector3 &vector)
{
    return vector.normalized();
}

template <typename T>
Vector3<T> Vector3<T>::abs(const Vector3 &vector)
{
    return Vector3(
        std::abs(vector.x),
        std::abs(vector.y),
        std::abs(vector.z));
}

} // namespace lumina
