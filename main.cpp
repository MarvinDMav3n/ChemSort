// ChemSort

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "elements.h"

using namespace std;

struct Element
{
    string name;
    string symbol;
    int atomicNumber;  
    float atomicMass;
    string group;
    int periodNum;
};

vector<Element> readElementsFromCSV(const string& filename) {
    vector<Element> elements;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return elements;
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string name, symbol, group, atomicNumberStr, atomicMassStr;

        getline(ss, name, ',');
        getline(ss, symbol, ',');
        getline(ss, atomicNumberStr, ',');
        getline(ss, atomicMassStr, ',');
        getline(ss, group, ',');

        Element elem;
        elem.name = name;
        elem.symbol = symbol;
        elem.atomicNumber = stoi(atomicNumberStr);
        elem.atomicMass = stof(atomicMassStr);
        elem.group = group;

        elements.push_back(elem);
    }

    file.close();
    return elements;
}

int main()
{ 
  vector<Element> elements = readElementsFromCSV("elements.csv");

  if (elements.empty()) {
      cout << "No elements loaded." << endl;
      return 1;
  }

  string searchName;
  
  cout << "ChemSort © 2025 Maven Builds";

  cout << "Search with ChemSort! \n\n";

  cout << "Search: ";
  getline(cin, searchName);

  bool found = false;

  for (const Element& elem: elements)
    {
      if (elem.name == searchName)
      {
        cout << "\nFound element!\n\n";
        cout << "Name: " << elem.name << "\n";
        cout << "Symbol: " << elem.symbol << "\n";
        cout << "Atomic Number: " << elem.atomicNumber << "\n";
        cout << "Atomic Mass: " << elem.atomicMass << "\n";
        cout << "Group: " << elem.group << "\n";
        cout << "Period Number: " << elem.periodNum << "\n\n";
        found = true;
        break;
      }
    }

  if (!found)
  {
    cout << "No element found with that name. Try again?";
  }
  
  return 0;
}
