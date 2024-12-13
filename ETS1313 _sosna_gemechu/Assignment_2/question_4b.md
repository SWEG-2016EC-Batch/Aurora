# Pseudocode

Start

Display the menu:

1: Print alphabet grid

2: Print decreasing stars

3: Print hollow rectangle

4: Print inverted hollow triangle

5: Print right-aligned triangle

6: Print inverted right-aligned triangle

7: Print hollow right-aligned triangle

Prompt the user to Enter their choice (1-7).

If choice = 1:

Loop through letters 'a' to 'e' for rows.

For each row, loop through letters 'a' to 'e' for columns.

Print the current letter followed by a space.

Print a newline after each row.

If choice = 2:

Set n = 6.

Loop from i = 1 to n:

Loop from j = 0 to (n - i):

Print * followed by a space.

Print a newline after each row.

If choice = 3:

Set n = 7.

Loop from i = 1 to n:

Loop from j = 0 to n:

If i == 1 OR i == n OR j == 0 OR j == n:

Print * followed by a space.

Else:

Print two spaces.

Print a newline after each row.

If choice = 4:

Set n = 6.

Loop from i = 1 to n:

Loop from j = 0 to (n - i):

If i == 1 OR j == (n - i) OR j == 0:

Print * followed by a space.

Else:

Print two spaces.

Print a newline after each row.

If choice = 5:

Set n = 6.

Loop from i = 1 to n:

Loop from k = (n - i) to 1:

Print a single space.

Loop from j = 1 to i:

Print * followed by a space.

Print a newline after each row.

If choice = 6:

Set n = 6.

Loop from i = 1 to n:

Loop from k = 1 to (i - 1):

Print a single space.

Loop from j = i to n:

Print * followed by a space.

Print a newline after each row.

If choice = 7:

Set n = 6.

Loop from i = 1 to n:

Loop from k = (n - i) to 1:

Print a single space.

Loop from j = 1 to i:

If i == n OR j == i OR j == 1:

Print * followed by a space.
Else:

Print two spaces.

Print a newline after each row.

If choice is invalid:

Print "Invalid choice. Please run the program again."

End


