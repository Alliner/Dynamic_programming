#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;

int main() {

    unordered_map<string, unordered_map<int, int>>tableCost;
    tableCost.insert({ "Water", {{ 3,10 }} });
    tableCost.insert({ "Book", {{ 1,3 } } });
    tableCost.insert({ "Food", {{ 2,9 } } });
    tableCost.insert({ "Cloth", {{ 2,5 } } });
    tableCost.insert({ "Camera", {{ 1,6 } } });

    const int maxBag = 6;

    int** resTable = new int* [tableCost.size()];
    for (int i = 0; i < tableCost.size(); i++) resTable[i] = new int[maxBag];


    for (int i = 0; i < tableCost.size(); i++)
        for (int j = 0; j < maxBag; j++) resTable[i][j] = 0;
    


    int i = 0;
    cout << "------------------------------------------------------------\n";
    cout << "|\t|  1\t   2\t   3\t   4\t   5\t   6\t   |\n";
    cout << "|-------|--------------------------------------------------|\n";
    for (const auto& n : tableCost) {
        cout <<"|"<< n.first << "\t|  ";

        for (const auto& k : n.second) {
            for (int j = 0; j < maxBag; j++) {
                if (i == 0) if (k.first <= (j + 1)) resTable[i][j] = k.second; 
                if (i > 0) {
                    resTable[i][j] = resTable[i - 1][j];
                    if (k.first == (j + 1)) if (k.second > resTable[i][j]) resTable[i][j] = k.second;
                    if (k.first < (j + 1)) if ((k.second+resTable[i-1][j-k.first]) > resTable[i][j]) resTable[i][j] = k.second+ resTable[i - 1][j-k.first];
                }
                cout << resTable[i][j] << "\t   ";
            }

        }
        i++;
        cout << "|\n|-------|--------------------------------------------------|\n";
    }

    

}