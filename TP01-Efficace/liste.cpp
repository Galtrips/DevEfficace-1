#include "liste.h"
#include "exception.h"

Liste::Liste() {
	this->cell = nullptr;
}

Liste::Liste(Cell* cell) {
	this->cell = cell;
}

Liste::~Liste() {

}

void Liste::check() {
	if (this->empty()) {
		throw Exception("La liste est vide...");
	}
}

bool Liste::empty() {
	return (this->cell == nullptr);
}

bool Liste::at_beginig() {
	
	this->check();
	return (this->cell->previous == nullptr);
}

bool Liste::at_end() {
	
	this->check();
	return (this->cell->next == nullptr);
}

void Liste::begining_of() {
	
	this->check();
	Cell* currentCell = this->cell;
	while (currentCell->previous != nullptr) {
		currentCell = currentCell->previous;
	}

	this->cell = currentCell;
}

void Liste::end_of() {
	
	this->check();
	Cell* currentCell = this->cell;
	while (currentCell->next != nullptr) {
		currentCell = currentCell->next;
	}

	this->cell = currentCell;
}

Cell* Liste::get() {

	this->check();
	return this->cell;
}

int Liste::size() {

	this->check();
	int size = 1;
	Cell* currentCell = this->cell;

	this->begining_of();
	Cell* tmp = this->cell;

	while (tmp->next != nullptr) {
		size++;
		tmp = tmp->next;
	}

	this->cell = currentCell;
	return size;
}

int Liste::size_before() {

	this->check();
	int size = 0;
	Cell* currentCell = this->cell;

	while (currentCell->previous != nullptr) {
		size++;
		currentCell = currentCell->previous;
	}

	return size;
}

int Liste::size_after() {

	this->check();
	int size = 0;
	Cell* currentCell = this->cell;

	while (currentCell->next != nullptr) {
		size++;
		currentCell = currentCell->next;
	}

	return size;
}

void Liste::print() {

	this->check();

	Cell* currentCell = this->cell;

	this->begining_of();
	Cell* tmp = this->cell;

	do {
		cout << "-----------------------------------------------" << endl;
		cout << "Cellule n: " << tmp->value << " (" << tmp << ")" << endl;
		cout << "Pointeur Precedent : " << tmp->previous << endl;
		cout << "Pointeur Suivant : " << tmp->next << endl;
		cout << "-----------------------------------------------" << endl;
		tmp = tmp->next;
	} while (tmp->next != nullptr);

	cout << "-----------------------------------------------" << endl;
	cout << "Cellule n: " << tmp->value << " (" << tmp << ")" << endl;
	cout << "Pointeur Precedent : " << tmp->previous << endl;
	cout << "Pointeur Suivant : " << tmp->next << endl;
	cout << "-----------------------------------------------" << endl;

	this->cell = currentCell;
}

void Liste::add_begin(int newValue) {

	this->check();

	Cell* newCell = new Cell;
	newCell->value = newValue;

	Cell* currentCell = this->cell;

	this->begining_of();
	Cell* tmp = this->cell;

	newCell->next = tmp;
	tmp->previous = newCell;

	this->cell = currentCell;
}

void Liste::add_end(int newValue) {

	this->check();

	Cell* newCell = new Cell;
	newCell->value = newValue;

	Cell* currentCell = this->cell;

	this->end_of();
	Cell* tmp = this->cell;

	newCell->previous = tmp;
	tmp->next = newCell;

	this->cell = currentCell;
}

void Liste::add(int newValue, int k) {

	this->check();
	int cpt = 0;
	Cell* newCell = new Cell;
	newCell->value = newValue;

	Cell* currentCell = this->cell;

	this->begining_of();
	Cell* tmp = this->cell;

	while (tmp->next != nullptr && cpt != k) {
		cpt++;
		tmp = tmp->next;
	}

	newCell->previous = tmp->previous;
	newCell->next = tmp;
	newCell->previous->next = newCell;
	tmp->previous = newCell;

	this->cell = currentCell;
}

int Liste::remove_begin() {

	this->check();

	Cell* currentCell = this->cell;

	this->begining_of();
	Cell* tmp = this->cell;

	tmp->next->previous = nullptr;
	tmp->next = nullptr;

	int value = tmp->value;
	
	if (currentCell == tmp) {
		currentCell->previous != nullptr ? this->cell = currentCell->previous : currentCell->next != nullptr ? this->cell = currentCell->next : this->cell = nullptr;
	}
	else {
		this->cell = currentCell;
	}

	delete tmp;

	return value;
}

int Liste::remove_end() {

	this->check();

	Cell* currentCell = this->cell;

	this->end_of();
	Cell* tmp = this->cell;

	tmp->previous->next = nullptr;
	tmp->previous = nullptr;

	int value = tmp->value;
	
	if (currentCell == tmp) {
		currentCell->previous != nullptr ? this->cell = currentCell->previous : currentCell->next != nullptr ? this->cell = currentCell->next : this->cell = nullptr;
	}
	else {
		this->cell = currentCell;
	}

	delete tmp;
	return value;
}

int Liste::remove_current() {

	this->check();

	Cell* currentCell = this->cell;

	Cell* tmp = this->cell;

	if (tmp->previous != nullptr)
		tmp->previous->next = tmp->next;

	if (tmp->next != nullptr)
		tmp->next->previous = tmp->previous;

	int value = tmp->value;
	if (currentCell == tmp) {
		currentCell->previous != nullptr ? this->cell = currentCell->previous : currentCell->next != nullptr ? this->cell = currentCell->next : this->cell = nullptr;
	}
	else {
		this->cell = currentCell;
	}

	delete tmp;
	return value;
}


int Liste::remove(int k) {

	this->check();
	int cpt = 0;
	Cell* currentCell = this->cell;

	this->begining_of();
	Cell* tmp = this->cell;

	while (tmp->next != nullptr && cpt != k) {
		cpt++;
		tmp = tmp->next;
	}

	if (tmp->previous != nullptr)
		tmp->previous->next = tmp->next;

	if (tmp->next != nullptr)
		tmp->next->previous = tmp->previous;

	int value = tmp->value;
	if (currentCell == tmp) {
		currentCell->previous != nullptr ? this->cell = currentCell->previous : currentCell->next != nullptr ? this->cell = currentCell->next : this->cell = nullptr;
	}
	else {
		this->cell = currentCell;
	}

	delete tmp;
	return value;
}

int Liste::remove_value(int value) {

	this->check();
	int cpt = 0;

	this->begining_of();
	Cell* tmp = this->cell;

	while (tmp->next != nullptr) {
		if (tmp->value == value) {
			tmp = tmp->next;
			this->remove(cpt);
		}
		else {
			tmp = tmp->next;
			cpt++;
		}
	}
	if (tmp->value == value) {
		this->remove(cpt);
	}

	return value;
}