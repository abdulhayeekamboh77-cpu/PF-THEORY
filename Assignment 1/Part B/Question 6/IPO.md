# Smart EV Charging and Parking Management System
## IPO Chart
| Input | Processing | Output |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Vehicle type `E / H` | Check whether vehicle is Electric or Hybrid. | Vehicle type and charging eligibility |
| Battery charge level `SOC %` | Store current battery percentage. | Current battery percentage |
| Required charging level `%` | Calculate `Required Charging = Required Level - Current SOC`. | Required charging percentage |
| Charging station `Y / N` | Check whether charging station is available. | Charging availability message |
| Vehicle type + SOC | E is eligible. H is eligible only if `SOC < 40%`. | Charging qualification result |
| Required charging % | If required charging `<= 0`, charging is not required. | `No charging required` |
| SOC + Required charging | Check `SOC <= 15%` AND required charging `>= 80%`. | `Emergency Charging Priority` |
| Disabled status `Y / N` | If emergency condition is false, check disabled-person priority. | Priority condition |
| Membership `Y / N` + SOC | If member is `Y` AND `SOC <= 30%`, assign priority. | `Priority Charging` |
| Priority conditions | If no priority condition is satisfied, assign normal priority. | `Normal Charging` |
| Current time `24-hour` | Before 17:00 or after 22:00 = off-peak; 17:00–22:00 = peak. | Peak / Off-peak status |
| Charging priority + time | Select charging rate: Off-peak = Rs. 35/unit; Peak = Rs. 50/unit. | Charging rate |
| Membership + off-peak | Apply 20% charging discount for members. | Charging discount |
| Membership + peak | Apply 10% charging discount for members. | Charging discount |
| Emergency priority | Do not apply membership charging discount. | No membership discount |
| Required charging + charging rate | Calculate charging cost after applicable discount. | Charging cost |
| Parking duration `hours` | If `<= 2` hours, charge Rs. 200. | Parking cost = Rs. 200 |
| Parking duration `hours` | If `> 2` and `<= 5` hours, charge Rs. 400. | Parking cost = Rs. 400 |
| Parking duration `hours` | If `> 5` hours, charge Rs. 700. | Parking cost = Rs. 700 |
| Membership `Y / N` | Apply additional 20% parking discount for members. | Parking discount |
| Disabled-person priority `Y` | Give free parking. | Parking cost = Rs. 0 |
| Parking duration `hours` | If duration `> 8` hours, generate long-stay warning. | `Long-stay warning` |
| Parking duration `hours` | If duration `<= 8` hours, generate normal message. | `Standard parking duration` |
| Charging cost + parking cost | Add charging and parking charges. | Total cost |
| Charging and parking discounts | Subtract applicable discounts from the charges. | Final payable amount |
| All calculated results | Display complete system information. | Vehicle type, battery %, required charging %, priority, peak/off-peak status, charging cost, parking cost, discount, final payable amount and warning/message |
