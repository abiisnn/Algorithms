
typedef long double ld;
const ld eps = 1e-9;
bool eq(ld a, ld b) {return abs(a-b) < eps;} // a == b
bool geq(ld a, ld b) {return (a-b) >= -eps;} // a >= b
bool leq(ld a, ld b) {return (a-b) <= eps;} // a <= b
bool gr(ld a, ld b) {return (a-b) > eps;} // a > b
bool le(ld a, ld b) {return (a-b) < -eps;} // a < b
bool noteq(ld a, ld b) {return abs(a-b) > eps;} // a != b
