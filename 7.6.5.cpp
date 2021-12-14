#include <iostream>
using namespace std;

class Vehicle {
    private:
    int power;
  protected:
    int seat;
  public:
    Vehicle (int p) : power(p) {}
    virtual void Show() {
        cout << " power " << power << endl;
    }
};

class Car : public Vehicle {
    public:
    Car(int power, int seat) : Vehicle(power) {
        this->seat = seat;
    }
    void Show() {
        Vehicle::Show();
        cout << " seat " << seat << endl;
    }
};

class Truck : public Vehicle {
    public:
    Truck(int power, int seat) : Vehicle(power) {
        this->seat = seat;
    }
    void Show() {
        cout << " seat " << seat << endl;
    }
};

class Boat : public Vehicle {
    public:
    Boat(int power, int seat) : Vehicle(power) {
        this->seat = seat;
    }
    void Show() {
        cout << " seat " << seat << endl;
    }
};

int main() {
    Car car(100, 5);
    car.Show();
    Vehicle *v = &car;
    v->Show();
}