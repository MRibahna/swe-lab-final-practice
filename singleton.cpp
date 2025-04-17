#include <iostream>
using namespace std;

class Singleton {
private:
    // Private static instance
    static Singleton* instance;

    // Private constructor to prevent direct instantiation
    Singleton() {
        cout << "Singleton instance created!" << endl;
    }

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public static method to get the instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Sample method
    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

// Main function to demonstrate usage
int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    Singleton* s2 = Singleton::getInstance();
    s2->showMessage();

    // Verifying both instances are same
    if (s1 == s2)
        cout << "Both instances are the same (Singleton works!) or does it?? bro!!" << endl;
    else
        cout << "Different instances (Singleton failed)." << endl;

    return 0;
}
