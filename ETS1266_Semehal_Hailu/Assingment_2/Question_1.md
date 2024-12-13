# Algorithm

## Question

Develop a program that find the Net-Pay of an employee after deduction of pension (7%) and tax based on tax rate provided. The

program should read the basic salary, worked hours, and bonus rate. If the employee worked hours exceed 40 hrs., the program

prompts the user to enter an over-time bonus rate/hour.

### Tax rate 

* up to 200 birr 0% rate
* 200 to 600 birr 10% rate
* 600 to 1200 birr 15% rate
* 1200 to 2000 birr 20% rate
* 2000-3500 birr 25% rate
* above 3500 birr 30% rate

 ## Psedocode 

```***

S1: start

S2: read input(basic salary,worked hours)

S3: if woking hour excedes 40 then calculate extra working hour= woking hour-40

S4: read overtime bonus rate 

S5: calculate bonus as bonus= overtime bonus rate * extra working hour

S6: calculate pention as pention =0.7*basic salary

S7: calcualte gross salary as  gross salary= basic salary+bonus 

S8: if gross salary<200 then tax=0

S9: if gross salary<600 and gross sa;ary >200 then tax= 0.1*gross salary,

S10: if gross salary<1200 and gross salary>600 then tax=0.15*gross salary,

S11: if gross salary<2000 and gross salary>1200 then tax=0.2* gross salary

S12: if gross salary<3500 and gross salary>2000 then tax=0.25*gross salary

S13: if gross salary>3500 then tax=0.3*gross salary

S14: net salary=gross salary-pension-tax

S15: print net salary 

S16: end
