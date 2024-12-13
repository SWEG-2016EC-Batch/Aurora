/* Develop a program that find the Net-Pay of an employee after
deduction of pension (7%) and tax based on tax rate provided. The
program should read the basic salary, worked hours, and bonus
rate. If the employee worked hours exceed 40 hrs., the program
prompts the user to enter an over-time bonus rate/hour. */

# psedocode of net salary
* start
* read the basic salary, worked hours, and bonus rate.

   if(worked_hours>40)
        read input as over time bonus rate
* calculate
  
     extra_work_hours=worked_hours-40
  
    bonus=extra_work_hours*bonus_rate
  
    gross_salary=basic_salary+bonus
  
     if(basic_salary<=200)
  
  calculate  tax=gross_salary*0;
  
     if(basic_salary>200&&basic_salary<=600)
  
     calculate tax=gross_salary*0.1
  
   if(basic_salary>600&&basic_salary<=1200)

    calculate tax=gross_salary*0.15
  
     if(basic_salary>1200&&basic_salary<=2000)
  
calculate  tax=gross_salary*0.2

  if(basic_salary>2000&&basic_salary<=3500)
     
   calculate tax=gross_salary*0.25
   
  if(basic_salary>3500)
  
  calculate  tax=gross_salary*0.3
  * print net salary, gross salary, bonus, tax and extra work hours
