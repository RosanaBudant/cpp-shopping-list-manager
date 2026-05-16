# Shopping List Manager (C++)

A simple terminal-based shopping list manager developed in C++.

## Features

- Add items to the shopping list
- Save items into a TXT file
- Display saved items
- Terminal menu interface
- File persistence using `fstream`

## Technologies

- C++
- STL (`vector`, `string`)
- File handling with `fstream`
- Linux/Windows terminal

## Project Structure

```bash
.
├── main.cpp
├── shopping_list.txt
└── README.md
````

## How to Compile

### Linux / Mac

```bash
g++ main.cpp -o shopping_list
./shopping_list
```

### Windows (MinGW)

```bash
g++ main.cpp -o shopping_list.exe
shopping_list.exe
```

## Learning Goals

This project was created to practice:

* Object-oriented programming
* File manipulation
* STL containers
* User input handling
* Terminal applications

## Future Improvements

* Remove items
* Edit items
* Save data using JSON
* Add categories
* Improve input validation
