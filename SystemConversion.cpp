#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include "convert.h"
#include <cmath>
#include <type_traits>

using namespace std;
using namespace std::chrono;

//Finds persistance of a decimal number
int numPersistant(unsigned long long int n){
        unsigned long long int nTemp = 1;
        string nSub = "";
        string nStr = "";
        int pCount = 0;
        bool isZero = false;

        while (n > 9){
            nStr = to_string(n);
            for (int i = 0; i < nStr.length(); i++){
                nSub = nStr.substr(i, 1);

                if (nSub == "0"){
                    pCount += 1;
                    isZero = true;
                    break;
                }
                else{
                    nTemp *= stoi(nSub);
                }
            }
            if (isZero == true){
                break;
            }
            else{
                pCount += 1;
            }
            n = nTemp;
            nTemp = 1;
        }

        return pCount;
    }

/*Finds smallest multiplicative persistent value in decimal and then prints base-10
 and user defined base equivalent of the result. This all done up to the max range 
 defined by the user.
*/
void performCalculations(int input, int base){
    //Variables
    char temp[100];
    int p;
    int stepper = 0;
    //int increment = 1;
    string mainSubTest = "";
    string mainStrTest = "";
    string sortStr;
    unsigned long long int myList[15];
    string resultList[15];
    unsigned long long int i = 0;

    auto s1 = high_resolution_clock::now(); //START CLOCK

    cout << endl << endl << "BASE-10" << "\t\t\t" << "BASE-" + to_string(base) << endl; //Table Title
    cout << "-------------------------------" << endl; //Table Divider
    

    while (i < input + 1){
        mainStrTest = to_string(i);
        if (mainStrTest.length() >= 3){
            mainSubTest = mainStrTest.substr(2, 1);
        }

        if (mainSubTest == "7" || mainSubTest == "8" || mainSubTest == "9" || mainStrTest.length() < 3){
            p = numPersistant(i);
            if (p == stepper){
                myList[stepper] = i;
                resultList[stepper] = from_deci(temp, i, base);
                i = myList[stepper] + pow(stepper, stepper);

                cout << myList[stepper] << "\t\t\t" << resultList[stepper] << endl;
                stepper++;
            }
        }
        i++;
    }
    cout << "-------------------------------" << endl << endl;

    auto e1 = high_resolution_clock::now(); //END CLOCK
    auto d1 = duration_cast<milliseconds>(e1 - s1); //FIND CLOCK DIFF.

    cout << d1.count() << "ms" << endl; //PRINT CLOCK DIFF.
    if(d1.count()<10){
        cout<<input<<" is not a vaild input"<<endl;
    }
}

int main(){
    long long int input;
    // string base;
    int base;
    //Take User input
    cout << "Enter Max Search Range: "; cin >> input;
    if(input > 1*pow(10,15)){
        cout<<"Input range will take too long, give a smaller range"<<endl;
        cout << "Enter Max Search Range: "; cin >> input;}
        
    cout << "Enter Number Base for Results: "; cin >> base;
    // if (base == "hex"){
    //     base = 6;}
    //base = stoi(base);
    if(base >= 20){
        cout<<"Base too large, input a smaller base"<<endl;
        cout << "Enter Number Base for Results: "; cin >> base;}
        
    performCalculations(input, base); //Performs Calculations

    return 0;
}