#include <iostream>

using namespace std;

float readFloat();
bool isTriangle(float edges[3]);
string typeOfTriangle(float edges[3]);

int main() {
    cout << "Ingrese los lados del triangulo:" << endl;
    //string txt;
    //getline(cin, txt);
    float nums[3] = {0};
    for (int i = 0; i < 3; i++) {
        cout << "Number " << i <<":";
        nums[i] = readFloat();
    }
    if (isTriangle(nums))
        cout << "Los numeros forman un triangulo " << typeOfTriangle(nums) << endl;
    else
        cout << "Los numeros no forman un triangulo" << endl;
    return 0;
}

float readFloat() {
    float num;
    string input;
    cin >> num;
    return num;
}

bool isTriangle(float edges[3]) {
    int maxIndex = 0;
    double lengthOfSmallerEdges = 0;
    for (int i = 1; i < 3; i++)
        if (edges[i] > edges[maxIndex])
            maxIndex = i;
    for (int i = 0; i < 3; i++)
        if (i != maxIndex)
            lengthOfSmallerEdges += edges[i];
    return lengthOfSmallerEdges > edges[maxIndex];
}

string typeOfTriangle(float edges[3]) {
    int countOfEqualEdges = 0;
    for (int i = 0; i < 3; i++)
        if (edges[0] == edges[i])
            countOfEqualEdges++;
    if (edges[1] == edges[2])
        countOfEqualEdges++;
    switch (countOfEqualEdges) {
        case 1:
            return "escaleno";
        case 2:
            return "isoceles";
        default:
            return "equilatero";
    }
}