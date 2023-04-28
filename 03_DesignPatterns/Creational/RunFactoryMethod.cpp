//
// Created by Russell Ang on 28/4/23.
//

#include <iostream>
#include <memory>
#include "FactoryMethod.h"

int main()
{
  std::unique_ptr<creational::ShapeFactory> shapeFactory = std::make_unique<creational::RectangleFactory>();
  shapeFactory = std::make_unique<creational::CircleFactory>();
  std::unique_ptr<creational::Shape> cir(shapeFactory->Create());
  cir->draw();
  std::cout << "RunFactoryMethod Start" << std::endl;
  return 0;
}