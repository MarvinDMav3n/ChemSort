// ChemSort

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Store details of each element

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

string toLower(const string &s)
{
    string result = s; 
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main()
{
    cout << "ChemSort © 2025 Maven Builds \n\n";

    // Read CSV file

    vector<Element> elements;
    ifstream file("elements.csv");

    // Check if file opened successfully

    if (!file.is_open())
    {
        cerr << "Error opening file... \n";
        return 1;
    }

    // Read file line by line

    string line;

    // Skip header line

    while (getline(file, line))
    {

        // Skip empty lines
        stringstream ss(line);
        string field;

        // Check if line is empty
        int atomicNum;
        string symbol, name, category;
        float atomicMass;

        // Read each field
        getline(ss, field, ',');
        atomicNum = stoi(field);

        // Read symbol and name
        getline(ss, symbol, ',');
        getline(ss, name, ',');

        // Read atomic mass
        getline(ss, field, ',');  
        atomicMass = stof(field);

        // Read category
        getline(ss, category, ',');

        elements.emplace_back(atomicNum, symbol, name, atomicMass, category);
    }

    file.close();

    string query;

    cout << "Search?";
    getline(cin, query);

    query = toLower(query);

    for (const auto& element : elements)
        {
            if (toLower(element.name).find(query) != string::npos || toLower(element.symbol).find(query) != string::npos) || toLower(element.category).find(query) != string::npos) || to_string(element.atomicNum).find(query) != string::npos) || toLower(element.atomicMass).find(query) != string::npos) || toLower(element.category).find(query) != string::npos) 
        }

    return 0;
}
