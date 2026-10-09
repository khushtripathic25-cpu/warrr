#include <iostream>
using namespace std;

struct Node {
    int prn;
    string name;
    Node *next;
};

Node *head = NULL;

void addPresident() {
    Node *p = new Node;
    cin >> p->prn >> p->name;
    p->next = head;
    head = p;
}

void addSecretary() {
    Node *p = new Node;
    cin >> p->prn >> p->name;
    p->next = NULL;

    if (head == NULL) head = p;
    else {
        Node *q = head;
        while (q->next) q = q->next;
        q->next = p;
    }
}

void addMember() {
    Node *p = new Node;
    cin >> p->prn >> p->name;

    Node *q = head;
    while (q->next->next) q = q->next;

    p->next = q->next;
    q->next = p;
}

void deletePresident() {
    if (head) {
        Node *p = head;
        head = head->next;
        delete p;
    }
}

void deleteSecretary() {
    Node *p = head;
    while (p->next->next) p = p->next;
    delete p->next;
    p->next = NULL;
}

void deleteMember() {
    int x;
    cin >> x;

    Node *p = head;
    while (p->next && p->next->prn != x)
        p = p->next;

    if (p->next) {
        Node *q = p->next;
        p->next = q->next;
        delete q;
    }
}

void display() {
    Node *p = head;
    while (p) {
        cout << p->prn << " " << p->name << endl;
        p = p->next;
    }
}

void countMembers() {
    int c = 0;
    Node *p = head;
    while (p) {
        c++;
        p = p->next;
    }
    cout << "Total: " << c << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1.Add President  2.Add Member  3.Add Secretary";
        cout << "\n4.Delete President  5.Delete Member  6.Delete Secretary";
        cout << "\n7.Display  8.Count  9.Exit\n";
        cin >> choice;

        if (choice == 1) addPresident();
        else if (choice == 2) addMember();
        else if (choice == 3) addSecretary();
        else if (choice == 4) deletePresident();
        else if (choice == 5) deleteMember();
        else if (choice == 6) deleteSecretary();
        else if (choice == 7) display();
        else if (choice == 8) countMembers();

    } while (choice != 9);
}