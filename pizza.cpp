#include <iostream>
using namespace std;

int q[100], front = -1, rear = -1, M;

void add() {
    if ((rear + 1) % M == front) {
        cout << "Queue Full\n";
        return;
    }
    int order;
    cin >> order;
    if (front == -1) front = 0;
    rear = (rear + 1) % M;
    q[rear] = order;
}

void serve() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Served: " << q[front] << endl;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % M;
}

void display() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }
    int i = front;
    do {
        cout << q[i] << " ";
        i = (i + 1) % M;
    } while (i != (rear + 1) % M);
    cout << endl;
}

int main() {
    int choice;
    cout << "Enter maximum orders: ";
    cin >> M;

    do {
        cout << "\n1.Add Order 2.Serve Order 3.Display 4.Exit\n";
        cin >> choice;
        if (choice == 1) add();
        else if (choice == 2) serve();
        else if (choice == 3) display();
    } while (choice != 4);
}