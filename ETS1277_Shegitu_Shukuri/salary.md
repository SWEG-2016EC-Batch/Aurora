 Design an algorithm and write a to read an employee name weekly working hours, bonus rate per hour and
base salary and find the employees gross-salary, net salary and bonus payment. (Hint: pension rate – 5%,
tax: 15%). 

## Input
- employee's name
  
- number of weekly working hours
  
- bonus rate per hour
  
- base salary
  
## Output 
- gross salary
              as gross salary = base salary + (weekly working hour * bonus rate)
  
- pension deduction
              as pension dedicution = 0.05 * gross salary
  
 - tax deduction 
              as tax deduction = 0.15* gross salary
  
 - net salary
              as net salary = gross salary -(pension deduction* tax deduction)
  
 - total bonus payment
              as bonus payment = weekly working hours* bonus rate

Algorithm

* step1: start
* step2: read the employee's name
* step3: read the number of weekly working hours
* step4: read the bonus rate per hour
* step5: read the base salary
* step6: calculate gross salary (gross salary=  base salary + (weekly working hour * bonus rate))
* step7: calculate the pension deduction ( pension deduction = 0.05 * gross salary)
* step8: calculate the tax deduction (tax deduction = 0.15* gross salary)
* step9: calculate the net salary (gross salary -(pension deduction * tax deduction))
* step10: calculate the total bonus payment( bonus payment = weekly working hours* bonus rate)
* step11: print employee's name, gross salary, net salary,and bonus payment
* step11: end

```mermaid
graph TD
A[start]-->B[input the employee's name, weekly working hours, bonus rate per hour, base salary]-->C[calculate gross salary, gross salary=  base salary + weekly working hour * bonus rate]-->D[ calculate the pension deduction  pension deduction = 0.05 * gross salary]-->E[calculate the tax deduction, tax deduction = 0.15* gross salary]-->F[calculate the net salary, net salary = gross salary -pension deduction * tax deduction]-->G[calculate the total bonus payment, bonus payment = weekly working hours* bonus rate]-->H[calculate the total bonus payment, bonus payment = weekly working hours* bonus rate]-->I[print employee's name, gross salary, net salary,and bonus payment]-->J[end]
