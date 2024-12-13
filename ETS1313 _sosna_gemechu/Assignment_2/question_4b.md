### **Pseudocode for the Given Program**

1. **Start**
2. Declare `row`, `column`, `choice`, `cont`.
3. **Repeat** until `cont != 1`:
   1. Display "Enter number of rows: "
   2. Input `row`.
   3. Display "Enter number of columns: "
   4. Input `column`.
   5. Display pattern menu:
      - 1: Rectangle of numbers
      - 2: Rectangle of uppercase Alphabets
      - 3: Incremental number pyramid
      - 4: Reversed incremental number pyramid
      - 5: Alphabetic half pyramid
      - 6: Rectangle of lowercase Alphabets
      - 7: Hollow star rectangle
      - 8: Inverted star half pyramid
      - 9: Hollow inverted star pyramid
      - 10: Star pyramid
      - 11: Inverted star pyramid
      - 12: Hollow star pyramid
   6. Display "Enter the choice of pattern: "
   7. Input `choice`.

4. **Switch (choice):**
   - **Case 1:** Rectangle of numbers
     - Loop `i` from 1 to `row`:
       - Loop `j` from 1 to `column`:
         - Print `j`.
       - Print newline.

   - **Case 2:** Rectangle of uppercase Alphabets
     - Set `letter = 'A'`.
     - Loop `i` from 1 to `row`:
       - Loop `j` from 1 to `column`:
         - Print `letter`.
         - If `letter == 'Z'`, break.
         - Increment `letter`.
       - Print newline.

   - **Case 3:** Incremental number pyramid
     - Loop `i` from 1 to `row`:
       - Loop `j` from 1 to `i`:
         - Print `j`.
       - Print newline.

   - **Case 4:** Reversed incremental number pyramid
     - Loop `i` from 1 to `row`:
       - Loop `k` from `row - i` down to 1:
         - Print space.
       - Loop `j` from `i` down to 1:
         - Print `j`.
       - Print newline.

   - **Case 5:** Alphabetic half pyramid
     - Loop `i` from 1 to `row`:
       - Set `letter = 'A'`.
       - Loop `j` from 1 to `i`:
         - Print `letter`.
         - Increment `letter`.
       - Print newline.

   - **Case 6:** Rectangle of lowercase Alphabets
     - Loop `i` from 1 to `row`:
       - Set `letter = 'a'`.
       - Loop `j` from 1 to `column`:
         - Print `letter`.
         - Increment `letter`.
       - Print newline.

   - **Case 7:** Hollow star rectangle
     - Loop `i` from 1 to `row`:
       - Loop `j` from 1 to `column`:
         - If `i == 1 or i == row or j == 1 or j == column`:
           - Print `*`.
         - Else:
           - Print space.
       - Print newline.

   - **Case 8:** Inverted star half pyramid
     - Loop `i` from 1 to `row`:
       - Loop `j` from `row` down to `i`:
         - Print `*`.
       - Print newline.

   - **Case 9:** Hollow inverted star pyramid
     - Loop `i` from 1 to `row`:
       - Loop `j` from `row` down to `i`:
         - If `i == 1 or j == row or i == j`:
           - Print `*`.
         - Else:
           - Print space.
       - Print newline.

   - **Case 10:** Star pyramid
     - Loop `i` from 1 to `row`:
       - Loop `k` from `row - i` down to 1:
         - Print space.
       - Loop `j` from 1 to `i`:
         - Print `*`.
       - Print newline.

   - **Case 11:** Inverted star pyramid
     - Loop `i` from 1 to `row`:
       - Loop `k` from 1 to `i`:
         - Print space.
       - Loop `j` from `row` down to `i`:
         - Print `*`.
       - Print newline.

   - **Case 12:** Hollow star pyramid
     - Loop `i` from 1 to `row`:
       - Loop `k` from `row - i` down to 1:
         - Print space.
       - Loop `j` from 1 to `i`:
         - If `i == 1 or j == 1 or j == i or i == row`:
           - Print `*`.
         - Else:
           - Print space.
       - Print newline.

   - **Default:**
     - Display "Invalid choice".

5. Display "Press 1 to continue or 0 to exit."
6. Input `cont`.

7. **End Repeat**

8. Display "Thank you!!!"
9. **End**
