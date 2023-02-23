#include <iostream>
#include <memory>

#include "PolicyDesign.h"

using namespace design;

typedef user::GenericManager< policy::MallocCreator< custom_objects::Widget > > CustomWidgetMgr;
typedef user::WidgetManager<policy::MallocCreator> WidgetMgr;

int main()
{
    std::cout << "###### START ######" << std::endl;

    CustomWidgetMgr wm;
    std::unique_ptr<custom_objects::Widget> widgetPtr = std::make_unique<custom_objects::Widget>();
    WidgetMgr wm2;
    std::unique_ptr<custom_objects::Widget> widgetPtr2(wm2.Create());
    std::cout << "###### END ######" << std::endl;
    return 0;
}