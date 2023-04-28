//
// Created by Russell Ang on 11/4/23.
//
#include <iostream>

#include "SimpleBuilder.h"

int main()
{
  simple::HtmlBuilder builder("ul");
  builder.addChild("li", "hello");
  std::cout << builder.str() << std::endl;
  return 0;
}