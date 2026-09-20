# PF-THEORY
## Assignment 01 Part B: IPO Chart And PAC Chart
### Question No 1: Hostel Booking System
#### IPO Chart:
| **Input** | **Process** | **Output** |
|---|---|---|
| `n` = Number of guests | Set `i = 1` | Final price / total price for each guest |
| `Season` = Peak / Off-Peak | Set `Revenue = 0` | Hotel total revenue |
| `Room Type` = Standard / Deluxe / Suite | Set `Discount = 0.15` | |
| `Nights` stayed | Check season | |
|  | If **Peak**, select rate according to room type | |
|  | Peak + Standard → `Rate = 5000` | |
|  | Peak + Deluxe → `Rate = 8000` | |
|  | Peak + Suite → `Rate = 12000` | |
|  | If **Off-Peak**, select rate according to room type | |
|  | Off-Peak + Standard → `Rate = 3000` | |
|  | Off-Peak + Deluxe → `Rate = 5000` | |
|  | Off-Peak + Suite → `Rate = 8000` | |
|  | Calculate `TotalPrice = Nights × Rate` | |
|  | If `Nights > 7`, calculate `Off = TotalPrice × 0.15` | |
|  | Calculate `TotalPrice = TotalPrice − Off` | |
|  | Add `TotalPrice` to `Revenue` | |
|  | Increment `i = i + 1` | |
|  | Repeat until all `n` guests are processed | |
|  | Display `Revenue` | |
