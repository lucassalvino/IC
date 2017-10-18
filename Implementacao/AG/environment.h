#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
class Environment{
public:
    double getRateChange(){
        return rateChange;
    }

    void setRateChange(double value){
        rateChange = value;
    }

private:
    double  rateChange;
};

#endif // ENVIRONMENT_H
