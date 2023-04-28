//
// Created by Russell Ang on 11/4/23.
//
#include <iostream>
#include <sstream>

#include "SimpleBuilder.h"

namespace simple
{
  
  simple::HtmlElement::HtmlElement(const std::string &name, const std::string &text)
  : m_name(name),
    m_text(text)
  {
  
  }
  
  std::string simple::HtmlElement::str(int indent) const
  {
    std::ostringstream output;
    for(const auto& element: m_elements)
    {
      output << element.m_text << "\n";
    }
    
    return output.str();
  }
  
  HtmlBuilder::HtmlBuilder(std::string name)
  {
    root.m_name = name;
  }
  
  void HtmlBuilder::addChild(std::string childName, std::string childText)
  {
    HtmlElement element{childName, childText};
    root.m_elements.emplace_back(element);
  }
  
  std::string HtmlBuilder::str()
  {
    return root.str();
  }
}