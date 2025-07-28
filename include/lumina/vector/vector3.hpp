#pragma once

namespace lumina
{

    template <typename T>
    class Vector3
    {
    public:
        // Member variables
        T x, y, z;

        // Constructors
        Vector3();
        Vector3(const T scalar);
        Vector3(const T x, const T y, const T z);

        // Arithmetic operators with another Vector3
        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator-(const Vector3 &other) const;
        Vector3 operator*(const Vector3 &other) const;
        Vector3 operator/(const Vector3 &other) const;

        // Arithmetic operators with scalar
        Vector3 operator+(T scalar) const;
        Vector3 operator-(T scalar) const;
        Vector3 operator*(T scalar) const;
        Vector3 operator/(T scalar) const;

        // Unary operators
        Vector3 operator+() const;
        Vector3 operator-() const;

        // Compound assignment operators
        Vector3 &operator+=(const Vector3 &other);
        Vector3 &operator-=(const Vector3 &other);
        Vector3 &operator*=(const Vector3 &other);
        Vector3 &operator/=(const Vector3 &other);

        // Comparison operators
        bool operator==(const Vector3 &other) const;
        bool operator!=(const Vector3 &other) const;

        // Array-style access operators
        T &operator[](int index);
        const T &operator[](int index) const;

        // Pointer access to data
        T *data();
        const T *data() const;

        // Vector properties
        Vector3 normalized() const;
        T magnitude() const;
        T sqrMagnitude() const;

        // Static predefined vectors
        static Vector3 zero();
        static Vector3 one();
        static Vector3 up();
        static Vector3 down();
        static Vector3 left();
        static Vector3 right();
        static Vector3 forward();
        static Vector3 back();

        // Static vector operations
        static T angle(const Vector3 &a, const Vector3 &b);
        static T distance(const Vector3 &a, const Vector3 &b);
        static T dot(const Vector3 &a, const Vector3 &b);
        static Vector3 cross(const Vector3 &a, const Vector3 &b);
        static Vector3 lerp(const Vector3 &a, const Vector3 &b, T t);
        static Vector3 reflect(const Vector3 &vector, const Vector3 &normal);
        static Vector3 min(const Vector3 &a, const Vector3 &b);
        static Vector3 max(const Vector3 &a, const Vector3 &b);
        static Vector3 clamp(const Vector3 &vector, const Vector3 &min, const Vector3 &max);
        static Vector3 normalize(const Vector3 &vector);
        static Vector3 abs(const Vector3 &vector);
    };

} // namespace lumina
