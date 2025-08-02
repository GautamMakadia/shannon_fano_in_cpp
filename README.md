# Character Frequency Counter in C++

This project reads a text file and calculates the frequency of each character using C++. It is a foundational part of many text processing or compression algorithms like Shannon-Fano or Huffman encoding.

---

## 📦 Features

- Reads text input from a file or stdin
- Calculates frequency of each character
- Outputs character-frequency table

---

## 🔧 Build & Run

### Requirements

- C++17 or higher
- Make

### Steps

```bash
git clone https://github.com/GautamMakadia/shannon_fano_in_cpp.git
cd shannon_fano_in_cpp

# Build and run the project
make
```

You can also compile manually:

```bash
g++ -std=c++17 main.cpp shannon_fano/*.tpp -o freqcalc
./freqcalc < t.txt
```

---

## 🧪 Sample Output

```
Character | Frequency
----------|----------
    a     |    10
    b     |     5
    c     |     3
   ...    |   ...
```

---

## 👤 Author

[Gautam Makadia](https://github.com/GautamMakadia)
