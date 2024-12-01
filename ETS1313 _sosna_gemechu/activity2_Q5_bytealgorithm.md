## psedocode and flowchart of
A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long
it will take to send a file, given the file size. Test your program on a 400MB (419,430,400 byte) file which may
take days.

##psedocode
* start
* read in put file size
* Calculate Time in Seconds(time_in_second = size / 0.00096)
* Calculate Time in hours(time_in_hours = time_in_second / 24)
*  Calculate Time in days(time_in_days = time_in_hours/ 0.00096)
*  print (time_in_second, time_in_hours and time_in_days)
*  end











## flow chart of the above psedocode
```mermaid
flowchart TD
    A[Start] --> B[Input File Size]
    B --> C[Calculate Time in Seconds]
    C --> D[Calculate Time in Hours]
    D --> E[Calculate Time in Days]
    E --> F[Output Time in Seconds, Hours, and Days]
    F --> G[End]

    C -->|time_in_second = size / 0.00096| C
    D -->|time_in_hour = time_in_second / 3600| D
    E -->|time_in_day = time_in_hour / 24| E
