# PF-THEORY
## Part B:
### Question No 1: Hostel Booking System
#### IPO Chart:
| **Input** | **Process** | **Output** |
|---|---|---|
| `N` = Number of guests | Set `i = 1` | Final price / total price for each guest |
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
|  | Repeat until all `N` guests are processed | |
|  | Display `Revenue` | |

##### PAC Chart:
| **Problem** | **Analysis / Logic** |
|---|---|
| Number of guests | Input `N` guests and process them one by one |
| Initialize counter | Set `i = 1` |
| Initialize revenue | Set `Revenue = 0` |
| Get guest information | Input `Season`, `RoomType`, and `Nights` |
| Determine season | Check whether `Season = Peak` |
| Peak season | Use Peak rates |
| Peak + Standard | `Rate = Rs. 5000/night` |
| Peak + Deluxe | `Rate = Rs. 8000/night` |
| Peak + Suite | `Rate = Rs. 12000/night` |
| Off-Peak season | Use Off-Peak rates |
| Off-Peak + Standard | `Rate = Rs. 3000/night` |
| Off-Peak + Deluxe | `Rate = Rs. 5000/night` |
| Off-Peak + Suite | `Rate = Rs. 8000/night` |
| Calculate room price | `TotalPrice = Rate × Nights` |
| Check long stay | If `Nights > 7`, apply 15% discount |
| Long-stay discount | `DiscountAmount = TotalPrice × 0.15` |
| Apply discount | `TotalPrice = TotalPrice − DiscountAmount` |
| No long-stay discount | If `Nights ≤ 7`, keep original `TotalPrice` |
| Calculate hotel revenue | `Revenue = Revenue + TotalPrice` |
| Process next guest | `i = i + 1` |
| Check remaining guests | If `i ≤ N`, process next guest |
| All guests processed | Display `Revenue` |
| End | Terminate the program |



### Question No 2:
#### IPO Chart:
| **Input** | **Process** | **Output** |
|---|---|---|
| Requested Floor | Set `i = 0` as current floor | Moving Up |
| Number of Floors `n` | Check `i ≤ n` | Moving Down |
|  | Compare Requested Floor with Current Floor | Going Floor / Floor Reached |
|  | If Requested Floor > Current Floor → move up |  |
|  | If Requested Floor < Current Floor → move down |  |
|  | If Requested Floor = Current Floor → floor reached |  |
|  | Increment `i = i + 1` |  |

##### PAC Chart:
| **Problem Analysis** | **Details** |
|---|---|
| **Problem** | Determine the elevator's movement according to the requested floor and current floor. |
| **Input** | Number of floors `n` and requested floor |
| **Variables** | `n`, `i`, Requested Floor |
| **Initialization** | `i = 0` |
| **Condition 1** | `i ≤ n` |
| **Condition 2** | Requested Floor > Current Floor |
| **Condition 3** | Requested Floor < Current Floor |
| **Condition 4** | Requested Floor = Current Floor |
| **Processing** | Compare requested floor with current floor and determine elevator direction. |
| **Output 1** | `Print Moving Up` |
| **Output 2** | `Print Moving Down` |
| **Output 3** | `Print Floor Reached / Going Floor` |
| **Loop Update** | `i = i + 1` |
| **Termination** | Stop when `i > n`. |


