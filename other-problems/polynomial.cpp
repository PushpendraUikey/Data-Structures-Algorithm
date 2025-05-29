#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

// Implementation of polynomial class

class Polynomial {
    void update(int s){
        int newsize = this->size + s;
        int* coeff = new int[s];
        for(int i=0; i<this->size; i++){
            coeff[i] = this->degCoeff[i];
        }
        this->size = newsize;
        this->degCoeff = coeff;
        coeff = nullptr;
    }
    public:
    int * degCoeff; // Name of your array (Don't change this)
    int size;

    Polynomial(){
        size = 100;
        this->degCoeff = new int[size];
    };
    void setCoefficient(int degree, int coeff){

        for(int i=0; i<this->size; ++i){
            if(degree>this->size){
                update(degree);
            }
            degCoeff[degree] = coeff;
        }
    }

    Polynomial(const Polynomial& second){
        int size = second.size;
        int *newpoly = new int[size];
        int j = 0;
        while(j<second.size){
            newpoly[j] = second.degCoeff[j];
            j++;
        }

        this->degCoeff = newpoly;
        this->size = size;

        newpoly=nullptr;
    }

    Polynomial operator+(const Polynomial &second) {
        int size = second.size;
        size = std::max(size, this->size);

        int *newpoly = new int[size];
        int i = 0, j = 0;
        while(i<this->size || j<second.size){
            newpoly[i] = this->degCoeff[i] + second.degCoeff[i];
            i++; j++;
        }
        while(i<this->size){
            newpoly[i] = this->degCoeff[i];
            i++;
        }
        while(j<second.size){
            newpoly[j] = this->degCoeff[j];
            j++;
        }

        this->degCoeff = newpoly;
        this->size = size;

        newpoly = nullptr;
        return *this;
    }

    Polynomial operator-(const Polynomial &second) {
        int size = second.size;
        size = std::max(size, this->size);

        int *newpoly = new int[size];
        int i = 0, j = 0;
        while(i<this->size || j<second.size){
            newpoly[i] = this->degCoeff[i] - second.degCoeff[i];
            i++; j++;
        }
        while(i<this->size){
            newpoly[i] = this->degCoeff[i];
            i++;
        }
        while(j<second.size){
            newpoly[j] = -1*this->degCoeff[j];
            j++;
        }

        this->degCoeff = newpoly;
        this->size = size;

        newpoly = nullptr;
        return *this;
    }
    

    Polynomial operator*(const Polynomial &second) {
        int size = second.size;
        size += this->size;

        int *newpoly = new int[size];
        for(int i=0; i<second.size; i++){
            for(int j=i+1; j<this->size; j++){
                newpoly[i+j] = 0;
            }
        }
        for(int i=0; i<second.size; i++){
            for(int j=0; j<this->size; j++){
                newpoly[i+j] += (this->degCoeff[j]*second.degCoeff[i]);
            }
        }

        this->degCoeff = newpoly;
        this->size = size;

        newpoly = nullptr;
        return *this;
    }

    Polynomial operator=(const Polynomial &second) {
        int size = second.size;
        int *newpoly = new int[size];
        int j = 0;
        while(j<second.size){
            newpoly[j] = second.degCoeff[j];
            j++;
        }

        this->degCoeff = newpoly;
        this->size = size;

        newpoly = nullptr;
        return *this;
    }

    void print(){
        for(int i=0; i<this->size; i++){
            if(this->degCoeff[i] != 0){
                std::cout << degCoeff[i] << 'x' << i << ' ';
            }
        }
        std::cout << endl;
    }
};

int main() {
    int count1, count2, choice;
    cin >> count1;

    int * degree1 = new int[count1];
    int * coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int * degree2 = new int[count2];
    int * coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice) {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    }

    return 0;
}