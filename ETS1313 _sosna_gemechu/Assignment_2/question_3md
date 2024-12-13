# Algorithm
## Psedocode
S1: Start

S2: Declare variables: num, choice, temp, digit, rev, count, prod, first, last, sum, newNum, freq, strong, perfect
S3: Declare boolean isPalindrome

S4: Print "Enter a number: "
S5: Read num
S6: Set temp = num

S7: Display menu options:

* PRINT "1. Reverse of the number"
* PRINT "2. Number of digits"
* PRINT "3. Product of even digits"
* PRINT "4. First and last digit"
* PRINT "5. Swap first and last digit"
* PRINT "6. Palindrome"
* PRINT "7. Frequency of first digit"
* PRINT "8. Strong number"
* PRINT "9. Perfect number"
* PRINT "10. Exit"

S8: Print "Enter your choice: "
S9: Read choice

S10: Switch choice

CASE 1:

WHILE temp > 0:

SET digit = temp MOD 10

SET rev = rev * 10 + digit

SET temp = temp / 10

PRINT "Reverse of the number: ", rev

BREAK

S6: If choice is 1:

Initialize the reversed number to 0

If temp is greater than 0:

Get the last digit by finding the remainder when temp is divided by 10

Build the reverse number by multiplying the current reversed number by 10 and adding the last digit

Remove the last digit from temp by dividing it by 10

PRINT "Reverse of the number: ", reversed number

S7: If choice is 2:

Initialize a count variable to 0

If temp is greater than 0:

Increase the count by 1

Remove the last digit from temp by dividing it by 10

PRINT "Number of digits: ", count

S8: If choice is 3:

Initialize product to 1

If temp is greater than 0:

Get the last digit by finding the remainder when temp is divided by 10

IF the digit is even THEN:

Multiply the product by the digit

Remove the last digit from temp by dividing it by 10

PRINT "Product of even digits: ", product

S9: If choice is 4:

Initialize first and last digits

If temp is greater than 0:

Get the last digit by finding the remainder when temp is divided by 10

IF first digit is not set THEN:

Assign the last digit to the first digit

Assign the last digit to the variable last

Remove the last digit from temp by dividing it by 10

Calculate sum as first digit + last digit

PRINT "First digit: ", first, ", Last digit: ", last, ", Sum: ", sum

S10: If choice is 5:

Initialize a variable for the new number

If temp is greater than 0:

Get the last digit by finding the remainder when temp is divided by 10

IF the last digit is the first digit THEN:

Replace it with the last digit

ELSE IF the last digit is the last digit THEN:

Replace it with the first digit

Build the new number by multiplying by 10 and adding the digit

Remove the last digit from temp by dividing it by 10

PRINT "Number after swapping: ", new number

S11: If choice is 6:

Reset temp to num

Initialize a variable for the reversed number

Assume the number is a palindrome

If temp is greater than 0:

IF the last digit as found from temp does not match the last digit from the reversed number THEN:

Set the palindrome flag to false

BREAK

Remove last digits from both temp and the reversed number by dividing by 10

IF palindrome flag is true THEN:

PRINT "Palindrome: Yes"

ELSE:

PRINT "Palindrome: No"

S12: If choice is 7:

Initialize a frequency variable to 0

If temp is greater than 0:

Get the last digit by finding the remainder when temp is divided by 10

IF the digit is equal to the first digit THEN:

Increase the frequency by 1

Remove the last digit from temp by dividing it by 10

PRINT "Frequency of first digit: ", frequency


S13: If choice is 8:

Initialize a variable for the strong number check

If temp is greater than 0:

Get the last digit by finding the remainder when temp is divided by 10

Set factorial to 1

FOR each number from 1 to the last digit:

Multiply the factorial by the current number

Add the factorial to the strong number variable

Remove the last digit from temp by dividing it by 10

IF the strong number variable equals num THEN:

PRINT "Strong number: Yes"

ELSE:

PRINT "Strong number: No"

S14: If choice is 9:

Initialize a variable for perfect number check

FOR each number from 1 to num - 1:

IF num is divisible by the number THEN:

Add the number to perfect number total

IF total equals num THEN:

PRINT "Perfect number: Yes"

ELSE:

PRINT "Perfect number: No"

S15: If choice is 10:

PRINT "Exiting..."

S16: End
