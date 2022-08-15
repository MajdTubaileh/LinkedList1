                                                                                                                                                                                                                                                  /*                          
                                                                                                     Majd Tubaileh 
																									 11822970
																									 Dr.Nizar Anabtawi




                                                                                                                                                                                                                                                   */
#include<iostream>
using namespace std;
class Node {
public:
	int coefficint;
	int expression;
	Node* next;
private:
};

class LinkList {
private:
	Node* head;


public:
	LinkList() {
		head = NULL;
	}
	void insert(int x, int y) {
		Node* ne
			
			
			wNode = new Node;
		newNode->coefficint = x;
		newNode->expression = y;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* currNode = head;
			while (currNode->next != NULL) {
				currNode = currNode->next;
			}
			currNode->next = newNode;
		}
	}

	LinkList sum(LinkList list1, LinkList list2) {
		LinkList sumList;

		Node* temp = list1.head;

		while (temp != NULL) {
			Node* lookingFor = sumList.hasNode(temp);
			if (lookingFor == NULL) {
				sumList.insert(temp->coefficint, temp->expression);
			}
			else {
				lookingFor->coefficint = lookingFor->coefficint + temp->coefficint;

			}
			temp = temp->next;
		}

		temp = list2.head;

		while (temp != NULL) {
			Node* lookingFor = sumList.hasNode(temp);
			if (lookingFor == NULL) {
				sumList.insert(temp->coefficint, temp->expression);
			}
			else {
				lookingFor->coefficint = lookingFor->coefficint + temp->coefficint;;

			}
			temp = temp->next;

		}

		return sumList;
	}

	Node* hasNode(Node* searchNode) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->expression == searchNode->expression) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void display() {
		Node* currNode = head;
		cout << endl << "\t";
		while (currNode->next != NULL) {

			cout << currNode->coefficint << "X^" << currNode->expression << "+";
			currNode = currNode->next;
		}
		cout << currNode->coefficint << "X^" << currNode->expression << endl;

	}

	void my_swap(Node *node_1, Node *node_2)
	{
		int tempCoefficint = node_1->coefficint;
		int tempExpression = node_1->expression;

		node_1->coefficint = node_2->coefficint;
		node_1->expression = node_2->expression;

		node_2->coefficint = tempCoefficint;
		node_2->expression = tempExpression;
	}

	void sortthenode()
	{
		int swapped;

		Node *startpt; // left pointer will always point to the start of the list
		Node *endpt = NULL; // right pointer will always point to the end of the list
		do
		{
			swapped = 0;
			startpt = head;
			while (startpt->next != endpt)
			{
				if (startpt->expression < startpt->next->expression)
				{
					my_swap(startpt, startpt->next);
					swapped = 1;
				}
				startpt = startpt->next;
			}

			endpt = startpt;

		} while (swapped);
	}

};

int main() {

	LinkList link1, link2;
	LinkList sumList;
	int x, y, a, b;
	cout << " Enter The Expressions As " << endl;
	cout << "first number for the coefficent" << endl;
	cout << "second number for the exp" << endl;
	cout << "example : " << endl;
	cout << "---->3" << endl;
	cout << "---->2" << endl;
	cout << "the expression will be -> 3X^2." << endl;
	cout << "if you wanna finish add both numbers 0" << endl;
	cout << " ===================================================================" << endl;
	cout << "Enter your expression 1: " << endl;

	while (cin >> x >> y, x != 0 && y != -1) {
		link1.insert(x, y);
	}
	link1.display();
	cout << endl;
	cout << "Enter your expression 2: " << endl;

	while (cin >> a >> b, a != 0 && b != -1) {
		link2.insert(a, b);
	}
	link2.display();
	sumList = link1.sum(link1, link2);
	sumList.sortthenode();
	sumList.display();
	system("pause");
}
