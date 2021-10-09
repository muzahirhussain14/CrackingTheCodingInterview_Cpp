/*
Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
that type). They cannot select which specific animal they would like. Create the data structures to
maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
and dequeueCat. You may use the built-in LinkedList data structure.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Animal 
{
	string name;
	int position;

	Animal(){}

	Animal(string n, int p) {
		name = n;
		position = p;
	}

	virtual string getName() {
		return name;
	}

	virtual int getPosition() {
		return position;
	}

	virtual ~Animal() {

	}
};

struct Cat:Animal
{
	Cat(string n)
	{
		name = n;
	}

	Cat(string n, int pos)
	{
		name = n;
		position = pos;
	}
};

struct Dog:Animal
{
	Dog(string n) 
	{
		name = n;
	}

	Dog(string n, int pos)
	{
		name = n;
		position = pos;
	}
};


class Queue
{
private:
	vector<Animal> queue;
	int start;

public:
	void enqueue(Animal animal) 
	{
		queue.push_back(animal);
	}

	Animal dequeue() 
	{
		Animal obj = queue[start];
		++start;

		if (start == queue.size()) {
			start = 0;
			queue.clear();
		}

		return obj;
	}

	Animal peek() {
		return queue[start];
	}

	int size() {
		return queue.size();
	}
};

class AnimalShelter
{
private:
	Queue cats;
	Queue dogs;
	int position = 0;

public:

	AnimalShelter() {
		position = 0;
	}

	void enqueue(Animal* animal)
	{
		if (dynamic_cast<Cat*>(animal) != nullptr)			// Cat
		{	
			Cat obj(animal->getName(), position);
			cats.enqueue(obj);
		}

		if (dynamic_cast<Dog*>(animal) != nullptr)			// Dog
		{
			Dog obj(animal->getName(), position);
			dogs.enqueue(obj);
		}
		++position;
	}

	Animal dequeueAny() 
	{
		if (cats.size() > 0 && dogs.size() > 0) 
		{
			return (cats.peek().getPosition() <= dogs.peek().getPosition()) ? cats.dequeue() : dogs.dequeue();
		}

		if (cats.size())
			return cats.dequeue();
		
		else if (dogs.size())
			return dogs.dequeue();
	}

	Animal dequeueCat() 
	{
		return cats.dequeue();
	}

	Animal dequeueDog()
	{
		return dogs.dequeue();
	}

	void Print() 
	{
		Queue cat = cats;
		Queue dog = dogs;

		while (cat.size() && dog.size()) 
		{
			cout <<  ((cat.peek().getPosition() <= dog.peek().getPosition()) ? cat.dequeue().getName() : dog.dequeue().getName()) << "  ";
		}

		while (cat.size())
			cout << cat.dequeue().getName() << "  ";

		while (dog.size())
			cout << dog.dequeue().getName() << "  ";
	}
};


int main() 
{
	AnimalShelter shelter;
	Cat cat_1("Memo_Cat");
	Cat cat_2("Memo_Cat2");
	Cat cat_3("Memo_Cat3");

	Dog dog_1("Doggy_dog");
	Dog dog_2("Doggy_dog2");
	Dog dog_3("Doggy_dog3");

	shelter.enqueue(&cat_1);
	shelter.enqueue(&cat_2);
	shelter.enqueue(&dog_1);
	shelter.enqueue(&cat_3);

	cout << shelter.dequeueAny().getName() << "\n";
	cout << shelter.dequeueAny().getName() << "\n";
	cout << shelter.dequeueAny().getName() << "\n";

	//cout << shelter.dequeueCat().getName() << "  ";
	//cout << shelter.dequeueCat().getName() << "\n";
	//cout << shelter.dequeueDog().getName() << "\n";

	//shelter.Print();

	cout << endl;
	return 0;
}