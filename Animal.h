
#pragma once
#include <iostream>
#include <string>

struct RGB {
	int r, g, b;
};
class Animal {
protected:
	std::string name;
	int age;
	RGB color;
public:
	Animal(std::string name, int age = 0, RGB color = { 0,0,0 }) {
		this->name = name;
		this->age = age;
		this->color = color;
	}
	virtual ~Animal() {}

	void set_age(int age) {
		this->age = age;
	}
	void set_color(RGB color) {
		this->color = color;
	}
	void grow() {}
	void eat() {
		std::cout << "eating\n";
	}
	virtual void say() const  {}
	
	void print_stat() {
		std::cout << name << '\n';
		std::cout << "Color: (" << color.r << ", " << color.g << ", " << color.b << ")\n";
	}
	void print_name()  {
		std::cout << name;
	}
	void print_name() const {
		std::cout << name;
	}
};
class Fish :public Animal {

public:
	Fish(std::string name) : Animal(name) {}
	void say() {}
	void swim() {
		std::cout << this->name << "swimming\n";
	}
};
class Mammal :public Animal {
public:
	Mammal(std::string name) : Animal(name) {}
	void run() {
		std::cout << this->name << " is running\n";
	}
};
class Dog :public Mammal {
public:
	Dog(std::string name) : Mammal(name) {}
	void complite_command(std::string command) {
		std::cout << this->name << " perfoms " << command << '\n';
	}
	void say() const override {
		std::cout << "Woof!\n";
	}
	void catch_stick() {
		std::cout << this->name << " is catching a stick \n";
	}
};
class Cat :public Mammal {

public:
	Cat(std::string name) : Mammal(name) {}
	void catch_mouse() {
		std::cout << this->name << " is cathing mouse\n";
	}
	void say() const override {
		std::cout << "Meow\n";
	}
};

class Bird :public Animal {
public:
	Bird(std::string name) : Animal(name) {}
	void fly() {
		std::cout << this->name << " is flying\n";
	}
};
class Parrot :public Bird {
	std::string phrase;
public:
	Parrot(std::string name) : Bird(name) {}
	void say() const override {
		std::cout << this->name << " horrroshii\n";
	}
	void say_phrase() {
		std::cout << phrase << '\n';
	}
	void study_new_phrase(std::string phrase) {
		this->phrase = phrase;
	}
};
class Myth_Dragon :public Animal {
public:
	Myth_Dragon(std::string name) : Animal(name) {}
	void growl() {
		std::cout << "Alarm!" << this->name << " is loudly growling!\n";
	}
	void flapping_wings() {
		std::cout << "Be careful!" << this->name << " flaps its wings!\n";
	}
	void change_form(std::string newform) {
		std::cout << "Wow?!? That's going on! " << this->name << " is changes form to " << newform << '\n';
	}
};
class Dragon_Fire :public Myth_Dragon {
public:
	Dragon_Fire(std::string name) : Myth_Dragon(name) {}
	void fire_breath() {
		std::cout << "DANGER!!!" << this->name << " breathing fire!\n";
	}
};
class Dragon_Ice :public Myth_Dragon {
public:
	Dragon_Ice(std::string name) : Myth_Dragon(name) {}
	void ice_breath() {
		std::cout << "DANGER!!!" << this->name << " exhales a frigid blast from its mouth!\n";
	}
};
class Dragon_Water :public Myth_Dragon {
public:
	Dragon_Water(std::string name) : Myth_Dragon(name) {}
	void Water_breath() {
		std::cout << "DANGER!!!" << this->name << " breathes a stream of water!\n";
	}
};
