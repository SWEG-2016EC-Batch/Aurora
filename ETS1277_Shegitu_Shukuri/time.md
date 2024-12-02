A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long
it will take to send a file, given the file size. Test your program on a 400MB (419,430,400 byte) file which may
take days.

## Input 
- size of file in MB
  
## Operation:
  -size in bytes = size*1024*1024
  
  -time in secinds = size in bytes / transmission rate
  
  -time in hours = time in seconds / 3600
  
  -time in days = time in hours / 24
  
## Out put
- time taken in seconds, hours, days.

Algorithm
* step1: start
* step2: input the file of size in MB
* step3: convert the input size from MB to bytes (size in bytes = size*1024*1024)
* step4: calculate time in seconds( time in seconds = size in bytes/transmission rate
* step5: calculate time in hours (time in seconds/3600)
* step6: calculate time in days (time in hours/24)
* step7: print time taken in seconds, hours and days
* step8: end
```mermaid
graph TD
A[start]-->B[input the file of size in MB]-->C[convert  MB to bytes, size in bytes = size*1024*1024]-->D[calculate time in seconds, time in seconds = size in bytes/transmission rate]-->E[calculate time in hours, time in seconds/3600]-->F[calculate time in days, time in hours/24]-->G[print time taken in seconds, hours and days]-->H[end]
