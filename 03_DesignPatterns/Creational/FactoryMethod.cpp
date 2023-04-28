//
// Created by Russell Ang on 28/4/23.
//
#include <iostream>

#include "FactoryMethod.h"

void creational::Rectangle::draw()
{
  std::cout << "Rectangle::draw()" << std::endl;
}

double creational::Rectangle::calculateArea()
{
  auto area = m_breadth * m_length;
  std::cout << "Area: " << area << std::endl;
  return area;
}

void creational::Circle::draw()
{
  std::cout << "Circle::draw()" << std::endl;
}

double creational::Circle::calculateArea()
{
  auto&& area = m_radius * 3.14;
  std::cout << "Area: " << area << std::endl;
  return area;
}

std::unique_ptr<creational::Shape> creational::RectangleFactory::Create()
{
  return std::make_unique<creational::Rectangle>();
}

std::unique_ptr<creational::Shape> creational::CircleFactory::Create()
{
  return std::make_unique<creational::Circle>();
}
