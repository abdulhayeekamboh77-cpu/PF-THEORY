/*Programmer: Abdul Hayee Kamboh
Program: Greenhouse Temperature Monitoring System
Roll No: 26K-0026
Section: BSAI-1A*/
Question # 3: 
Greenhouse Temperature Monitoring System 
A greenhouse manager uses multiple temperature sensors to monitor the temperature inside a greenhouse. Each sensor records the temperature in degrees Celsius at the end of every hour. The readings are stored in a two-dimensional array, where each row represents a sensor and each column represents an hourly reading. 
The manager wants to analyze the recorded temperatures to identify potentially dangerous conditions for the plants. 
Write a C program using functions and a two-dimensional array to perform the following tasks: 
1.	Input Data: Input the number of sensors and the number of hourly readings from the user. Store the temperature readings for every sensor and every hour in a twodimensional array. 
2.	Input Function: Write a function to input all temperature readings into the twodimensional array. 
3.	Sensor Analysis Function: Write a function that receives the readings of a sensor and calculates the following: 
o	Total of all temperature readings. o 	Average temperature, displayed up to two decimal places. 
o	Highest and lowest temperature readings. 
o	Number of critical readings (temperature of 40°C or above). o 	Number of warning readings (temperature between 35°C and 39°C, inclusive). 
o	Longest streak of consecutive hours during which the temperature remained at 35°C or above. 
4.	Individual Reports: Display a separate report for each sensor containing all the calculated statistics. 
5.	Highest Average Function: Write a separate function to determine and return the sensor number with the highest average temperature. 
6.	Final Report: Display the sensor number with the highest average temperature along with its average reading. 
Requirements: 
•	Use a two-dimensional array to store the temperature readings. 
•	Use separate user-defined functions for inputting readings, analyzing a sensor's readings, and identifying the sensor with the highest average temperature. 
•	Pass the required array elements and values as function arguments. 
•	Use appropriate return values wherever necessary. 
•	Display all average temperatures with exactly two decimal places. 
•	Assume that at least one sensor and one hourly reading will be entered by the user. Sample input (3 sensors, 6 readings each):  
  
 Sample output:  
  
 Note: A streak is a run of readings that are next to each other in the same row. A reading below 35 ends the streak and the count starts again.  
 
Question # 4: 
Bakery Festival Sales Management System 
A bakery participates in a food festival that runs for several days. Each day, the bakery receives a different number of customer orders, and each order has a different sale amount. The owner wants to generate a sales summary to evaluate the bakery's performance throughout the festival. 
Write a C program using loops, arrays, and user-defined functions to perform the following tasks: 
1. Input Festival Duration 
Ask the user to enter the number of festival days. The value must be between 1 and 7. If an invalid value is entered, keep asking until a valid value is provided. 2. Daily Order Processing For each festival day: 
•	Input the number of customer orders received. 
•	Input the amount in rupees for each order. Each amount must be greater than zero. If an invalid amount is entered, ask again for the same order. 
•	Calculate and display the total sales, average order amount (two decimal places), and highest order amount for that day. 
3.	Festival Sales Summary 
After processing all days, display the total sales for the entire festival and the day number with the highest total sales. If multiple days have the same highest sales, display the earliest such day. 
 
 
