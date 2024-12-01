## psedocode and flowchart of
Design an algorithm and write a to read an employee name weekly working hours, bonus rate per hour and
base salary and find the employees gross-salary, net salary and bonus payment. (Hint: pension rate – 5%,
tax: 15%).

## Analysis

Input: name,weekly working hour,bonus rate per hours and base salary

Out put: net salary, bouns and  gross salary

operation: bonus=bonusrate*working hours,gross salary=bonus+base salary,tax=0.15*gross salary, pension=o.5*gross salary and net salary=base salary-tax-pension

## psedocode

* start
* read input name,weekly working hours, bonus rate per hours and base salary
* calculate bonus=bonusrate*working hours
* calculate gross salary=bonus+base salary
* calculate tax=0.15*gross salary
* calculate pension=o.5*gross salary
* calculate net salary=base salary-tax-pension
* print netsalary, gross salary and bunus
* end

```mermaid
   flowchart TD
     A[read input name,weekly working hours, bonus rate per hours and base salary]-->
     B[calculate bonus=bonusrate*working hours]-->
C[calculate gross salary=bonus+base salary]-->
D[ calculate tax=0.15*gross salary]-->
E[calculate pension=o.5*gross salary]-->
F[calculate net salary=base salary-tax-pension]-->
G[print netsalary, gross salary and bunus]-->
H[end]
