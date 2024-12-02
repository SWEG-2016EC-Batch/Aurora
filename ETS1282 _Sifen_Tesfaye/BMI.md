/* Make a program that calculates the Body Mass Index (BMI) of a person and determine weather the person is
in normal weight, under weight or over weight. BMI is calculated as (BMI = w/h*h). Make the program to
work for multiple person before terminated. */

 pseudocod :

step__1:Start

step__2:Input Weight and Height

      Prompt user to enter their weight.
      Read the weight.
      Prompt user to enter their height.
      Read the height.

step__3: Calculate BMI
step__4:Calculate BMI using the formula: BMI = weight / (height * height).
step__5: Display BMI

      Print the calculated BMI.e
      Determine Weight Category
      IF BMI < 18.5:
      Print "Underweight".
      ELSE IF BMI >= 18.5 AND BMI <= 24.9:
      Print "Normal weight".
      ELSE IF BMI >= 25 AND BMI <= 29.9:
      Print "Overweight".
      ELSE:
      Print "Obese".

step__6:Prompt to Continue

       Ask if the user wants to calculate BMI for another person (1 to continue, 0 to terminate).
       Read user's choice.
       Decision
       IF choice == 0:
       Print "We finish, thank you".
       End the program.
       ELSE:
       Return to step 2.

step__7:End :

Flow chart :

    graph TD
    A[Start] --> B{Input weight (kg) and height (m)};
    B --> C[Calculate BMI = weight / (height*height)];
    C --> D[Display BMI];
    D --> E{Is BMI < 18.5?};
    E -- Yes --> F[Display: Underweight];
    E -- No --> G{Is BMI <= 24.9?};
    G -- Yes --> H[Display: Normal weight];
    G -- No --> I{Is BMI <= 29.9?};
    I -- Yes --> J[Display: Overweight];
    I -- No --> K[Display: Obese];
    F --> L{Continue?};
    H --> L;
    J --> L;
    K --> L;
    L -- Yes --> B;
    L -- No --> M[End];



