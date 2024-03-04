#include <iostream>
#include <chrono>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    struct Rectangle r;
    r.length = 10;
    r.breadth = 5;

    struct Rectangle p = {20, 10};
    cout << r.length * r.breadth << endl;
    cout << p.length * p.breadth << endl;

    // Complex Number
    struct Complex
    {
        int a;
        int b;
    };

    struct Complex c = {2, 3};
    cout << c.a << "+" << c.b << "i" << endl;

    // Student Information Structure
    struct Student
    {
        int roll;
        char name[20];
        char department[20];
        float cgpa;
        char address[100];
    };

    struct Card
    {
        int face;
        int shape;
        int color;
    };

    struct Card deck[52];

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Execution time: " << duration << " ms" << std::endl;
    return 0;
}