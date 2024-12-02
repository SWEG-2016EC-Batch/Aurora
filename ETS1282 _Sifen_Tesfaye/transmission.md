/*A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long it will take to send a file, given the file size. Test your program on a 400MB (419,430,400 byte) file which may take days.*/

Analysis:

     Input: size
     Output: time
     Operation: time=size/transimsion rate(0.00096)

pseudocode:


step__1:Start

step__2:Input:

     Prompt the user to enter the size of the file in megabytes (MB).

step__3:Calculate:

    Convert the size from MB to bytes (1 MB = 1,048,576 bytes).
    Calculate the time to transmit the file in seconds using the transmission rate (960 characters/bytes per second).
    Convert the time to hours and days.

step__4:Output:

    Print the time in seconds, hours, and days.

step__5:End:
