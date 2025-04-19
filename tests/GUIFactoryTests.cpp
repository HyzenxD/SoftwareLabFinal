#include <gtest/gtest.h>
#include "../GUIFactory.h"

using namespace std;

class GUIFactoryTest : public ::testing::Test {
protected:
    GUIFactory* windowsFactory;
    GUIFactory* linuxFactory;
    
    void SetUp() override {
        windowsFactory = new WindowsGUIFactory();
        linuxFactory = new LinuxGUIFactory();
    }
    
    void TearDown() override {
        delete windowsFactory;
        delete linuxFactory;
    }
};

TEST_F(GUIFactoryTest, WindowsFactoryCreatesWindowsProducts) {
    Window* window = windowsFactory->createWindow();
    Scrollbar* scrollbar = windowsFactory->createScrollbar();
    
    EXPECT_EQ(window->getPlatform(), "Windows");
    EXPECT_EQ(scrollbar->getPlatform(), "Windows");
    
    EXPECT_NE(window->render().find("Windows"), string::npos);
    EXPECT_NE(scrollbar->render().find("Windows"), string::npos);
    
    delete window;
    delete scrollbar;
}

TEST_F(GUIFactoryTest, LinuxFactoryCreatesLinuxProducts) {
    Window* window = linuxFactory->createWindow();
    Scrollbar* scrollbar = linuxFactory->createScrollbar();
    
    EXPECT_EQ(window->getPlatform(), "Linux");
    EXPECT_EQ(scrollbar->getPlatform(), "Linux");
    
    EXPECT_NE(window->render().find("Linux"), string::npos);
    EXPECT_NE(scrollbar->render().find("Linux"), string::npos);
    
    delete window;
    delete scrollbar;
}

TEST_F(GUIFactoryTest, FactoriesCreateDifferentProducts) {
    Window* windowsWindow = windowsFactory->createWindow();
    Window* linuxWindow = linuxFactory->createWindow();
    
    EXPECT_NE(windowsWindow->getPlatform(), linuxWindow->getPlatform());
    EXPECT_NE(windowsWindow->render(), linuxWindow->render());
    
    delete windowsWindow;
    delete linuxWindow;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
