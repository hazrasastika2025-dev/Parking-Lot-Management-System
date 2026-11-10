# Parking Lot Management System

## 1. Project Overview
The Parking Lot Management System is a menu-driven application developed using the C programming language. It simulates the entry and exit of vehicles in a parking lot and manages parking space allocation efficiently.

The project demonstrates the practical application of Data Structures and Algorithms (DSA).

## 2. Objectives
- To manage vehicle entry and exit.
- To allocate available parking slots efficiently.
- To manage waiting vehicles using a queue.
- To track parked vehicles using a hash map.
- To maintain vehicle exit history using a stack.

## 3. Technologies Used
- Programming Language: C
- Compiler: GCC
- IDE: Visual Studio Code
- Version Control: Git and GitHub

## 4. Data Structures Used

### Stack
Used to maintain the history of vehicles that have exited the parking lot.

### Queue
Used to manage vehicles waiting for available parking slots. It follows the FIFO (First In, First Out) principle.

### Hash Map
Used to store vehicle registration numbers and their corresponding parking slot numbers for efficient searching.

### Arrays
Used to store parking slot information and vehicle details.

## 5. Features
- Vehicle entry management.
- Vehicle exit management.
- Automatic parking slot allocation.
- Waiting queue management.
- Display available and occupied parking slots.
- Vehicle exit history.
- Vehicle search using a hash map.

## 6. Project File Structure

```text
Parking-Lot-Management-System/
│
├── parking_lot.c
└── README.md
```

## 7. How to Compile and Run

### Step 1: Compile the Program

```bash
gcc parking_lot.c -o parking_lot
```

### Step 2: Run the Program

For Windows:

```bash
.\parking_lot.exe
```

For Linux:

```bash
./parking_lot
```

## 8. Menu Options

1. Entry
2. Exit
3. Display
4. Exit History
5. Stop

## 9. Sample Output

```text
Enter parking-lot capacity (1-100): 3

1. Entry
2. Exit
3. Display
4. Exit History
5. Stop

Enter choice: 1
Enter vehicle number: WB01AB1234

Vehicle parked in slot 1.
```

## 10. Complexity Analysis

- Hash Map: Average O(1) for searching and insertion.
- Queue: O(1) for enqueue and dequeue.
- Stack: O(1) for push and pop.
- Parking Slot Search: O(n).

## 11. Future Scope
- Adding a graphical user interface.
- Implementing parking fee calculation.
- Adding date and time tracking.
- Storing vehicle records permanently using file handling.
- Supporting multiple parking floors.

## 12. Conclusion
The Parking Lot Management System demonstrates the practical implementation of Stack, Queue, Hash Map and Array data structures using C programming. It provides an efficient way to manage vehicle entry, exit and parking slot allocation.

---
**Project:** DSA Mini Project – Parking Lot Management System  
**Language:** C