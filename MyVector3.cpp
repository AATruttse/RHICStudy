
#include <iostream>
#include "MyVector3.h"


//========================================
cMyVector3::cMyVector3 () : 
fX (0.0), fY (0.0), fZ (0.0) {}

cMyVector3::cMyVector3 (double x_, double y_, double z_) :
fX (x_), fY (y_), fZ (z_) {}

cMyVector3::cMyVector3 (const double *array, int starter) :
fX (array[0 + starter]), fY (array[1 + starter]), fZ (array[2 + starter]) {}

cMyVector3::~cMyVector3() {}

//=========================================

double cMyVector3::operator () (int i) const{
   //dereferencing operator
   switch(i) {
      case 0:
         return fX;
      case 1:
         return fY;
      case 2:
         return fZ;
      default:
         std::cout << "not right i \n";
   }
   return fX;
}

//=========================================
//  function for operation with vectors
									 
cMyVector3 operator + (const cMyVector3 &, const cMyVector3 &); // +

cMyVector3 operator - (const cMyVector3 &, const cMyVector3 &); // +

double operator * (const cMyVector3 &, const cMyVector3 &); // +

cMyVector3 operator * (const cMyVector3 &, double a);  // +

cMyVector3 operator * (double a, const cMyVector3 &); // +

//cMyVector3 operator * (const TMatrix &, const cMyVector3 &);

//---------------------------------------------------------------------------------------------------
//=========================================
 void cMyVector3::SetXYZ (double x_, double y_, double z_) {
   fX = x_;
   fY = y_;
   fZ = z_;
}
//=========================================

 void cMyVector3::SetX (double xx) { fX = xx; }
 void cMyVector3::SetY (double yy) { fY = yy; }
 void cMyVector3::SetZ (double zz) { fZ = zz; }

//=========================================
 cMyVector3 & cMyVector3::operator = (const cMyVector3 & p) {
   fX = p.fX;
   fY = p.fY;
   fZ = p.fZ;
   return *this;
}

//=========================================
inline void cMyVector3::GetXYZ (double *carray, int starter) const {
   carray [0 + starter] = fX;
   carray [1 + starter] = fY;
   carray [2 + starter] = fZ;
}
//---------------------------------------------------------------------------------------------------

//=========================================
inline double cMyVector3::Dot(const cMyVector3 & p) const {
   return fX*p.fX + fY*p.fY + fZ*p.fZ;
}

//=========================================
inline bool cMyVector3::operator == (const cMyVector3& v) const {
   return (v.fX == fX && v.fY == fY && v.fZ == fZ) ? true : false;
}

//=========================================
inline bool cMyVector3::operator != (const cMyVector3& v) const {
   return (v.fX != fX || v.fY != fY || v.fZ != fZ) ? true : false;
}

//=========================================
inline cMyVector3& cMyVector3::operator += (const cMyVector3 & p) {
   fX += p.fX;
   fY += p.fY;
   fZ += p.fZ;
   return *this;
}

//=========================================
inline cMyVector3& cMyVector3::operator -= (const cMyVector3 & p) {
   fX -= p.fX;
   fY -= p.fY;
   fZ -= p.fZ;
   return *this;
}

//=========================================
inline cMyVector3 cMyVector3::operator - () const {
   return cMyVector3(-fX, -fY, -fZ);
}

//=========================================
inline cMyVector3& cMyVector3::operator *= (double a) {
   fX *= a;
   fY *= a;
   fZ *= a;
   return *this;
}

//=========================================
cMyVector3 operator + (const cMyVector3 & a, const cMyVector3 & b) {
   return cMyVector3 (a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}

//=========================================
cMyVector3 operator - (const cMyVector3 & a, const cMyVector3 & b) {
   return cMyVector3 (a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}

//=========================================
cMyVector3 operator * (const cMyVector3 & p, double a) {
   return cMyVector3 (a*p.X(), a*p.Y(), a*p.Z());
}

//=========================================
cMyVector3 operator * (double a, const cMyVector3 & p) {
   return cMyVector3 (a*p.X(), a*p.Y(), a*p.Z());
}

//=========================================
double operator * (const cMyVector3 & a, const cMyVector3 & b) {
   return a.Dot(b);
}

