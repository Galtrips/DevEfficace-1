#include <iostream>
#include "liste.h"


using namespace std;

int main(void) {

	Cell* c1 = new Cell;
	Cell* c2 = new Cell;
	Cell* c3 = new Cell;
	Cell* c4 = new Cell;
	Cell* c5 = new Cell;

	c1->value = 1;
	c1->next = c2;

	c2->previous = c1;
	c2->value = 2;
	c2->next = c3;

	c3->previous = c2;
	c3->value = 3;
	c3->next = c4;

	c4->previous = c3;
	c4->value = 4;
	c4->next = c5;

	c5->previous = c4;
	c5->value = 5;

	Liste list(c2);

	
	list.add_begin(0);
	list.add_end(6);
	list.add(7, 3);
	list.add_end(6);
	list.add_end(6);
	list.add_end(6);

	
	//cout << "Je viens de supprimer " << list.remove_begin() << endl;
	//cout << "Je viens de supprimer " << list.remove_end() << endl;
	//cout << "Je viens de supprimer " << list.remove_current() << endl;
	//cout << "Je viens de supprimer " << list.remove(3) << endl;
	cout << "Je viens de supprimer " << list.remove_value(6) << endl;

	cout << "La taille finale est : " << list.size() << endl;
	cout << "La taille avant c" << list.get()->value << " est : " << list.size_before() << endl;
	cout << "La taille apres c" << list.get()->value << " est : " << list.size_after() << endl;
	list.print();

	return EXIT_SUCCESS;
}