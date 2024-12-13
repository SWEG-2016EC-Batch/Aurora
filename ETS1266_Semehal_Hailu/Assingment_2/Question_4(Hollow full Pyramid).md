# Algorithm

## Psedocode 

```

S1:START  

S2:DECLARE INTEGER variable: n  

S3:SET n = 6 

S4:FOR i FROM 1 TO n DO  
    
S5:FOR k FROM (n - i) DOWN TO 1 DO  

        PRINT " " 
        
END FOR  

S6:FOR j FROM 1 TO i DO  
       
S7:IF (i == n OR j == i OR j == 1) THEN  

            PRINT "* "
            
            ELSE  
            
            PRINT "  "         
        END IF 
        
    END FOR 
    
S8:PRINT newline          

END FOR  

S9:End
