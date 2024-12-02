/* Make a program that calculates the Body Mass Index (BMI) of a person and determine weather the person is
in normal weight, under weight or over weight. BMI is calculated as (BMI = w/h*h). Make the program to
work for multiple person before terminated. */

## Input

-weight

-height

-BMI = weight/(height*height)
  
## Output

-under weight,if BMI is less than 18.5 

-Normal weight, if BMI is between 18.5-24.9

-Overweight, if BMI is between 25.0-29.9

-Obese, if BMI is morethan 30

 Algorithm
 * step1: start
 * step2: read weight
* step3: read height
* step4: operate BMI,as BMI= weight/(height*height)
* step5: print BMI
* step6: end




```mermaid
graph TD
A[start]-->B[read weight]-->C[read height]-->D[operate BMI, BMI=weight/(height*height)]-->E[print BMI]-->F[end]
