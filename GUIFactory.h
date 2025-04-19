#pragma once
#include <string>
#include <iostream>

using namespace std;


class Window {
public:
    virtual ~Window() = default;
    virtual string render() const = 0;
    virtual string getPlatform() const = 0;
};


class Scrollbar {
public:
    virtual ~Scrollbar() = default;
    virtual string render() const = 0;
    virtual string getPlatform() const = 0;
};


class WindowsWindow : public Window {
public:
    string render() const override {
        return "Rendering Windows style window";
    }
    
    string getPlatform() const override {
        return "Windows";
    }
};

class WindowsScrollbar : public Scrollbar {
public:
    string render() const override {
        return "Rendering Windows style scrollbar";
    }
    
    string getPlatform() const override {
        return "Windows";
    }
};


class LinuxWindow : public Window {
public:
    string render() const override {
        return "Rendering Linux style window";
    }
    
    string getPlatform() const override {
        return "Linux";
    }
};

class LinuxScrollbar : public Scrollbar {
public:
    string render() const override {
        return "Rendering Linux style scrollbar";
    }
    
    string getPlatform() const override {
        return "Linux";
    }
};


class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual Window* createWindow() const = 0;
    virtual Scrollbar* createScrollbar() const = 0;
  
    void displayGUI() const {
        Window* window = createWindow();
        Scrollbar* scrollbar = createScrollbar();
        
        cout << "Created " << window->getPlatform() << " GUI:" << endl;
        cout << " - Window: " << window->render() << endl;
        cout << " - Scrollbar: " << scrollbar->render() << endl;
        cout << endl;
        
        delete window;
        delete scrollbar;
    }
};


class WindowsGUIFactory : public GUIFactory {
public:
    Window* createWindow() const override {
        return new WindowsWindow();
    }
    
    Scrollbar* createScrollbar() const override {
        return new WindowsScrollbar();
    }
};


class LinuxGUIFactory : public GUIFactory {
public:
    Window* createWindow() const override {
        return new LinuxWindow();
    }
    
    Scrollbar* createScrollbar() const override {
        return new LinuxScrollbar();
    }
};