//
// Created by Russell Ang on 28/4/23.
//

#pragma once

#include <memory>

namespace creational
{
  class Shape
  {
    public:
      Shape() = default;
      virtual ~Shape(){};
      
      virtual void draw() = 0;
      virtual double calculateArea() = 0;
  };
  
  class Rectangle : public Shape
  {
    public:
      Rectangle() = default;
    
      ~Rectangle() = default;
    
      void draw() override;
    
      double calculateArea();
  
    private:
      double m_length { 10 };
      double m_breadth { 20 };
  };
  
  class Circle : public Shape
  {
    public:
      Circle() = default;
      ~Circle() = default;

      void draw() override;

      double calculateArea();

    private:
      double m_radius { 10 };
  };
  

  class ShapeFactory
  {
    public:
      virtual ~ShapeFactory(){};
      
      virtual std::unique_ptr<Shape> Create() = 0;
  };
  
  class RectangleFactory : public ShapeFactory
  {
    public:
      RectangleFactory() = default;
      ~RectangleFactory() = default;
      
      std::unique_ptr<Shape> Create();
  };
  
  class CircleFactory : public ShapeFactory
  {
    public:
      CircleFactory() = default;
      ~CircleFactory(){};
      
      std::unique_ptr<Shape> Create();
  };
}
