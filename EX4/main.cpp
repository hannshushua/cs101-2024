#include <iostream>
#include <string>
using namespace std;

class Car{
    protected: // 直屬可使用
    string m_DriveMode;

    private:   //私人使用
    int Max_Seating;
    int m_price;
    void m_Updateprice(int base = 500000){
        m_price = Max_Seating * base;
    }

    public:     //公用
    string m_brand;
    string m_model;
    int m_year;
    
    Car(string x, string y, int z, int s){
        m_brand = x;
        m_model = y;
        m_year = z;
        Max_Seating = s;
        m_DriveMode = "No-wheel";  
        m_Updateprice();
    }
    int get_m_MaxSeating(){
        return Max_Seating;
    }
    int getprice(){
        return m_price;
    }
    string get_DriveMode(){
        return m_DriveMode;
    }

};
class BMW : public Car{

    public:
    BMW(string y, int z, int s) : Car("BMW", y, z, s) {
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};
class Audi : public Car{

    public:
    Audi(string y, int z, int s) : Car("Audi", y, z, s) {
        cout << "Constructing Audi_Car\n";
        m_DriveMode = "Front-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};
class BENZ : public Car{
    public:
    BENZ(string y, int z, int s) : Car("BENZ", y, z, s){
        cout << "Construcing BENZ_Car\n";
        m_DriveMode = "Front-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};
int main(){
    
    BMW car_1("X5", 2023, 6);
    cout << car_1.m_brand;
    cout << ": Drive Mode : " << car_1.get_DriveMode() << endl;
    // cout << "Price : " << car_1.getprice() << endl;
    Audi car_2("A1", 2023, 5);  
    cout << car_2.m_brand;
    cout << ": Drive Mode : " << car_2.get_DriveMode() << endl;
    // cout << "Price : " << car_2.getprice() << endl;
    BENZ car_3("C300", 2021, 3);
    cout << car_3.m_brand;
    cout << ": Drive Mode : " << car_3.get_DriveMode() << endl;
    // cout << "Price : " << car_3.getprice() << endl;
}
