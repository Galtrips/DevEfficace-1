#pragma once

using namespace std;

struct Cell {
	Cell* previous = nullptr;
	int value;
	Cell* next = nullptr;
};

class Liste
{
private:
	Cell* cell;
	void check();
public:
	Liste();
	Liste(Cell*);
	~Liste();

	bool at_beginig();
	bool at_end();
	bool empty();
	bool equals();

	void begining_of();
	void end_of();
	void print();

	int size();
	int size_before();
	int size_after();

	void add(int, int);
	void add_begin(int);
	void add_end(int);
	
	int remove(int);
	int remove_begin();
	int remove_end();
	int remove_current();
	int remove_value(int);

	Liste duplicate();
	void merge(Liste);
	void sort();

	Cell* get();
};