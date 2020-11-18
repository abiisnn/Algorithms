#include<bits/stdc++.h>
using namespace std;

class ValuableObject {
    public:
    string name;
    double size;
    ValuableObject(string name, double size) :name(name), size(size) {}
    ValuableObject() :name(""), size(0.0) {}
    friend bool operator< (const ValuableObject &object1, const ValuableObject &object2);

};
bool operator< (const ValuableObject &object1, const ValuableObject &object2) {
    return object1.name < object2.name;
}
struct ByName {
    ByName(string name): name(name){}
    bool operator()(const ValuableObject & obj) const {
        return obj.name == name;
    }
    private:
    string name;
};
class SecureBox {
    public:
    set<ValuableObject> box;
    SecureBox() {
        this->box = {};
    }
    void add(ValuableObject obj) {
        box.insert(obj);
    }
    ValuableObject remove(string name) {
        set<ValuableObject>::iterator it = find_if(box.begin(), box.end(), ByName(name));
        ValuableObject element = *it;
        box.erase(it);
        return element;
    }
};

int main() {
	ValuableObject mouse("mouse", 5.5);
	ValuableObject computer("computer", 5.0);

	SecureBox safe;
	safe.add(mouse);
	safe.add(computer);

	for(auto &obj: safe.box) {
        cout << obj.name << " with size: " << obj.size << endl;
    }
	safe.remove("computer");
	cout << "------------" << endl;
	for(auto &obj: safe.box) {
        cout << obj.name << " with size: " << obj.size << endl;
    }
}