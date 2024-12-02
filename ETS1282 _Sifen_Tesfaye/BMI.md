# Algorithm of Question number 1


Make a program that calculates the Body Mass Index (BMI) of a person and determine weather the person is
in normal weight, under weight or over weight. BMI is calculated as (BMI = w/h*h). Make the program to
work for multiple person before terminated?

## Analysis 

Input: Weight ,Height & number

output: BMI,normal weith/over weight/under weight/obses

operation: BMI= Weight/Height * Height

## Psedocode 

step_1: start

step_2: read the input as (height, weight, and number)

step_3: calculate body mass indedx(BMI) as BMI=weight/(height*height)

step_4: check if BMI is under weight,normal weight,over weight or obese

  * if(BMI<18.5) then weight=under weight

  * if(BMI>18.5 & BMI<24.9) then weight=normal weight

  * if(BMI>24.918.5 & BMI<29.9) then weight=over weight

  * if(BMI>29.9) then weight=obese

step_5: Print weight

step_6: read the input number 

step_7: if (number=1) then goto line 2

step_8: if(number=0) finish

step_9: End






```mermaid
flowchart TD
    Start([Start])
    Input1["Read height, weight, and number"]
    Calc["Calculate BMI = weight / (height * height)"]
    Check1{"BMI < 18.5?"}
    Underweight["Underweight"]
    Check2{"BMI ≤ 24.9?"}
    Normal["Normal weight"]
    Check3{"BMI ≤ 29.9?"}
    Overweight["Overweight"]
    Obese["Obese"]
    Output["Print weight category"]
    Continue["Read number (1 to continue, 0 to exit)"]
    Decision["number = 1?"]
    End([End])

    Start --> Input1
    Input1 --> Calc
    Calc --> Check1
    Check1 --> Underweight
    Check1 --> Check2
    Underweight --> Output
    Check2 --> Normal
    Check2 --> Check3
    Normal --> Output
    Check3 --> Overweight
    Check3 --> Obese
    Overweight --> Output
    Obese --> Output
    Output --> Continue
    Continue --> Decision
    Decision --> Input1
    Decision --> End
