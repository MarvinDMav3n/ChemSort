// ChemSort

#include <iostream>
#include <string>

using namespace std;

struct Element
{
  int atomicNum;
  string symbol;
  string name;
  float atomicMass;
  string category;
  
  Element(int num, string sym, string element, float mass, string cat)
      : atomicNum(num), symbol(sym), name(element), atomicMass(mass), category(cat) {}
};

int main()
{
  cout << "ChemSort © 2025 Maven Builds \n";
  cout << "\n";
  
  Element hydrogen(1, "H", "Hydrogen", 1, "Non-metals");
  Element helium(2, "He", "Helium", 4, "Alkaline Earth Metals");
  Element oxygen(8, "O", "Oxygen", 15.999, "Reactive Non-Metals");
  
  cout << "Three Elements So Far In Development, Namely: \n";
  cout << "\n";
  cout << "Hydrogen: " << hydrogen.symbol << ", " << hydrogen.category << "\n";
  cout << "Helium: " << helium.symbol << ", " << helium.category << "\n";
  cout << "Oxygen: " << oxygen.symbol << ", " << oxygen.category << "\n";
  
  return 0;
}
