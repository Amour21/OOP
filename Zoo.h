#pragma once
#include <iostream>
#include <vector>
#include "Animal.h"  

class Zoo {
private:
    std::vector<Animal*> animals;  
public:
    Zoo () {}
    Zoo(Animal* Arr[], int ArrSize) {
        for (int i = 0; i < ArrSize; i++) {
            animals.push_back(Arr[i]);
        }
    }
    ~Zoo() {
        for (Animal* animal : animals) {
            delete animal;  
        }
    } 
    void ask_for_eating() const {
        std::cout << "\n It's feeding time in the Zoo! \n";
        for (const Animal* animal : animals) {
            animal->print_name();
            std::cout << " says: ";
            animal->say();
            std::cout << std::endl;
        }
    }    void add(Animal* animal) {
        
        if (animal != nullptr) {
            
            animals.push_back(animal);
        }
        else {
            std::cout << "Error: Trying to add a nullptr to the zoo.\n";
        }
    }
    void erase(Animal* animal) {
        std::vector<Animal*>::iterator it = std::find(animals.begin(), animals.end(), animal);
        if (it != animals.end()) {
            delete* it;          
            animals.erase(it);   
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }
    int counting(std::string TypeName) const {
        TypeName[0] = std::tolower(TypeName[0]);
        int count = 0;
        for (const Animal* animal : animals) {
            if (TypeName == "bird" && dynamic_cast <const Bird*> (animal)) {
                count++;
            }
            else if (TypeName == "cat" && dynamic_cast <const Cat*> (animal)) {
                count++;
            }
            else if (TypeName == "dog" && dynamic_cast <const Dog*> (animal)) {
                count++;
            }
            else if (TypeName == "parrot" && dynamic_cast <const Parrot*> (animal)) {
                count++;
            }
            else if (TypeName == "mammal" && dynamic_cast <const Mammal*> (animal)) {
                count++;
            }
            else if (TypeName == "fish" && dynamic_cast <const Fish*> (animal)) {
                count++;
            }
            else if (TypeName == "dragon" && dynamic_cast <const Myth_Dragon*> (animal)) {
                count++;
            }
        }
    return count;
    }
};
