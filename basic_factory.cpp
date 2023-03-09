#include <iostream>
#include <memory>

/**
 * Factory design pattern
 */

class LandVehicle
{
  public:
    virtual ~LandVehicle() {};
    virtual void drive() = 0;

  protected:
    int speed = 0;
    int tachometer = 0;
};

class Car : public LandVehicle
{
  public:
    Car() { std::cout << "Car object created. (" << this << ")" << std::endl; };
    virtual ~Car() { std::cout << "Car object destroyed. (" << this << ")" << std::endl; };

    void drive() override { speed += 2; std::cout << "Invoked Car::drive()" << std::endl; };
};

class Truck : public LandVehicle
{
  public:
    Truck() { std::cout << "Truck object created. (" << this << ")" << std::endl; };
    virtual ~Truck() { std::cout << "Truck object destroyed. (" << this << ")" << std::endl; };

    void drive() override { speed += 1; std::cout << "Invoked Truck::drive()" << std::endl; };
};

class LandVehicleFactory
{
  public:
    virtual LandVehicle* CreateVehicle() = 0;
};

class CarFactory : public LandVehicleFactory
{
  public:
    CarFactory() { std::cout << "Created CarFactory (" << this << ")" << std::endl; };
    virtual LandVehicle* CreateVehicle()
    {
      return new Car;
    };
};

int main()
{
  std::unique_ptr<LandVehicleFactory> carFactory = std::make_unique<CarFactory>();
  auto car = carFactory->CreateVehicle();
  car->drive();
  delete car;
  return 0;
};
