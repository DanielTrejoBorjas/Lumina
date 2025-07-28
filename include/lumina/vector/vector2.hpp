#pragma once

namespace lumina
{

    template <typename T>
    class Vector2
    {
    public:
        // Member variables
        T x, y;

        // Constructors
        Vector2();
        Vector2(const T scalar);
        Vector2(const T x, const T y);

        // Arithmetic operators with another Vector2
        Vector2 operator+(const Vector2 &other) const;
        Vector2 operator-(const Vector2 &other) const;
        Vector2 operator*(const Vector2 &other) const;
        Vector2 operator/(const Vector2 &other) const;

        // Arithmetic operators with scalar
        Vector2 operator+(T scalar) const;
        Vector2 operator-(T scalar) const;
        Vector2 operator*(T scalar) const;
        Vector2 operator/(T scalar) const;

        // Unary operators
        Vector2 operator+() const;
        Vector2 operator-() const;

        // Compound assignment operators
        Vector2 &operator+=(const Vector2 &other);
        Vector2 &operator-=(const Vector2 &other);
        Vector2 &operator*=(const Vector2 &other);
        Vector2 &operator/=(const Vector2 &other);

        // Comparison operators
        bool operator==(const Vector2 &other) const;
        bool operator!=(const Vector2 &other) const;

        // Array-style access operators
        T &operator[](int index);
        const T &operator[](int index) const;

        // Pointer access to data
        T *data();
        const T *data() const;

        // Vector properties
        Vector2 normalized() const;
        T magnitude() const;
        T sqrMagnitude() const;

        // Static predefined vectors
        static Vector2 zero();
        static Vector2 one();
        static Vector2 up();
        static Vector2 down();
        static Vector2 left();
        static Vector2 right();

        // Static vector operations
        static T angle(const Vector2 &a, const Vector2 &b);
        static T distance(const Vector2 &a, const Vector2 &b);
        static T dot(const Vector2 &a, const Vector2 &b);
        static Vector2 lerp(const Vector2 &a, const Vector2 &b, T t);
        static Vector2 reflect(const Vector2 &vector, const Vector2 &normal);
        static Vector2 min(const Vector2 &a, const Vector2 &b);
        static Vector2 max(const Vector2 &a, const Vector2 &b);
        static Vector2 clamp(const Vector2 &vector, const Vector2 &min, const Vector2 &max);
        static Vector2 normalize(const Vector2 &vector);
        static Vector2 abs(const Vector2 &vector);
    };

} // namespace lumina
