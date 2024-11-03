//Avleen Gill - 210 lab 27
//std::map code copied from module


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <cstdlib>
using namespace std;


int main() {
    srand(time(0));
    int randlevel = rand() % 11;
    // declarations
    map<string, tuple<int, string, string>> villagers;

    tuple<int, string, string> v1(randlevel, "horse", "NEIGH");
    tuple<int, string, string> v2(randlevel, "dog", "barkbark");
    tuple<int, string, string> v3(randlevel, "cat", "meoww");
    tuple<int, string, string> v4(randlevel, "lizard", "Geico gets you 50 percent off car insurance");
    tuple<int, string, string> v5(randlevel, "crow", "I will steal your sandwich and poop on your car");
    tuple<int, string, string> v6(randlevel, "cow", "Please don't turn me into steak.");

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {"Orange", "Yellow", "Red"};
    villagers["Raymond"] = {"Black", "Gray", "White"};
    villagers.insert({"Marshal", v1});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
