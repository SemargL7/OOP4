/*Створити базовий клас УПАКУВАННЯ ДЛЯ ЛІКІВ (задаються назва, розмір упакування (ширина, довжина, висота).
Створити похідний клас УПАКУВАННЯ ДЛЯ ЛІКІВ У ТАБЛЕТКАХ (задається вага таблеток з упакуванням).
Для введених даних про різні ліки, наявні в аптеці,
обчислити їх сумарну вагу та сумарний об’єм і визначити чи можна розмістити ці ліки у певній тарі із заданою максимально можливою вагою.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int n;

class PFM {
private:
    char name[30];
    int size;
public:
    PFM() {}
    PFM(char n[], int size) { strcpy(name, n); this->size = size; }
    ~PFM() {}

    void SetName(char a[30]) { strcpy(name, a); }
    void SetSize(int a) { size = a; }

    string GetName() { return name; }
    int GetSize() { return size; }
};

class PFM_T : public PFM {
private:
    int weight;
public:
    PFM_T() :PFM() {}
    PFM_T(char n[], int s, int w) :PFM(n,s), weight(w){}
    ~PFM_T() {}

    void SetWeight(int a) { weight = a; }

    int GetWeight() { return weight; }
};

int sum_weight(PFM_T a[]) {
    int sum_w = 0;
    for (int i = 0; i < n; i++) {
        sum_w += a[i].GetWeight();
    }
    return sum_w;
}

int sum_volume(PFM_T a[]) {
    int sum_v = 0;
    for (int i = 0; i < n; i++) {
        sum_v += a[i].GetSize();
    }
    return sum_v;
}

int volume(char a[]) {
    int b = 0;
    int l = 0, w = 0, h = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != 'x') {
            switch(b){
            case 0: l = l * 10 +(a[i] - '0'); break;
            case 1: w = w * 10 + (a[i] - '0'); break;
            case 2: h = h * 10 + (a[i] - '0'); break;
            }
        }
        else
            b++;
    }
    return l * w * h;
}

void Input(PFM_T *ex) {
    cout << "Name: ";
    char a[30];
    scanf("%s", &a);
    getchar; getchar;

    cout << "Size(example: \"10x10x10\" in mm): ";
    char b[30];
    scanf("%s", &b);
    getchar; getchar;

    int c;
    cout << "Weight(in grams): ";
    cin >> c;

    ex->SetName(a);

    ex->SetSize(volume(b));

    ex->SetWeight(c);
    cout << "\n";
}

int main(){
    cout << "How many drugs is in batch?" << endl;
    cin >> n;
    PFM_T* batch_of_drugs = new PFM_T[n];
    for (int i = 0; i < n; i++) {
        Input(&batch_of_drugs[i]);
    }
    int tara;
    cout << "Tara max find out the weight: ";
    cin >> tara;
    sum_weight(batch_of_drugs) <= tara 
        ? cout << "Weight of batch of drugs " << sum_weight(batch_of_drugs)<< " grams" << endl 
        : cout << "You can`t find out the weight" << endl;
    cout << "volume of batch " << sum_volume(batch_of_drugs) << " mm^3" << endl;
}