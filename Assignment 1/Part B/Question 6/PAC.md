# Smart EV Charging and Parking Management System
## PAC Chart
| Given Data | Processing Required | Required Result |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Vehicle type `E / H` | Check whether the vehicle is fully electric or hybrid | Vehicle type and charging eligibility |
| Battery charge level `SOC %` | Store and compare current battery level with required charging level | Current battery percentage |
| Required charging level `%` | Calculate `Required Charging = Required Level - Current SOC` | Required charging percentage |
| Charging station `Y / N` | Check whether the charging station is available | Charging available / unavailable message |
| Vehicle type + SOC | If `E`, allow charging. If `H`, allow charging only when `SOC < 40%` | Charging qualification result |
| Required charging + SOC | If required charging `<= 0`, no charging is required | `No charging required` |
| SOC + Required charging | Check emergency condition: `SOC <= 15%` AND `Required Charging >= 80%` | `Emergency Charging Priority` |
| Disabled status `Y / N` | If emergency condition is false, check whether disabled status is `Y` | Priority charging condition |
| Membership `Y / N` + SOC | If member is `Y` AND `SOC <= 30%`, assign priority | `Priority Charging` |
| Priority conditions | If no priority condition is satisfied | `Normal Charging` |
| Current time (24-hour) | If time is before `17:00` or after `22:00`, select off-peak | `Off-peak` status |
| Current time (24-hour) | If time is from `17:00` to `22:00`, select peak | `Peak` status |
| Charging priority + time | Off-peak rate = `Rs. 35/unit`; Peak rate = `Rs. 50/unit` | Applicable charging rate |
| Membership + off-peak | Apply `20%` charging discount if customer is a member | Charging discount |
| Membership + peak | Apply `10%` charging discount if customer is a member | Charging discount |
| Emergency priority | Do not apply membership charging discount | No membership discount |
| Required charging + charging rate | Calculate charging cost after applicable charging discount | `Charging Cost` |
| Expected parking duration | If duration `<= 2` hours, parking charge = `Rs. 200` | Parking cost = Rs. 200 |
| Expected parking duration | If duration `> 2` and `<= 5` hours, parking charge = `Rs. 400` | Parking cost = Rs. 400 |
| Expected parking duration | If duration `> 5` hours, parking charge = `Rs. 700` | Parking cost = Rs. 700 |
| Membership `Y / N` | Member receives an additional `20%` parking discount | Parking discount |
| Disabled priority `Y` | Give free parking; parking discount applies only to parking charges | Parking cost = Rs. 0 |
| Expected parking duration | If duration `> 8` hours, display long-stay warning | `Long-stay warning` |
| Expected parking duration | If duration `<= 8` hours, display normal message | `Standard parking duration` |
| Charging cost + parking cost | Add applicable charging and parking charges | Total cost |
| All applicable discounts | Subtract charging and parking discounts | `Final Payable Amount` |
| All input and processing results | Display complete system information | Vehicle type, SOC, required charging, priority, peak/off-peak status, charging cost, parking cost, discount, final amount and warning/message |
