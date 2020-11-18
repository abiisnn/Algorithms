#include<bits/stdc++.h>
using namespace std;

class Valuable {
public:
	string name;
	double volume;
	Valuable(string name, double volume) {
		this->name = name;
		this->volume = volume;
	}
};

class SafeBox {
public:
	vector<Valuable> box;

	SafeBox() {
		this->box = {};
	}
	void add(Valuable object) {
		box.push_back(object);
	}
	Valuable remove(string name) {
		Valuable object("", 0.0);
		std::vector<Valuable>::iterator it;

		for(it = box.begin(); it != box.end(); it++) {
			Valuable temp = *it;
			if(temp.name == name) {
				object = temp;
				box.erase(it);
				break; 
			}
		}
		return object;
	}
};

int main() {
	Valuable mouse("mouse", 5.5);
	Valuable computer("computer", 5.0);

	SafeBox safe;;
	safe.add(mouse);
	safe.add(computer);

	for(int i = 0; i < safe.box.size(); i++) {
		cout << safe.box[i].name << " " << safe.box[i].volume << endl;
	}
	safe.remove("computer");
	cout << "------------" << endl;
	for(int i = 0; i < safe.box.size(); i++) {
		cout << safe.box[i].name << " " << safe.box[i].volume << endl;
	}
}