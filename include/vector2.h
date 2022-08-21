#ifndef PHYSICSENGINE_VECTOR2_H
#define PHYSICSENGINE_VECTOR2_H

namespace phy_eng{

    class vector2 {
        float x;
        float y;

    public:
        vector2();
        vector2(float x, float y);

        vector2 operator +(vector2 v2); // algebraic sum
        vector2 operator -(vector2 v2);
        vector2 operator +=(vector2 v2) const;
        vector2 operator *(float m);
        vector2 operator /(float m);

        static float norm(vector2 v);
    };
}

#endif //PHYSICSENGINE_VECTOR2_H
