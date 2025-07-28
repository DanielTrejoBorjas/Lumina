#include <lumina/vector/vector4.hpp>
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace lumina
{

template <typename T>
Vector4<T>::Vector4() : x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}

template <typename T>
Vector4<T>::Vector4(const T scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}

template <typename T>
Vector4<T>::Vector4(const T x, const T y, const T z, const T w) : x(x), y(y), z(z), w(w) {}

// Arithmetic operators with another Vector4
template <typename T>
Vector4<T> Vector4<T>::operator+(const Vector4 &other) const
{
    return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

template <typename T>
Vector4<T> Vector4<T>::operator-(const Vector4 &other) const
{
    return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

template <typename T>
Vector4<T> Vector4<T>::operator*(const Vector4 &other) const
{
    return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
}

template <typename T>
Vector4<T> Vector4<T>::operator/(const Vector4 &other) const
{
    return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
}

// Arithmetic operators with scalar
template <typename T>
Vector4<T> Vector4<T>::operator+(T scalar) const
{
    return Vector4(x + scalar, y + scalar, z + scalar, w + scalar);
}

template <typename T>
Vector4<T> Vector4<T>::operator-(T scalar) const
{
    return Vector4(x - scalar, y - scalar, z - scalar, w - scalar);
}

template <typename T>
Vector4<T> Vector4<T>::operator*(T scalar) const
{
    return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

template <typename T>
Vector4<T> Vector4<T>::operator/(T scalar) const
{
    return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

// Unary operators
template <typename T>
Vector4<T> Vector4<T>::operator+() const
{
    return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator-() const
{
    return Vector4(-x, -y, -z, -w);
}

// Compound assignment
template <typename T>
Vector4<T> &Vector4<T>::operator+=(const Vector4 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

template <typename T>
Vector4<T> &Vector4<T>::operator-=(const Vector4 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

template <typename T>
Vector4<T> &Vector4<T>::operator*=(const Vector4 &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}

template <typename T>
Vector4<T> &Vector4<T>::operator/=(const Vector4 &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
}

// Comparison
template <typename T>
bool Vector4<T>::operator==(const Vector4 &other) const
{
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

template <typename T>
bool Vector4<T>::operator!=(const Vector4 &other) const
{
    return !(*this == other);
}

// Array-style access
template <typename T>
T &Vector4<T>::operator[](int index)
{
    if (index == 0) return x;
    if (index == 1) return y;
    if (index == 2) return z;
    if (index == 3) return w;
    throw std::out_of_range("Vector4 index out of range");
}

template <typename T>
const T &Vector4<T>::operator[](int index) const
{
    if (index == 0) return x;
    if (index == 1) return y;
    if (index == 2) return z;
    if (index == 3) return w;
    throw std::out_of_range("Vector4 index out of range");
}

// Pointer access
template <typename T>
T *Vector4<T>::data()
{
    return &x;
}

template <typename T>
const T *Vector4<T>::data() const
{
    return &x;
}

// Vector properties
template <typename T>
Vector4<T> Vector4<T>::normalized() const
{
    T mag = magnitude();
    if (mag == T(0))
        return Vector4(0);
    return *this / mag;
}

template <typename T>
T Vector4<T>::magnitude() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

template <typename T>
T Vector4<T>::sqrMagnitude() const
{
    return x * x + y * y + z * z + w * w;
}

// Predefined vectors
template <typename T>
Vector4<T> Vector4<T>::zero()
{
    return Vector4(0, 0, 0, 0);
}

template <typename T>
Vector4<T> Vector4<T>::one()
{
    return Vector4(1, 1, 1, 1);
}

// Static operations
template <typename T>
T Vector4<T>::dot(const Vector4 &a, const Vector4 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

template <typename T>
T Vector4<T>::distance(const Vector4 &a, const Vector4 &b)
{
    return (a - b).magnitude();
}

template <typename T>
T Vector4<T>::angle(const Vector4 &a, const Vector4 &b)
{
    T dotProduct = dot(a.normalized(), b.normalized());
    dotProduct = std::clamp(dotProduct, T(-1), T(1));
    return std::acos(dotProduct); // Radianes
}

template <typename T>
Vector4<T> Vector4<T>::lerp(const Vector4 &a, const Vector4 &b, T t)
{
    return a + (b - a) * t;
}

template <typename T>
Vector4<T> Vector4<T>::reflect(const Vector4 &vector, const Vector4 &normal)
{
    T dotProduct = dot(vector, normal);
    return vector - normal * (T(2) * dotProduct);
}

template <typename T>
Vector4<T> Vector4<T>::min(const Vector4 &a, const Vector4 &b)
{
    return Vector4(
        std::min(a.x, b.x),
        std::min(a.y, b.y),
        std::min(a.z, b.z),
        std::min(a.w, b.w));
}

template <typename T>
Vector4<T> Vector4<T>::max(const Vector4 &a, const Vector4 &b)
{
    return Vector4(
        std::max(a.x, b.x),
        std::max(a.y, b.y),
        std::max(a.z, b.z),
        std::max(a.w, b.w));
}

template <typename T>
Vector4<T> Vector4<T>::clamp(const Vector4 &vector, const Vector4 &minVec, const Vector4 &maxVec)
{
    return Vector4(
        std::clamp(vector.x, minVec.x, maxVec.x),
        std::clamp(vector.y, minVec.y, maxVec.y),
        std::clamp(vector.z, minVec.z, maxVec.z),
        std::clamp(vector.w, minVec.w, maxVec.w));
}

template <typename T>
Vector4<T> Vector4<T>::normalize(const Vector4 &vector)
{
    return vector.normalized();
}

template <typename T>
Vector4<T> Vector4<T>::abs(const Vector4 &vector)
{
    return Vector4(
        std::abs(vector.x),
        std::abs(vector.y),
        std::abs(vector.z),
        std::abs(vector.w));
}

} // namespace lumina
