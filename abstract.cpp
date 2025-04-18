#include <iostream>
#include <memory>
using namespace std;

// Step 1: Abstract Products
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() {}
};

class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() {}
};

// Step 2: Concrete Products for Windows
class WindowsButton : public Button {
public:
    void render() override {
        cout << "Rendering a Windows Button" << endl;
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering a Windows Checkbox" << endl;
    }
};

// Step 3: Concrete Products for Mac
class MacButton : public Button {
public:
    void render() override {
        cout << "Rendering a Mac Button" << endl;
    }
};

class MacCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering a Mac Checkbox" << endl;
    }
};

// Step 4: Abstract Factory
class GUIFactory {
public:
    virtual shared_ptr<Button> createButton() = 0;
    virtual shared_ptr<Checkbox> createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

// Step 5: Concrete Factory for Windows
class WindowsFactory : public GUIFactory {
public:
    shared_ptr<Button> createButton() override {
        return make_shared<WindowsButton>();
    }
    shared_ptr<Checkbox> createCheckbox() override {
        return make_shared<WindowsCheckbox>();
    }
};

// Step 6: Concrete Factory for Mac
class MacFactory : public GUIFactory {
public:
    shared_ptr<Button> createButton() override {
        return make_shared<MacButton>();
    }
    shared_ptr<Checkbox> createCheckbox() override {
        return make_shared<MacCheckbox>();
    }
};

// Step 7: Client Code
void renderUI(shared_ptr<GUIFactory> factory) {
    shared_ptr<Button> btn = factory->createButton();
    shared_ptr<Checkbox> chk = factory->createCheckbox();
    
    btn->render();
    chk->render();
}

int main() {
    cout << "Using Windows Factory:" << endl;
    shared_ptr<GUIFactory> windowsFactory = make_shared<WindowsFactory>();
    renderUI(windowsFactory);

    cout << "\nUsing Mac Factory:" << endl;
    shared_ptr<GUIFactory> macFactory = make_shared<MacFactory>();
    renderUI(macFactory);

    return 0;
}
