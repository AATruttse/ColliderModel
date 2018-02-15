#ifndef CCOLLIDER_H
#define CCOLLIDER_H

using namespace std;

class CCollider {
private:
    double t;

    CCollider() = default;
    CCollider(const CCollider&);
    CCollider &operator = ( CCollider& );
public:
    static CCollider &getInstance() {
        static CCollider  instance;
        return instance;
    }

    double get_t() const;                   // returns t
    void Lstep(const double dt);            // changes t to t + dt
};
#endif // CCOLLIDER_H
