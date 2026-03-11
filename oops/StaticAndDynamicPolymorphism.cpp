#include<iostream>
using namespace std;

class car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currSpeed;

    public:

        car(string b, string m)
        {
            this->brand=b;
            this->model=m;
            isEngineOn=false;
            currSpeed=0;
        }
        void startEngine()
        {
            if(isEngineOn)
            {
                cout << "engine is already on" << endl;
            }
            else
            {
                isEngineOn =true;
                cout << "engine started" << endl;
            }
            
        }

        void stopEngine()
        {
            if(isEngineOn)
            {
                isEngineOn=false;
                 currSpeed=0;
                cout << "engine is off" << endl;
            }
            else
            {
                cout << "engine already off" << endl;
            }
        }
        virtual void accelerate();

        virtual void accelerate(int  currSpeed);

        virtual void brake();

        virtual ~car() {};

};

// Definitions for virtual methods to ensure vtable is emitted
void car::accelerate() {
    // base implementation (could be empty or a diagnostic)
}

void car::accelerate(int currSpeed) {
    // base implementation
}

void car::brake() {
    // base implementation
}


class ManualCar : public car
{
    private:
        int currentGear;

    public:
        ManualCar(string brand, string model) : car(brand, model)
        {
            currentGear=0;
        }

    void changeGear(int gear)
    {
        currentGear=gear;
        cout << brand << " " << model << " " << "gear changed to " << currentGear << endl;
    }

    void accelerate()
    {
        if(!isEngineOn)
        {
            cout << "engine is off" << endl;
            return;
        }

        currSpeed+=20;
        cout << "speed increased by 20" << endl;
    }

    void accelerate(int speed)
    {
        if(!isEngineOn)
        {
            cout << "engine is off" << endl;
            return;
        }

        currSpeed+=speed;
        cout << "speed increased by " << speed << endl;
    }

    void brake()
    {
        if(!isEngineOn)
        {
            cout << "engine is already off" << endl;
            return;
        }
        currSpeed-=20;
        cout << "brakes applied " << endl;
    }

};

class ElectricCar : public car
{
    private:
        int battery;

    public:
        ElectricCar(string brand, string model)  : car(brand, model)
        {
            battery=100;
        }

    void chargeBattery()
    {
        if(battery==100)
        {
            cout << "already charged" << endl;
            return;
        }
        battery=100;
        cout << "charged to 100 " << endl;
    }

   void accelerate()
    {
        if(!isEngineOn)
        {
            cout << "engine is off" << endl;
            return;
        }
        
        if(battery==0)
        {
            cout << "please charge first" << endl;
            return;
        }

        currSpeed+=20;
        cout << "speed increased by 20" << endl;
    }

    void accelerate(int speed)
    {
        if(!isEngineOn)
        {
            cout << "engine is off" << endl;
            return;
        }

        if(battery==0)
        {
            cout << "please charge first" << endl;
            return;
        }

        currSpeed+=speed;
        cout << "speed increased by " << speed << endl;
    }

    void brake()
    {
        if(!isEngineOn)
        {
            cout << "engine is already off" << endl;
            return;
        }

        if(battery==0)
        {
            cout << "please charge first " << endl;
            return;
        }

        currSpeed-=20;
        if(currSpeed<0)
        {
            currSpeed=0;
        }
        cout << "brakes applied " << endl;
    }

};

int main()
{
    ManualCar* manualCar = new ManualCar("Audi" , "DJ");

    manualCar->startEngine();
    manualCar->brake();
    manualCar->changeGear(3);
    manualCar->accelerate();
    manualCar->accelerate(40);
    manualCar->stopEngine();


    ElectricCar* electricCar = new ElectricCar("Tesla" , "MJ");

    electricCar->startEngine();
    electricCar->chargeBattery();
    electricCar->accelerate();
    electricCar->accelerate(40);
    electricCar->brake();
    electricCar->stopEngine();

};
 

    


