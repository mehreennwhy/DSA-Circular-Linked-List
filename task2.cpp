#include<iostream>
#include<cstdint>  // For fixed-width integers
#include<cmath>    // For sqrt()
using namespace std;

// Node structure to hold parts of the large number
class Node {
public:
    uint32_t value;  // Store 32-bit part of the large number
    Node* next;

    Node(uint32_t val) {
        value = val;
        next = NULL;
    }
};

// Class to represent a large number using a linked list
class LargeNumber {
public:
    Node* head;
    int num_bits;

    LargeNumber() {
        head = NULL;
        num_bits = 0;
    }

    // Add a 32-bit part to the linked list
    void addPart(uint32_t part) {
        Node* newNode = new Node(part);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        num_bits += 32;  // Each node adds 32 bits
    }

    // Convert the linked list number to a string (for visualization)
    void display() {
        Node* temp = head;
        cout << "The large number (in 32-bit parts) is: ";
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // A function to calculate the modulus of the large number with a small number
    uint64_t mod(uint64_t smallNum) {
        Node* temp = head;
        uint64_t result = 0;

        while (temp != NULL) {
            result = (result * 100000000ULL + temp->value) % smallNum;
            temp = temp->next;
        }

        return result;  // Returns large number % smallNum
    }

    // Check if the large number is divisible by a small prime number
    bool isDivisibleBy(uint64_t smallPrime) {
        return (mod(smallPrime) == 0);
    }

    // Perform trial division up to a given limit (e.g., up to sqrt(n))
    bool isPrime() {
        if (isDivisibleBy(2)) return false;   // Check for even numbers
        if (isDivisibleBy(3)) return false;

        // Check for divisibility by primes from 5 onwards
        for (uint64_t i = 5; i <= 1000000; i += 6) {  // Limit can be adjusted
            if (isDivisibleBy(i)) return false;
            if (isDivisibleBy(i + 2)) return false;
        }

        return true;
    }
};

int main() {
    LargeNumber bigNum;
    int numParts = 1024 / 32;  // 32 parts of 32 bits

    cout << "Enter " << numParts << " 32-bit parts of the number: " << endl;
    for (int i = 0; i < numParts; i++) {
        uint32_t part;
        cin >> part;
        bigNum.addPart(part);  // Store the 32-bit part
    }

    // Display the stored number
    bigNum.display();

    // Check primality
    bool isPrime = bigNum.isPrime();
    if (isPrime)
        cout << "The number is prime." << endl;
    else
        cout << "The number is not prime." << endl;

    return 0;
}
