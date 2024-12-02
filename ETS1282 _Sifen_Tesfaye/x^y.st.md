# Algorithm of question number 3

Write a program that find the result of the expression 𝑥^𝑦 where the value of X and Y are entered by the user.

## Analysis

Input: two postive integer x and y

Output: x^y

operation: z=x^y
 
## Psedocode of the above code

step_1: start

step_2: read input of two positive integer number X and Y

step_3: i=1, X=1, i++

step_4: product*=X

step_5: if(i<=Y), then goto line 4

step_6: end


## flowchart of the above psedocode

```mermaid
   graph TD
    A[Start] --> B[Read input of two positive integers X and Y]
    B --> C[i = 1, product = 1]
    C --> D[product *= X]
    D --> E{Is i <= Y?}
    E -- Yes --> D
    E -- No --> F[End]
