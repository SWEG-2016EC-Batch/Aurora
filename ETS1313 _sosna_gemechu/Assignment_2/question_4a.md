### Pseudocode Using Only Statements

```
START  
DO  
    PRINT "1: rectangle of numbers"  
    PRINT "2: Rectangle of uppercase Alphabets"  
    PRINT "3: Incremental number pyramid"  
    PRINT "4: Reversed incremental number pyramid"  
    PRINT "5: Alphabetic half pyramid"  
    PRINT "6: Rectangle of lowercase Alphabets"  
    PRINT "7: Hollow star rectangle"  
    PRINT "8: Inverted star half pyramid"  
    PRINT "9: Hollow inverted star pyramid"  
    PRINT "10: Star pyramid"  
    PRINT "11: Inverted star pyramid"  
    PRINT "12: Hollow star pyramid"  
    PRINT "Enter the choice of pattern"  
    INPUT choice  

    SWITCH choice  
        CASE 1  
            FOR i FROM 1 TO 5  
                FOR j FROM 1 TO 5  
                    PRINT j  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 2  
            SET letter TO 'A'  
            FOR i FROM 1 TO 5  
                FOR j FROM 1 TO 5  
                    PRINT letter  
                    IF letter EQUALS 'Z' THEN BREAK  
                    INCREMENT letter  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 3  
            FOR i FROM 1 TO 5  
                FOR j FROM 1 TO i  
                    PRINT j  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 4  
            FOR i FROM 1 TO 5  
                FOR k FROM (5 - i) DOWN TO 1  
                    PRINT " "  
                END FOR  
                FOR j FROM i DOWN TO 1  
                    PRINT j  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 5  
            FOR i FROM 1 TO 5  
                SET letter TO 'A'  
                FOR j FROM 1 TO i  
                    PRINT letter  
                    INCREMENT letter  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 6  
            FOR i FROM 1 TO 5  
                SET letter TO 'a'  
                FOR j FROM 1 TO 5  
                    PRINT letter  
                    INCREMENT letter  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 7  
            FOR i FROM 1 TO 5  
                FOR j FROM 1 TO 5  
                    IF i EQUALS 1 OR i EQUALS 5 OR j EQUALS 1 OR j EQUALS 5  
                        PRINT "*"  
                    ELSE  
                        PRINT " "  
                    END IF  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 8  
            FOR i FROM 1 TO 5  
                FOR j FROM 5 DOWN TO i  
                    PRINT "*"  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 9  
            FOR i FROM 1 TO 5  
                FOR j FROM 5 DOWN TO i  
                    IF i EQUALS 1 OR j EQUALS 5 OR i EQUALS j  
                        PRINT "*"  
                    ELSE  
                        PRINT " "  
                    END IF  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 10  
            FOR i FROM 1 TO 5  
                FOR k FROM (5 - i) DOWN TO 1  
                    PRINT " "  
                END FOR  
                FOR j FROM 1 TO i  
                    PRINT "*"  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 11  
            FOR i FROM 1 TO 5  
                FOR k FROM 1 TO i  
                    PRINT " "  
                END FOR  
                FOR j FROM 5 DOWN TO i  
                    PRINT "*"  
                END FOR  
                PRINT newline  
            END FOR  

        CASE 12  
            FOR i FROM 1 TO 5  
                FOR k FROM (5 - i) DOWN TO 1  
                    PRINT " "  
                END FOR  
                FOR j FROM 1 TO i  
                    IF i EQUALS 1 OR j EQUALS 1 OR j EQUALS i OR i EQUALS 5  
                        PRINT "*"  
                    ELSE  
                        PRINT " "  
                    END IF  
                END FOR  
                PRINT newline  
            END FOR  

        DEFAULT  
            PRINT "Invalid choice"  

    END SWITCH  

    PRINT "Press 1 to continue 0 to exit"  
    INPUT cont  
WHILE cont EQUALS 1  

PRINT "Thank you!!!"  
END  
```
