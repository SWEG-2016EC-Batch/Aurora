# Algorithm
## Psedocode
START PROGRAM  

  DECLARE variables:   
        num, choice, temp, digit, rev, count, prod, first, last, sum, newNum, freq, strong, perfect  
        SET isPalindrome TO true  
 LABEL numb  
    INPUT num  
    SET temp = num  
    
    
  PRINT "1. Reverse of the number"  
    PRINT "2. Number of digits"  
    PRINT "3. Product of even digits"  
    PRINT "4. First and last digit"  
    PRINT "5. Swap first and last digit"  
    PRINT "6. Palindrome"  
    PRINT "7. Frequency of first digit"  
    PRINT "8. Strong number"  
    PRINT "9. Perfect number"  
    PRINT "10. Exit"  

PRINT "Enter your choice: "  
INPUT choice  

if  choice=1 then 
    Reverse of the number  
         rev = 0  
        if temp > 0 then
            calculate digit = temp MOD 10  
            calculate rev = rev * 10 + digit  
            Calculate temp /= 10  
            
  PRINT  
            > rev  

 if  choice=2  then  
 Number of digits  
       count = 0  
        if temp > 0 then
          INCREMENT count  
          Calculate temp/= 10  
       
  PRINT 
           >count  

if  choice=3  then 
Product of even digits  
        Calculate  prod = 1  
        if temp > 0 then
            Calculate  digit = temp % 10  
            IF digit MOD 2 = 0 THEN  
              Calculate  prod = prod * digit  
       Calculate temp /= 10  
       
  PRINT
         >prod  

 if  choice=4  then
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

 if  choice=4  then
 Swap first and last digit  
      SET newNum = 0  
        WHILE temp > 0 DO  
            SET digit = temp MOD 10  
            IF digit == first THEN  
                SET digit = last  
            ELSE IF digit == last THEN  
                SET digit = first  
            END IF  
            SET newNum = newNum * 10 + digit  
            SET temp = temp DIV 10  
        END WHILE  
        PRINT "Number after swapping: ", newNum  
        
  CASE 6: // Palindrome check  
      SET tempRev = num  
      SET rev = 0  // Reset rev for palindrome check  
      WHILE tempRev > 0 DO  
          SET digit = tempRev MOD 10  
          SET rev = rev * 10 + digit  
          SET tempRev = tempRev DIV 10  
      END WHILE  
      IF num == rev THEN  
          PRINT "Palindrome: Yes"  
      ELSE  
          PRINT "Palindrome: No"  
      END IF  
      
  CASE 7: // Frequency of first digit  
      SET freq = 0  
      temp = num  // Reset temp for frequency count  
      WHILE temp > 0 DO  
          SET digit = temp MOD 10  
          IF digit == first THEN  
              INCREMENT freq  
          END IF  
            SET temp = temp DIV 10  
        END WHILE  
        PRINT "Frequency of first digit: ", freq  
        
  CASE 8: // Strong number check  
      SET strong = 0  
      temp = num  // Reset temp for strong number check  
      WHILE temp > 0 DO  
          SET digit = temp MOD 10  
          SET fact = 1  
          FOR i FROM 1 TO digit DO  
              SET fact = fact * i  
          END FOR  
          SET strong = strong + fact  
          SET temp = temp DIV 10  
      END WHILE  
      IF strong == num THEN  
          PRINT "Strong number: Yes"  
      ELSE  
          PRINT "Strong number: No"  
      END IF  
      
  CASE 9: // Perfect number check  
      SET perfect = 0  
      FOR i FROM 1 TO num - 1 DO  
          IF num MOD i == 0 THEN  
              SET perfect = perfect + i  
          END IF  
      END FOR  
        IF perfect == num THEN  
            PRINT "Perfect number: Yes"  
        ELSE  
            PRINT "Perfect number: No"  
        END IF  
        
   CASE 10: // Exit  
        PRINT "Exiting..."  
    
// Ask if user wants to continue  
PRINT "If you want to continue press 1, otherwise press 0"  
INPUT num1  
IF num1 == 1 THEN  
    GOTO numb // Return to the number input step  
ELSE  
    PRINT NEW LINE  
END IF  
