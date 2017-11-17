#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		Node() {
			data = 0;
			next = NULL;
		}
};

class IntegerList {
	private:
		Node* head;
		Node* tail;
		int n;

	public:
		IntegerList() {
			head = NULL;
			tail = NULL;
			n = 0;
		}

		void addNode(int x);
		void insertNode(int x, int i);
		void deleteNode(int i);
		void display();
};

void IntegerList::addNode(int x) {
	Node* ptemp = new Node;
	ptemp->data = x;
	ptemp->next = NULL;

	if (head == NULL) {
		head = ptemp;
		tail = ptemp;
		++n;
	} else {
		tail->next = ptemp;
		tail = ptemp;
		++n;
	}
}

void IntegerList::insertNode(int x, int i) {
	if (i > n) {
		cout << "Invalid index." << endl;

	} else if (i == 0) {
		Node* ptemp = new Node;
		ptemp->data = x;
		ptemp->next = head;
		head = ptemp;
		++n;

	} else if (i == n) {
		(*this).addNode(x);

	} else {
		Node* ptemp = new Node;
		ptemp->data = x;

		Node* move = head;

		for (int j=0; j<i-1; ++j) {
			move = move->next;
		}

		ptemp->next = move->next;
		move->next = ptemp;
		++n;
	}
}

void IntegerList::deleteNode(int i) {
	if (i >= n) {
		cout << "Invalid index." << endl;
	} else if (i == 0) {
		head = head->next;
		--n;
	} else if (i == n-1) {
		Node* move = head;
		for (int j=0; j<i-1; ++j) {
			move = move->next;
		}

		tail = move;
		move->next = NULL;
		--n;
	} else {
		Node* move = head;
		for (int j=0; j<i-1; ++j) {
			move = move->next;
		}

		move->next = (move->next)->next;
		--n;
	}
}

void IntegerList::display() {
	if (head == NULL) {
		cout << "The list is empty." << endl;
	} else {
		Node* ptemp = new Node;
		ptemp = head;
		
		while (ptemp != NULL) {
			cout << ptemp->data << endl;
			ptemp = ptemp->next;
		}
	}
}

int main() {
	IntegerList list1;
	int foo=0;
	cout << "Enter five elements to the list: " << endl;
	for (int i=0; i<5; ++i) {
		cin >> foo;
		list1.addNode(foo);
	}

	cout << endl;
	list1.display();

	list1.deleteNode(4);

	cout << endl;
	list1.display();
	

	return 0;
}
