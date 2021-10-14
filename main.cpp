#include <iostream>
#include "vector.h"
using namespace std;
int main() {
    vector <int> vendetta(3);
    cin>>vendetta;
    cout<<vendetta<<endl;
    vendetta.push_back(13);
    cout<<vendetta<<endl;
    cout<<vendetta.at(3)<<endl;
    vendetta.insert(2,15);
    cout<<vendetta<<endl;
    vendetta.erase(1);
    cout<<vendetta<<endl;
    return 0;
}
