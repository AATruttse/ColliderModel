#ifndef CVECTOR3_H
#define CVECTOR3_H

class CVector3 {
public:
    double x;
    double y;
    double z;

    CVector3() = default;


    CVector3 &operator = (const CVector3 &v);
    CVector3 &operator * (const double a);
    CVector3 &operator+ (const CVector3 &v){       // ???
        CVector3 a;
        a.x = x + v.x;
        a.y = y + v.y;
        a.z = z + v.z;

        return a;
    }

    void show() const;
};

#endif // CVECTOR3_H
