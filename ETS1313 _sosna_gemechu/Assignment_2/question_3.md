# Algorithm
## Psedocode
1. START PROGRAM  

2. DECLARE variables:    num, choice, temp, digit, rev, count, prod, first, last, sum, newNum, freq, strong, perfect  
        SET isPalindrome TO true  
3.  LABEL numb  
4. INPUT num  
    SET temp = num  
    
    
5. PRINT "1. Reverse of the number"  
6. PRINT "2. Number of digits"  
7. PRINT "3. Product of even digits"  
8. PRINT "4. First and last digit"  
9. PRINT "5. Swap first and last digit"  
10. PRINT "6. Palindrome"  
11. PRINT "7. Frequency of first digit"  
12. PRINT "8. Strong number"  
13. PRINT "9. Perfect number"  
14. PRINT "10. Exit"
15.  read INPUT choice  

* if  choice=1 then 
    Reverse of the number  
         rev = 0  
        if temp > 0 then
            calculate digit = temp MOD 10  
            calculate rev = rev * 10 + digit  
            Calculate temp /= 10  
            
  PRINT  
            > rev  

* if  choice=2  then  
 Number of digits  
       count = 0  
        if temp > 0 then
          INCREMENT count  
          Calculate temp/= 10  
       
  PRINT 
           >count  

* if  choice=3  then 
Product of even digits  
        Calculate  prod = 1  
        if temp > 0 then
            Calculate  digit = temp % 10  
            IF digit MOD 2 = 0 THEN  
              Calculate  prod = prod * digit  
       Calculate temp /= 10  
       
  PRINT
         >prod  

* if  choice=4  then
       Calculate first = 0  
     Calculatelast = 0  
      if temp > 0 then
           Calculate digit = temp % 10  
          IF first = 0 THEN  
               first = digit  
      ELSE     last = digit  
           Calculate temp /n 10  
       Calculate sum = first + last  
      PRINT 
           >first  
      PRINT 
            >last  
      PRINT
            >sum  

* if  choice=5  then
 Swap first and last digit  
       newNum = 0  
       if temp > 0 then
            Calculate digit = temp % 10  
            IF digit = first THEN  
                digit = last  
            ELSE IF digit == last THEN  
                digit = first  
             Calculate newNum = newNum * 10 + digit  
            Calculate temp = temp /=10  
         PRINT 
                >newNum  
        
* if  choice=6  then 
 Palindrome check  
      SET tempRev = num  
      SET rev = 0  // Reset rev for palindrome check  
      WHILE tempRev > 0 DO  
         Calculate digit = tempRev MOD 10  
          Calculate rev = rev * 10 + digit  
         Calculate tempRev = tempRev /= 10  
     
   IF num = rev THEN  
          PRINT 
          >Yes  
      ELSE  
          PRINT 
           >No  
     
* if  choice=7  then
 Frequency of first digit  
       freq = 0  
      temp = num  // Reset temp for frequency count  
     if temp > 0 then 
          Calculate digit = temp MOD 10  
          IF digit == first THEN  
              INCREMENT freq  
          END IF  
            Calculate temp = temp/= 10  
        END WHILE  
        PRINT 
             >freq  
        
*  if  choice=8  then
  Strong number check  
       strong = 0  
      temp = num  // Reset temp for strong number check  
     if temp > 0 then
          Calculate digit = temp /= 10  
          Calculate fact = 1  
          FOR i FROM 1 TO digit DO  
              Calculate fact = fact * i  
          END FOR  
          Calculate strong = strong + fact  
         Calculate temp /=10  
       IF strong = num THEN  
          PRINT 
               >Yes  
      ELSE  
          PRINT 
               >No  
   
      
*  if  choice=9  then
  Perfect number check  
      perfect = 0  
      FOR i FROM 1 TO num - 1 DO  
          IF num % i = 0 THEN  
              Calculate perfect = perfect + i  
        IF perfect = num THEN  
            PRINT 
                 >Yes  
        ELSE  
            PRINT 
                 >No  
       
        
*   if  choice=10  then
   Exit  
        PRINT 
              >Exiting... 
    
// Ask if user wants to continue  
16. READ INPUT as num1  
* IF num1 = 1 THEN  
    GOTO numb // Return to the number input step  
* ELSE  
    PRINT NEW LINE  
17. END IF  
