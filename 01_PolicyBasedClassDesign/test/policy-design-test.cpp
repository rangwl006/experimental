#include <iostream>
#include <memory>

#include "CreatorPolicies.h"
#include "SmartPtr.h"

using namespace design;

// typedef user::GenericManager< policy::MallocCreator< custom_objects::Widget > > CustomWidgetMgr; // C style
// typedef user::WidgetManager<policy::MallocCreator> WidgetMgr; // C style

int main()
{
    std::cout << "###### START PolicyDesignTestProgram ######" << std::endl;


    // using CustomWidgetMgr = client::GenericManager< policy::MallocCreator< custom_objects::Widget > >; // modern cxx
    // CustomWidgetMgr wm;
    // std::unique_ptr<custom_objects::Widget> widgetPtr = std::make_unique<custom_objects::Widget>();

    // using WidgetMgr = client::WidgetManager<policy::MallocCreator>; // modern cxx
    // WidgetMgr wm2;
    // std::unique_ptr<custom_objects::Widget> widgetPtr2(wm2.Create());

    // using WidgetPrototypeMgr = client::WidgetManager<policy::PrototypeCreator>;
    // std::unique_ptr<custom_objects::Widget> wPtr = std::make_unique<custom_objects::Widget>();
    // WidgetPrototypeMgr wm3;
    // wm3.SetPrototype(wPtr.release());
    // std::unique_ptr<custom_objects::Widget> wPtr2 = std::make_unique<custom_objects::Widget>();
    // wm3.SwitchPrototype(wPtr2.release());

    using WidgetSmartPointer = design::custom_objects::SmartPtr<custom_objects::Widget, design::policy::EnforceNotNull>;
    WidgetSmartPointer invalidPtr(nullptr);
    try
    {
        invalidPtr.Check(nullptr);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "###### END PolicyDesignTestProgram ######" << std::endl;
    return 0;
}