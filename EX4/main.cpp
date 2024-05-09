#include <iostream>
#include <string>
using namespace std;

class Fueltank{

private:
    int m_FueltankCapacity;
    int m_Gas_grade;
public:
    Fueltank(int FueltankCapacity = 3000, int Gas = 98){
        m_Gas_grade = Gas;
        m_FueltankCapacity = FueltankCapacity;
    }
    void fuel_up(int v, int gas){
        if(gas != m_Gas_grade)cout << "Error: Gas_grade : " << gas << " Correct: Gas_grade " << m_Gas_grade << endl;
        if(v > m_FueltankCapacity)cout << "Error: FueltankCapacity : " << m_FueltankCapacity << " but fuel up: " << v << endl;
        cout << "fuel up: " << v << " Gas_grade: " << gas << endl;
    }
    
    int set_Gas_grade(int Gas_grade){
        cout << "Set Gas_grade : " << Gas_grade << endl;
        m_Gas_grade = Gas_grade;
        return m_Gas_grade;
    }
    int get_Gas_grade(){
        return m_Gas_grade;
    }
    
};

class Engine{
    private:
        int m_EngineCapacity;
        int m_Horsepower;
        bool m_EngineRunning;
    public:
        Engine(int EngineCapacity = 2000, int Horsepower = 200){
            m_EngineCapacity = EngineCapacity;
            m_Horsepower = Horsepower;
            m_EngineRunning = false;
        }
        bool EngineStart(){
            m_EngineRunning = true;
            return true;
        }
        bool EngineStop(){
            m_EngineRunning = false;
            return false;
        }
        bool get_EngineStatus(){
            return m_EngineRunning;
        }
};
class Car{
    protected: // 直屬可使用
    string m_DriveMode;
    

    private:   //私人使用
    Engine m_Engine;
    Fueltank m_Fueltank;
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
    bool get_EngineStatus(){
        return m_Engine.get_EngineStatus();
    }
    string get_brand(){
        return m_brand;
    }
    void fuel_up(int v, int gas){
        m_Fueltank.fuel_up(v, gas);
    }
    
    int set_Gas_grade(int Gas_grade){
        return m_Fueltank.set_Gas_grade(Gas_grade);
    }
    int get_Gas_grade(){
        return m_Fueltank.get_Gas_grade();
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
    string get_brand(){
        return m_brand;
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
    string get_brand(){
        return m_brand;
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
    string get_brand(){
        return m_brand;
    }
};
int main(){
    
    Audi car_1("A1", 2021, 2);
    cout << car_1.get_brand() << " : Gas_grade = " << car_1.get_Gas_grade() << endl;
    car_1.set_Gas_grade(95);
    cout << car_1.get_brand() << " : Gas_grade = " << car_1.get_Gas_grade() << endl;
    car_1.fuel_up(30000,99);

}
