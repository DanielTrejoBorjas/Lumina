#pragma once

namespace lumina
{

    template <typename T>
    class Vector4
    {
    public:
        // Member variables
        T x, y, z, w;

        // Constructors
        Vector4();
        Vector4(const T scalar);
        Vector4(const T x, const T y, const T z, const T w);

        // Arithmetic operators with another Vector4
        Vector4 operator+(const Vector4 &other) const;
        Vector4 operator-(const Vector4 &other) const;
        Vector4 operator*(const Vector4 &other) const;
        Vector4 operator/(const Vector4 &other) const;

        // Arithmetic operators with scalar
        Vector4 operator+(T scalar) const;
        Vector4 operator-(T scalar) const;
        Vector4 operator*(T scalar) const;
        Vector4 operator/(T scalar) const;

        // Unary operators
        Vector4 operator+() const;
        Vector4 operator-() const;

        // Compound assignment operators
        Vector4 &operator+=(const Vector4 &other);
        Vector4 &operator-=(const Vector4 &other);
        Vector4 &operator*=(const Vector4 &other);
        Vector4 &operator/=(const Vector4 &other);

        // Comparison operators
        bool operator==(const Vector4 &other) const;
        bool operator!=(const Vector4 &other) const;

        // Array-style access operators
        T &operator[](int index);
        const T &operator[](int index) const;

        // Pointer access to data
        T *data();
        const T *data() const;

        // Vector properties
        Vector4 normalized() const;
        T magnitude() const;
        T sqrMagnitude() const;

        // Static predefined vectors
        static Vector4 zero();
        static Vector4 one();

        // Static vector operations
        static T angle(const Vector4 &a, const Vector4 &b);
        static T distance(const Vector4 &a, const Vector4 &b);
        static T dot(const Vector4 &a, const Vector4 &b);
        static Vector4 lerp(const Vector4 &a, const Vector4 &b, T t);
        static Vector4 reflect(const Vector4 &vector, const Vector4 &normal);
        static Vector4 min(const Vector4 &a, const Vector4 &b);
        static Vector4 max(const Vector4 &a, const Vector4 &b);
        static Vector4 clamp(const Vector4 &vector, const Vector4 &min, const Vector4 &max);
        static Vector4 normalize(const Vector4 &vector);
        static Vector4 abs(const Vector4 &vector);
    };

} // namespace lumina
