#include <iostream>
#include <string>

class Person {
public:
    // Конструктор
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Метод для отображения информации о человеке
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name; // Член данных
    int age; // Член данных
};

class OurDataTypeclass {
    private:
        int number = 10;
        int d_number = 15;
    public:
        OurDataTypeclass() = default;
        //конструктор
        OurDataTypeclass(int value) {
            this->number = value;
        }
        /*OurDataTypeclass(int value)
            :number(value)
            ,d_number(value)
        {}*/
        //конструктор копирования + список инициализации
        OurDataTypeclass(const OurDataTypeclass& other)
            : number(other.number)
        {}
        //деструктор

        ~OurDataTypeclass() = default;
        int addNumber(int new_value) {
            return this->number += new_value;
        }
        //геттер
        int getNumber() {
            return this->number;
        }
        //сеттер
        void setNumber(int new_value) {
            this->number = new_value;
        }
};
struct OurDataType {
    int number = 10;
    int addNumber(int new_value) {
        return this->number += new_value;
    }

};

int main() {
    Person person("Alice", 30);
    person.displayInfo(); // Вывод: Name: Alice, Age: 30
    //std::string ne_name = person.name;
    OurDataType data_type;
    OurDataTypeclass data_typeclass(45);
    std::cout<<data_typeclass.addNumber(18)<<std::endl;
    std::cout << data_type.addNumber(20)<<std::endl;
    std::cout << data_typeclass.getNumber();

    return 0;
}