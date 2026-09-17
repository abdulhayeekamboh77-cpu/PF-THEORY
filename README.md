# PF-THEORY
## Part B:
### Question No 1: Hostel Booking System
#### IPO Chart:
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

##### PAC Chart:
| **Problem** | **Analysis / Decision** |
|---|---|
| Determine room rate | If Season = Peak, use Peak rates |
| Peak + Standard | Rate = Rs. 5,000/night |
| Peak + Deluxe | Rate = Rs. 8,000/night |
| Peak + Suite | Rate = Rs. 12,000/night |
| Off-Peak + Standard | Rate = Rs. 3,000/night |
| Off-Peak + Deluxe | Rate = Rs. 5,000/night |
| Off-Peak + Suite | Rate = Rs. 8,000/night |
| Calculate room cost | `Rate × Nights` |
| Long-stay discount | If Nights > 7 → 15% discount |
| No long-stay discount | If Nights ≤ 7 → discount = 0 |
| Final guest price | `Total Price − Discount` |
| Hotel revenue | Add every guest's final price to running total |
| Processing | Process all `N` guests |
