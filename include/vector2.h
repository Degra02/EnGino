#ifndef PHYSICSENGINE_VECTOR2_H
#define PHYSICSENGINE_VECTOR2_H

namespace pheng{

    class vector2 {
        float x;
        float y;

    public:
        vector2();
        vector2(float x, float y);

        void setX(float);
        void setY(float);
        float getX() const;
        float getY() const;

        vector2 operator +(vector2 v2) const; // algebraic sum
        vector2 operator -(vector2 v2) const;
        void operator +=(vector2 v2);
        void operator -=(vector2 v2);
        vector2 operator *(float m) const;
        vector2 operator /(float m) const;

        static float dotProduct(vector2 v1, vector2 v2);

        float angle() const;
        static float angle(vector2);
        static float angleBetween(vector2, vector2);

        static pheng::vector2 twoPoints(vector2 p1, vector2 p2);
        static pheng::vector2 fromNormAngle(float norm, float angle);

        float norm() const;
        static float norm(vector2 v);
        static float norm(vector2 v1, vector2 v2);
    };
}

#endif //PHYSICSENGINE_VECTOR2_H
