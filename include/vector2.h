#ifndef PHYSICSENGINE_VECTOR2_H
#define PHYSICSENGINE_VECTOR2_H

namespace pheng{

    class vector2 {
        double x;
        double y;

    public:
        vector2();
        vector2(double x, double y);

        void setX(double);
        void setY(double);
        double getX();
        double getY();

        vector2 operator +(vector2 v2); // algebraic sum
        vector2 operator -(vector2 v2);
        void operator +=(vector2 v2);
        void operator -=(vector2 v2);
        vector2 operator *(double m);
        vector2 operator /(double m);

        static double dotProduct(vector2 v1, vector2 v2);

        double angle();
        static double angle(vector2);
        static double angleBetween(vector2, vector2);

        static pheng::vector2 twoPoints(vector2 p1, vector2 p2);
        static pheng::vector2 fromNormAngle(double norm, double angle);

        double norm();
        static double norm(vector2 v);
        static double norm(vector2 v1, vector2 v2);
    };
}

#endif //PHYSICSENGINE_VECTOR2_H
