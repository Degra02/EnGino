#ifndef PHYSICSENGINE_VECTOR2_H
#define PHYSICSENGINE_VECTOR2_H

namespace phy_eng{

    class vector2 {
        float x;
        float y;

    public:
        vector2();
        vector2(float x, float y);

        void setX(float);
        void setY(float);
        float getX();
        float getY();

        vector2 operator +(vector2 v2); // algebraic sum
        vector2 operator -(vector2 v2);
        void operator +=(vector2 v2);
        vector2 operator *(float m);
        vector2 operator /(float m);

        static float norm(vector2 v);
        static float norm(vector2 v1, vector2 v2);
    };
}

#endif //PHYSICSENGINE_VECTOR2_H
