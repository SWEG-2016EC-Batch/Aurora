/*Design an algorithm and write a to read an employee name, weekly working hours, bonus rate per hour and base salary and find the employees gross-salary,
net salary and bonus payment. (Hint: pension rate – 5%, tax: 15%)*/

Analysis:

Input: name,weekly working hour,bonus rate per hours and base salary

Out put: net salary, bouns and gross salary

operation: bonus=bonusrateworking hours,gross salary=bonus+base salary,tax=0.15gross salary, pension=o.5*gross salary and net salary=base salary-tax-pension

Pseudocode:

step__1:Start

step__2:Input:

       Prompt the user to enter the employee's name.
       Prompt the user to enter the base salary.
       Prompt the user to enter the bonus rate per hour.
       Prompt the user to enter the weekly working hours.

step__3:Calculate:

     Bonus = bonus rate * weekly working hours.
     Gross salary = base salary + bonus.
     Tax = 15% of gross salary.
     Pension = 5% of base salary.
     Net salary = gross salary - tax - pension.

step__4:Output:

     Print net salary, gross salary, and bonus.

step__5:End: