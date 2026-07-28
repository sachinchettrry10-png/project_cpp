#include <iostream>
#include <cmath>
using namespace std;

// Generic Vector class with operator overloading
template <typename T>
class Vector {
private:
    T x, y, z;
    
public:
    Vector(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}
    
    // Addition operator overload
    Vector<T> operator+(const Vector<T>& other) const {
        cout << "Vector addition" << endl;
        return Vector<T>(x + other.x, y + other.y, z + other.z);
    }
    
    // Subtraction operator overload
    Vector<T> operator-(const Vector<T>& other) const {
        cout << "Vector subtraction" << endl;
        return Vector<T>(x - other.x, y - other.y, z - other.z);
    }
    
    // Scalar multiplication (member function)
    Vector<T> operator*(T scalar) const {
        cout << "Vector scalar multiplication" << endl;
        return Vector<T>(x * scalar, y * scalar, z * scalar);
    }
    
    // Equality operator
    bool operator==(const Vector<T>& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }
    
    // Unary minus
    Vector<T> operator-() const {
        return Vector<T>(-x, -y, -z);
    }
    
    // Stream insertion operator (friend function)
    friend ostream& operator<<(ostream& os, const Vector<T>& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    
    // Accessor methods
    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }
};

// Non-member operator overloading with templates
template <typename T>
Vector<T> operator*(T scalar, const Vector<T>& v) {
    cout << "Scalar * Vector (non-member)" << endl;
    return Vector<T>(v.getX() * scalar, v.getY() * scalar, v.getZ() * scalar);
}

// Template function for dot product using overloaded operators
template <typename T>
T dotProduct(const Vector<T>& a, const Vector<T>& b) {
    return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

// Generic matrix class with operator overloading
template <typename T>
class Matrix {
private:
    T data[2][2];
    
public:
    Matrix(T a = 0, T b = 0, T c = 0, T d = 0) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }
    
    // Matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    // Matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    
    friend ostream& operator<<(ostream& os, const Matrix<T>& m) {
        os << "[" << m.data[0][0] << " " << m.data[0][1] << "]" << endl;
        os << "[" << m.data[1][0] << " " << m.data[1][1] << "]";
        return os;
    }
};

int main() {
    // Vector operations with different types
    Vector<int> v1(1, 2, 3);
    Vector<int> v2(4, 5, 6);
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * 2 = " << (v1 * 2) << endl;
    cout << "2 * v1 = " << (2 * v1) << endl;
    cout << "-v1 = " << (-v1) << endl;
    
    // Dot product
    cout << "Dot product: " << dotProduct(v1, v2) << endl;
    
    // Vector with double
    Vector<double> v3(1.5, 2.5, 3.5);
    Vector<double> v4(0.5, 1.5, 2.5);
    cout << "\nDouble vectors:" << endl;
    cout << "v3 + v4 = " << (v3 + v4) << endl;
    
    // Matrix operations
    Matrix<int> m1(1, 2, 3, 4);
    Matrix<int> m2(5, 6, 7, 8);
    
    cout << "\nMatrix operations:" << endl;
    cout << "m1 = " << endl << m1 << endl;
    cout << "m2 = " << endl << m2 << endl;
    cout << "m1 + m2 = " << endl << (m1 + m2) << endl;
    cout << "m1 * m2 = " << endl << (m1 * m2) << endl;
    
    // Mixed type operations (demonstrating template flexibility)
    Vector<float> v5(1.1f, 2.2f, 3.3f);
    Vector<float> v6(4.4f, 5.5f, 6.6f);
    cout << "\nFloat vectors:" << endl;
    cout << "v5 + v6 = " << (v5 + v6) << endl;
    
    return 0;
}
