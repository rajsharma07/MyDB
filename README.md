# SQLite Clone (C Language)

A lightweight, educational clone of **SQLite** written in **C**.  
This project is aimed at understanding how relational databases work under the hood by building one step by step.

---

## 🚀 Current Progress
- [x] Implemented a basic **REPL (Read–Eval–Print Loop)** for accepting SQL-like commands from the user.
- [ ] Command parsing
- [ ] Table creation
- [ ] Data insertion
- [ ] Query execution
- [ ] Storage engine (disk persistence)
- [ ] Indexing & optimization

---

## 📖 Features (Planned)
- Minimal SQL support (`CREATE`, `INSERT`, `SELECT`, etc.)
- In-memory + on-disk storage
- B-Tree based indexing
- Query parsing & execution engine
- Transaction support (future goal)

---

## 🛠️ Getting Started

### Prerequisites
- A C compiler (e.g., `gcc`, `clang`)
- Make (optional, if you use a Makefile)
- Linux/MacOS/Windows environment

### Build & Run
```bash
# Clone the repo
git clone https://github.com/<your-username>/sqlite-clone.git
cd sqlite-clone

# Compile
gcc main.c -o sqlite_clone

# Run
./sqlite_clone
