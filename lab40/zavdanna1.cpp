#include <iostream>
#include <functional>
#include <string>
using namespace std;

class Notification {
protected:
    string title;
    string text;  

public:
    Notification(const string& title, const string& text)
        : title(title), text(text) {}
    void display() const {
        cout << "[Notification]\nTitle: " << title << "\nText: " << text << "\n";
    }
};
class ImportantNotification : public Notification {
private:
    string importanceLevel;
    function<void()> additionalAction;

public:
    ImportantNotification(const string& title, const string& text, const string& importanceLevel)
        : Notification(title, text), importanceLevel(importanceLevel) {}
    void setAdditionalAction(const function<void()>& action) {
        additionalAction = action;
    }
    void display() const {
        cout << "[Important Notification]\nTitle: " << title << "\nText: " << text
             << "\nImportance Level: " << importanceLevel << "\n";
        if (importanceLevel == "high" && additionalAction) {
            additionalAction(); 
        }
    }
};
int main() {
    ImportantNotification notification("System Update", "A critical update is available.", "high");

    notification.setAdditionalAction([]() {
        cout << "Action Required: Confirmation needed!\n";
    });
    notification.display();

    return 0;
}
