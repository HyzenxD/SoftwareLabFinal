#include "GUIFactory.h"
#include <iostream>

void clientCode(const GUIFactory& factory) {
    Window* window = factory.createWindow();
    Scrollbar* scrollbar = factory.createScrollbar();
    
    cout << "Client: Created " << window->getPlatform() << " GUI elements:" << endl;
    cout << window->render() << endl;
    cout << scrollbar->render() << endl;
    cout << endl;
    
    delete window;
    delete scrollbar;
}

int main() {
    cout << "GUI Abstract Factory Example" << endl;
    cout << "==========================" << endl << endl;
    
    WindowsGUIFactory windowsFactory;
    LinuxGUIFactory linuxFactory;
    
    cout << "Testing Windows GUI Factory:" << endl;
    clientCode(windowsFactory);
    
    cout << "Testing Linux GUI Factory:" << endl;
    clientCode(linuxFactory);
    
    return 0;
}
