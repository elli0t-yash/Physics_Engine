#include <iostream>
#include <vector>
#include <cmath>

class Vector3 {
    public:
        float x, y, z;

        // Constructor
        Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

        Vector3 operator+(const Vector3& other) const {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        Vector3 operator-(const Vector3& other) const {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

        Vector3 operator*(float scalar) const {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }

        float dot(const Vector3& other) const {
            return x * other.x + y * other.y + z * other.z; 
        }

        Vector3 cross(const Vector3& other) const {
            return Vector3(y * other.z - z * other.y + z * other.x - x * other.z + x * other.y - y * other.x);
        }

        float magnitude() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        Vector3 normalized() const {
            float mag = magnitude();
            if(mag > 0.0f) 
                return *this * (1.0f/mag);
            else    
                return *this;
        }
};

