# Detailed Design Document

| **Author**              | `Ahmed M Shahin`                                       |
|:------------------------|:-----------------------------------------------------|
| **Status**              | `Draft/Inspection/Approved`                          |
| **Version**             | `1.0`                                                |
| **Date**                | `2/10/2025`                                         |

## Introduction
As we normally see over radars how data is transferred quickly from distance and time to speed then its transferred to police stations using network , it is so quick that its almost as in instance transferred. This helps the user to control data faster that way they can utilize it even faster. 
### Purpose
During this assessment we implemented UART communication using a button and a led. To accomplish using an input and an output using embedded C language to program an Arduino to deliver data or input data for data exchange

### Main Content

In our code we first define the pins used for Led and Button separately. The next step is setting up Led as an output and Button as an input while enabling the pull up resistor. Moreover, we used 1 when button was pressed as high and 0 as button was released as low. Making led high on 1 and low on 0. And if button was pressed or released it would show in output.


