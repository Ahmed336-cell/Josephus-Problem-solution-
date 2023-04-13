

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

};

Node* head = NULL;
/*void push(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newnode->data = val;
    newnode->next = head;
    if (head != NULL) {
        while (temp->next !=head) {
            temp = temp->next;
            temp->next = newnode;
        }
    }
    else {
        newnode->next = newnode;
    }
    head = newnode;
}
*/
void pop(int k) {
    if (head == NULL) {
        cout << "game is empty" << endl;
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        Node* temp = current;
        current = prev->next;
        cout << "number " << temp->data << " is died" << endl;
        free(temp);
    }

    cout << "winner is nuumber " << current->data << "" << endl;
    head == NULL;
}
void display() {
    if (head == NULL) {
        cout << "game is empty" << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void initGame(int n) {
    if (n < 1) {
        return;
    }

    for (int i = 1; i <= n; i++) {
       struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }
}

int main()
{
    int n, k;
    cout << "welcome to Josephus PROBLEM " << endl;
    cout << "please enter number of players : ";
    cin >> n;
    cout << endl;
    cout << "please enter number of rotations : ";
    cin >> k;

    initGame(n);
    cout << "Circle contain : ";
        display();
        cout << "Game started : ";
        pop(k);


}

