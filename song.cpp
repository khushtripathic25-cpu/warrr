#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *next, *prev;
};
Node *head = NULL;

void add() {
    Node *p = new Node;
    cin >> p->song;
    if (!head) {
        head = p;
        p->next = p->prev = p;
    } else {
        p->prev = head->prev;
        p->next = head;
        head->prev->next = p;
        head->prev = p;
    }
}

void del() {
    if (!head) return;
    string s;
    cin >> s;
    Node *p = head;
    do {
        if (p->song == s) {
            if (p->next == p) head = NULL;
            else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                if (p == head) head = p->next;
            }
            delete p;
            return;
        }
        p = p->next;
    } while (p != head);
}

void show(bool forward) {
    if (!head) return;
    Node *p = forward ? head : head->prev;
    Node *start = p;
    do {
        cout << p->song << " ";
        p = forward ? p->next : p->prev;
    } while (p != start);
}

int main() {
    int choice;
    do {
        cout << "\n1.Add 2.Delete 3.Forward 4.Backward 5.Exit\n";
        cin >> choice;
        if (choice == 1)
            add();
        else if (choice == 2)
            del();
        else if (choice == 3)
            show(true);
        else if (choice == 4)
            show(false);
    } while (choice != 5);
}