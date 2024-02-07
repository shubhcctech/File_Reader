#include "..\headers\Points.h"
Points::Points(){
    
}
Points::Points(double xCoordinate, double yCoordinate, double zCoordinate)
    : mX(xCoordinate), mY(yCoordinate), mZ(zCoordinate) {}

Points::~Points() {}

double Points::X() const {
    return mX;
}

double Points::Y() const {
    return mY;
}

double Points::Z() const {
    return mZ;
}

bool Points::operator<(const Points &pointsOther) const{
    if(mX<pointsOther.mX){
        return true;
    }
    if(mX>pointsOther.mX){
        return false;
    }

    if(mY<pointsOther.mY){
        return true;

    }
    if(mY>pointsOther.mY){
        return false;
    }

    return mZ < pointsOther.mZ;
}
