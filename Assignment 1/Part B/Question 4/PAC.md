# Online Shopping Bill Calculator
## PAC Chart
| Given Data | Processing Required | Required Result |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Quantity of products `q` | Check whether quantity is valid. Calculate `s = q × p`. | Subtotal |
| Price per item `p` | Check whether price is valid and use it to calculate subtotal. | Price per item / Subtotal |
| Quantity `q` + Price `p` | Apply Subtotal function: `s = q × p`. | Subtotal amount |
| Discount percentage `d` | Validate discount percentage and calculate `s - (s × d) / 100`. | Discounted amount |
| Subtotal `s` + Discount `d` | Apply Discounted Amount function: `a = s - (s × d) / 100`. | Discounted amount |
| Tax percentage `t` | Validate tax percentage and calculate tax on discounted amount. | Tax amount |
| Discounted amount `a` + Tax `t` | Apply Final Bill function: `Final Bill = a + (a × t) / 100`. | Final bill amount |
| Quantity `q` | Check if quantity is invalid. | Appropriate error message |
| Price per item `p` | Check if price is invalid. | Appropriate error message |
| Discount percentage `d` | Check if discount percentage is invalid. | Appropriate error message |
| Tax percentage `t` | Check if tax percentage is invalid. | Appropriate error message |
| All entered values | If any value is invalid, terminate the calculation. | Error message / Calculation terminated |
| Valid calculation details | Store quantity, price, discount, tax and calculated amounts. | Stored calculation details |
| Stored calculation details | Generate a bill document. | Bill document |
| Final bill amount | Display the completed bill to the customer. | Final bill displayed |
