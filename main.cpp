//Avleen Gill - 210 lab 27
//std::map code copied from module


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <cstdlib>
using namespace std;

void addV(map<string, tuple<int, string, string>>&);
void deleteV(map<string, tuple<int, string, string>>&);
void output(const map<string, tuple<int, string, string>>&);
void increase(map<string, tuple<int, string, string>>&);
void decrease(map<string, tuple<int, string, string>>&);
void search(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    cout << "-------Villager Map-------\n";
    cout << "\t1. Add Villager\n";
    cout << "\t2. Delete Villager\n";
    cout << "\t3. Increase Friendship\n";
    cout << "\t1. Add Villager\n";
    cout << "\t1. Add Villager\n";



    return 0;
}
void addV(map<string, tuple<int, string, string>>& villagers) {
    string name, species, cphrase;
    int level;
    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship level: ";
    cin >> level; 
    cout << "Species: ";
    cin.ignore();
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, cphrase);

    villagers[name] = make_tuple(level, species, cphrase);
    cout << name << "added.\n";
    output(villagers);
}
void deleteV(map<string, tuple<int, string, string>>& villagers) {
    string name;
    cout << "Enter villager name to delete: ";
    cin >> name;

    if(villagers.erase(name)) { //if this return true/if the name is found and deleted
        cout << name << " deleted.\n";
    }
    else {
        cout << name << " not found.\n";
    }
    output(villagers);
}
void output(const map<string, tuple<int, string, string>>& villagers) {
    cout << "Villager details:\n";
    for (auto i : villagers){
        cout << i.first << " [" << get<0>(i.second) << ", " << get<1>(i.second) << ", " << get<2>(i.second) << "]";
        cout << endl;
    }
}
void increase(map<string, tuple<int, string, string>>& villagers){
    string name;
    cout << "Enter villager name to increase friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        if(get<0>(it->second) < 10){
            get<0>(it->second)++;
        }
        else {
            cout << name << "'s frienship level is already 10.\n";
        }
    }
    else {
        cout << "Villagers not found.\n";
    }

    output(villagers);
}

void decrease(map<string, tuple<int, string, string>>& villagers){
    string name;
    cout << "Enter villager name to decrease friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        if(get<0>(it->second) > 0){
            get<0>(it->second)--;
        }
        else {
            cout << name << "'s frienship level is already 0.\n";
        }
    }
    else {
        cout << "Villagers not found.\n";
    }

    output(villagers);
}
void search(map<string, tuple<int, string, string>>& villagers){
    string name;
    cout << "Villager name to search: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()){
        cout << name << "[ " << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]";
        cout << endl; 
    }
    else {
        cout << "Villagers not found.\n";
    }
}