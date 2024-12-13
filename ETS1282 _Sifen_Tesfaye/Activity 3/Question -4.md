### **Pseudocode Using Only Statements**

1. Display "Choose a program to run:"
2. Display options:
   - "1. Print alphabet grid"
   - "2. Print decreasing stars"
   - "3. Print hollow rectangle"
   - "4. Print inverted hollow triangle"
   - "5. Print right-aligned triangle"
   - "6. Print inverted right-aligned triangle"
   - "7. Print hollow right-aligned triangle"
3. Display "Enter your choice (1-7):"
4. Input `choice`

---

**If `choice == 1`**:
- Loop through `i` from 'a' to 'e':
  - Loop through `j` from 'a' to 'e':
    - Print `j` with a space.
  - Print a newline.

---

**Else if `choice == 2`**:
- Set `n = 6`
- Loop through `i` from 1 to `n`:
  - Loop through `j` from 0 to `n - i`:
    - Print "* ".
  - Print a newline.

---

**Else if `choice == 3`**:
- Set `n = 7`
- Loop through `i` from 1 to `n`:
  - Loop through `j` from 0 to `n`:
    - If `i == 1` or `i == n` or `j == 0` or `j == n`:
      - Print "* ".
    - Else:
      - Print two spaces.
  - Print a newline.

---

**Else if `choice == 4`**:
- Set `n = 6`
- Loop through `i` from 1 to `n`:
  - Loop through `j` from 0 to `n - i`:
    - If `i == 1` or `j == n - i` or `j == 0`:
      - Print "* ".
    - Else:
      - Print two spaces.
  - Print a newline.

---

**Else if `choice == 5`**:
- Set `n = 6`
- Loop through `i` from 1 to `n`:
  - Loop through `k` from `n - i` down to 1:
    - Print one space.
  - Loop through `j` from 1 to `i`:
    - Print "* ".
  - Print a newline.

---

**Else if `choice == 6`**:
- Set `n = 6`
- Loop through `i` from 1 to `n`:
  - Loop through `k` from 1 to `i - 1`:
    - Print one space.
  - Loop through `j` from `i` to `n`:
    - Print "* ".
  - Print a newline.

---

**Else if `choice == 7`**:
- Set `n = 6`
- Loop through `i` from 1 to `n`:
  - Loop through `k` from `n - i` down to 1:
    - Print one space.
  - Loop through `j` from 1 to `i`:
    - If `i == n` or `j == i` or `j == 1`:
      - Print "* ".
    - Else:
      - Print two spaces.
  - Print a newline.

---

**Else**:
- Display "Invalid choice. Please run the program again."

---

**End**
