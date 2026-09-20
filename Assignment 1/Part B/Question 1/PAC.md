# Hotel Booking System 
## PAC Chart
| Given Data | Processing Required | Required Result |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Number of guests `N` | Set the loop to process `N` guests. | All guests processed |
| Guest number `i` | Process each guest one by one using the loop. | Current guest selected |
| Season `Peak / Off-Peak` | Check whether the season is Peak or Off-Peak. | Applicable season determined |
| Room type `Standard / Deluxe / Suite` | Check the selected room type and apply the corresponding room rate. | Applicable room rate |
| Peak + Standard | Apply Peak Standard rate = `Rs. 5,000/night`. | Rate = Rs. 5,000/night |
| Peak + Deluxe | Apply Peak Deluxe rate = `Rs. 8,000/night`. | Rate = Rs. 8,000/night |
| Peak + Suite | Apply Peak Suite rate = `Rs. 12,000/night`. | Rate = Rs. 12,000/night |
| Off-Peak + Standard | Apply Off-Peak Standard rate = `Rs. 3,000/night`. | Rate = Rs. 3,000/night |
| Off-Peak + Deluxe | Apply Off-Peak Deluxe rate = `Rs. 5,000/night`. | Rate = Rs. 5,000/night |
| Off-Peak + Suite | Apply Off-Peak Suite rate = `Rs. 8,000/night`. | Rate = Rs. 8,000/night |
| Number of nights | Calculate base price: `rate × nights`. | Base price |
| Number of nights `> 7` | Calculate 15% long-stay discount on the total price. | 15% discount |
| Number of nights `<= 7` | No long-stay discount is applied. | Discount = Rs. 0 |
| Base price + discount | Calculate `Total Price = (rate × nights) − discount`. | Final price for guest |
| Guest's final price | Add the guest's final price to the running hotel revenue. | Updated Hotel Total Revenue |
| All `N` guests | Repeat the process until all guests are processed. | All guest bookings processed |
| Running Hotel Total Revenue | Display the accumulated revenue after the loop ends. | **Hotel Total Revenue** |
