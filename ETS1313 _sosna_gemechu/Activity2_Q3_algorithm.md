## Algorithm
Write a program that find the result of the expression x^y where the value of X and Y are entered by the user.

## Analysis

Input: two postive integer x and y

Output: x^y

operation: z=x^

## psedocode of the above code
* start
* read input of two positive integer number X and Y
* i=1, X=1 
* product*=X
* if(i<=Y), then goto line 4
* print product
* end


## flowchart of the above psedocode
```mermaid
   graph TD
    A[Start] --> B[Read input of two positive integers X and Y]
    B --> C[i = 1, product = 1]
    C --> D[product *= X]
    D --> E{Is i <= Y?}
    E -- Yes --> D
    E -- No --> F[print product]-->[End]
