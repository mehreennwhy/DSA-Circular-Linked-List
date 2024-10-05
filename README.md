# DSA-Circular-Linked-List
-TASK 1
Approach:
Process Representation: Store each process as a node in a circular linked list with process_id, execution_time, and remaining_time.
Round-Robin Scheduling: Implement a round-robin algorithm where each process is allocated a fixed time slice, reducing its remaining time after each cycle.
Process Removal: When a process's remaining time becomes zero, remove it from the circular linked list.
Assumptions:
Equal Time Slice: Each process gets an equal time slice for CPU execution.
Circular Linked List: The processes are stored in a circular linked list to continuously cycle through them.
No I/O Interrupts: The system does not account for process blocking or I/O interrupts, purely CPU-bound.
Challenges:
Efficient Process Removal: Removing a process from the circular linked list while maintaining the structure and continuity.
Edge Cases: Handling cases where the remaining time is less than the time slice or when only one process remains.
Performance Overhead: Managing overhead in constantly cycling through processes and keeping the linked list updated.

-TASK 2
Approach:
Storing the Number: Store the 1024-bit number in a linked list, with each node holding up to 64 bits of the number (or 19 decimal digits).
Primality Testing: Use the probabilistic Miller-Rabin test to check if the number is prime
Memory Optimization: Manage memory by minimizing node usage and performing arithmetic directly on the linked list nodes without overflow.
Assumptions:
Random Number: The 1024-bit number is truly random and evenly distributed.
Node Size: Each linked list node stores up to 64-bit numbers (max 19 digits per node).
Probabilistic Accuracy: test divisibility by small prime numbers (up to some reasonable limit) using modular arithmetic across the nodes of the linked list.
Challenges:
Linked List Arithmetic: Implement efficient modular arithmetic across nodes representing parts of the large number.
Performance: Balancing the time complexity of a 1024-bit primality test with efficient memory usage.
