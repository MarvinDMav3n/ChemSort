// ChemSort

#include <iostream>
#include <string>
#include <vector>

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

int main()
{
  vector<Element> elements = {
    {"Hydrogen", "H", 1, 1.008, "Nonmetal", 1},
    {"Helium", "He", 2, 4.0026, "Noble Gas", 1},
    {"Lithium", "Li", 3, 6.94, "Alkali Metal", 2},
    {"Oxygen", "O", 8, 15.999, "Nonmetal", 2} 
  }; 

  for (const Element& elem: elements)
    {
      cout << elem.name << " " << elem.symbol << " " << elem.atomicNumber << " " << elem.atomicMass << " " << elem.group << " " << elem.periodNum << endl;
    }
  
  return 0;
}
