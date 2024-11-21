class ParkingSystem {
    int big, medium, small;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1)
        {
            if(!big) return false;
            else{
                big--;
                return true;
            }
        }
        else if(carType == 2)
        {
            if(!medium) return false;
            else{
                medium--;
                return true;
            }
        }
        else{
            if(!small) return false;
            else{
                small--;
                return true;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
