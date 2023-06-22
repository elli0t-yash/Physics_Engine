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

        Vector3 operator/(float scalar) const {
            return Vector3(x / scalar, y / scalar, z / scalar);
        }

        Vector3& operator+=(const Vector3& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        Vector3& operator-=(const Vector3& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        Vector3& operator*=(const Vector3& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }

        Vector3& operator/=(const Vector3& other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
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

struct Particle {
    float mass;
    Vector3 position;
    Vector3 velocity;

    Particle(float mass, const Vector3& position, const Vector3 velocity) 
        : mass(mass), position(position), velocity(velocity) {}
};

void updateParticles(std::vector<Particle>& particles, float deltaTime) {
    const float gravity = 9.8f;

    for(auto& particle : particles) {
        Vector3 force(0.0f, -gravity * particle.mass, 0.0f);
        particle.velocity = particle.velocity + (force * deltaTime)/particle.mass;

        particle.position = particle.position + particle.velocity * deltaTime;
    }
}

int main() {
    std::vector<Particle> particles {
        Particle(1.0f, Vector3(0.0f, 0.0f, 0.0f), Vector3(10.0f, 0.0f, 0.0f)),
        Particle(2.0f, Vector3(5.0f, 0.0f, 0.0f), Vector3(-5.0f, 0.0f, 0.0f))
    };

    float deltaTime = 0.1f;

    for(int i = 0; i < 10; ++i) {
        updateParticles(particles, deltaTime);

        for(const auto& particle : particles) {
            std::cout << "Particle: x =" <<particle.position.x << ", y =" <<particle.position.y << ", z =" <<particle.position.z <<std::endl;
        }

        std::cout<<"--------------"<<std::endl;
    }

    return 0;
}