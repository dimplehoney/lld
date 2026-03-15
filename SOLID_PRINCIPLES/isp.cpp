#include <iostream>
using namespace std;

class twoDShapes
{
    public:
        virtual double area()=0;

};

class ThreeDShape
{
    public:
        virtual double area()=0;
        virtual double volume()=0;
};


class square: public twoDShapes
{   
    private:
        double side;
    public:
        square(double side)
        {
            this->side=side;
        }

        double area()
        {
            return side*side;
        }
};

class cube: public ThreeDShape
{
    private:
        double side;
    public:
        cube(double side)
        {
            this->side=side;
        }

        double area()
        {
            return 6*side*side;
        }

        double volume()
        {
            return side*side*side;
        }
};

int main()
{
    twoDShapes* sq=new square(5);
    cout << "area of square is " << sq->area() << endl;

    ThreeDShape* cu=new cube(2);    
    cout << "area of cube is " << cu->area() << endl;
    cout << "volume of cube is " << cu->volume() << endl;

}