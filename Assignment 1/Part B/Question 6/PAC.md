Smart EV Charging & Parking Management System — IPO Chart
Given Data / Input	Processing Required	Required Result / Output
Vehicle Type: E / H	Check vehicle type and charging eligibility. E can charge. H can charge only if SOC < 40%.	Vehicle type + charging eligibility
Battery Level (SOC %)	Compare SOC with required charging level and priority conditions.	Current battery percentage
Required Charging Level (%)	Calculate: Required Charging = Required Charging Level − Current Battery Level. If result ≤ 0, no charging is required.	Required charging percentage / “No charging required”
Charging Station Available: Y/N	If station unavailable: H → “Charging unavailable — Parking only.” Otherwise → “No charging slot available.” If available, continue checks.	Charging availability / parking-only message
Vehicle Type + SOC	E can use charging station. H can use it only when SOC < 40%; otherwise → “Vehicle does not qualify for EV charging.”	Charging qualification
SOC + Required Charging Level + Disabled Status + Membership	Determine priority in this order: P1 Emergency: SOC ≤ 15% AND required charging ≥ 80%. P2 Priority: disabled = Y OR (member = Y AND SOC ≤ 30%). Otherwise P3 Normal.	Emergency Charging Priority / Priority Charging / Normal Charging
Current Time (24-hour)	If time is before 5 PM or after 10 PM → Off-peak. If 5 PM–10 PM → Peak.	Peak / Off-peak status
Charging Priority + Time + Membership	Off-peak rate = Rs. 35/unit. Member gets 20% discount during off-peak. Peak rate = Rs. 50/unit. Member gets 10% discount during peak. Emergency priority gets no membership discount.	Charging rate + charging discount
Required Charging + Charging Rate	Calculate charging cost according to required charging and applicable rate/discount.	Charging cost
Expected Parking Duration (hours)	≤ 2 hours → Rs. 200. More than 2 and up to 5 → Rs. 400. More than 5 → Rs. 700.	Base parking cost
Membership + Disabled Status	Member → 20% parking discount. Disabled-priority customer → free parking. Parking discount does not apply to charging charges.	Parking discount + final parking cost
Expected Parking Duration	If duration > 8 hours → “Long-stay warning: Please relocate your vehicle after charging.” Otherwise → “Standard parking duration.”	Appropriate parking warning/message
Charging Cost + Parking Cost − Discounts	Calculate final payable amount.	Final Payable Amount
