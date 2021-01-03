class ParkingSystem {
public:
    
    int bigs, mediums, smalls;
    
    ParkingSystem(int big, int medium, int small) {
        bigs = big;
        mediums = medium;
        smalls = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) return --bigs >= 0;
        else if(carType == 2) return --mediums >= 0;
        else return --smalls >= 0;
        return false;
    }
};
​
/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
