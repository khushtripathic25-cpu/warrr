#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *next;
};

Node *current = NULL;

void addPlayer() {
    Node *p = new Node;
    cin >> p->name;

    if (!current) {
        current = p;
        p->next = p;
    } else {
        p->next = current->next;
        current->next = p;
    }
}

void removePlayer() {
    if (!current) return;

    Node *p = current;
    while (p->next != current)
        p = p->next;

    if (p == current)
        current = NULL;
    else {
        p->next = current->next;
        delete current;
        current = p->next;
    }
}

void nextPlayer() {
    if (current)
        current = current->next;
}

void display() {
    if (current)
        cout << "Current Turn: " << current->name << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1.Add 2.Remove 3.Next 4.Display 5.Exit\n";
        cin >> choice;

        if (choice == 1) addPlayer();
        else if (choice == 2) removePlayer();
        else if (choice == 3) nextPlayer();
        else if (choice == 4) display();

    } while (choice != 5);
}