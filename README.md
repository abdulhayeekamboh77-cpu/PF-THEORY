# PF-THEORY
## Part B:
### Question No 1:
| **Input** | **Process** | **Output** |
|---|---|---|
| Number of guests `N` | Initialize `Hotel Total Revenue = 0` | Final price for each guest |
| Season (Peak / Off-Peak) | Determine base rate according to season | Discount amount, if applicable |
| Room Type (Standard / Deluxe / Suite) | Select rate according to room type and season | Final price after discount |
| Number of nights stayed | Calculate `Total Price = Rate × Nights` | Hotel Total Revenue |
|  | If nights > 7, calculate 15% discount |  |
|  | Subtract discount from total price |  |
|  | Add guest's final price to Hotel Total Revenue |  |
|  | Repeat processing for all N guests |  |
