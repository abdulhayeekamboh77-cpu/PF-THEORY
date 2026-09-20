# Class Result Processing
## PAC Chart
| Given Data | Processing Required | Required Result |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Number of students `n` | Set the outer loop to process `N` students. | All students processed |
| Student number `i` | Process each student one by one using the outer loop. | Current student selected |
| 5 subject marks | Use an inner loop to input and process 5 subject marks. | Five marks for the student |
| Five subject marks | Calculate `Average = (m1 + m2 + m3 + m4 + m5)/ 5`. | Student average |
| Average `>= 80` | Check whether average is 80 or above. | `Distinction` |
| Average `>= 60` and `< 80` | Check whether average is 60 or above but below 80. | `Pass` |
| Average `< 60` | Check whether average is below 60. | `Fail` |
| Subject marks | Check whether any single subject mark is below 33. | Subject deficiency condition |
| Any mark `< 33` | Override the previous result regardless of average. | `Fail — Subject Deficiency` |
| Student's average + subject marks | Apply classification and subject-deficiency override rules. | Final result for the student |
| Student result | Display the student's total marks and average. | Total and average displayed |
| Final classification | Display the final classification for each student. | `Distinction / Pass / Fail / Fail — Subject Deficiency` |
| Student counter `i` | Increment `i` and continue until all `N` students are processed. | Complete class result |
