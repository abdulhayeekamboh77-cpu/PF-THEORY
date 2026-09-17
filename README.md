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



### Question No 2: Elevator Simulation
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



### Question No 3: Class Result Processing
#### IPO Chart:
| **Input** | **Process** | **Output** |
|---|---|---|
| `n` = Number of students | Set `i = 1` | **Distinction** |
| `m1, m2, m3, m4, m5` = 5 subject marks | Calculate `Avg = (u1+u2+u3+u4+u5) / 5` | **Pass** |
|  | Check `Avg > 80` | **Fail** |
|  | Check `Avg ≥ 60` | **Fail due to Subject Deficiency** |
|  | Check whether any subject mark `< 33` | **Result** |
|  | Increment `i = i + 1` |  |
|  | Repeat until `i > n` |  |

##### PAC Chart:
| **PAC Component** | **Details** |
|---|---|
| **Problem** | Calculate the average marks of each student and determine the result. |
| **Input** | Number of students `n` |
| **Input Data** | Five subject marks `m1, m2, m3, m4, m5` |
| **Variables** | `n`, `i`, `m1`, `m2`, `m3`, `m4`, `m5`, `Avg` |
| **Initialization** | `i = 1` |
| **Calculation** | `Avg = (m1 + m2 + m3 + m4 + m5) / 5` |
| **Condition 1** | `Avg > 80` |
| **If Yes** | Display **Distinction** |
| **Condition 2** | `Avg ≥ 60` |
| **If Yes** | Display **Pass** |
| **If No** | Display **Fail** |
| **Condition 3** | Check whether any subject mark `< 33` |
| **If Yes** | Display **Fail due to Subject Deficiency** |
| **Counter Update** | `i = i + 1` |
| **Loop Condition** | `i ≤ n` |
| **Termination** | Stop when `i > n` |



### Question No 4: Online Shopping Bill Calculator
#### IPO Chart:
| **Input** | **Process** | **Output** |
|---|---|---|
| Quantity `q` | Validate input values | Shopping Bill |
| Price `p` | Calculate `Subtotal = q × p` | Quantity |
| Discount `d` (%) | Calculate `Discount Amount = s - (s*d)/100` | Price |
| Tax `t` (%) | Calculate amount after discount | Subtotal |
|  | Calculate Tax Amount | Discount Amount |
|  | Calculate Final Bill | Tax Amount |
|  | Store all calculated values | Final Bill |

##### PAC Chart:
| **PAC Component** | **Details** |
|---|---|
| **Problem** | Calculate the final shopping bill after applying discount and tax. |
| **Inputs** | Quantity `q`, Price `p`, Discount `%` `d`, Tax `%` `t` |
| **Variables** | `q, p, d, t, subtotal, discount, tax, finalBill` |
| **Validation** | Check that quantity, price, discount and tax values are valid. |
| **Step 1** | `subtotal = q × p` |
| **Step 2** | `discount = s - (s*d) / 100` |
| **Step 3** | `finalBill = discount +(discount*t)/100` |
| **Output** | Display shopping bill details. |
| **Termination** | End program after displaying the bill. |



### Question No 5: Smart Campus Parking And Access Management System
#### IPO Chart:
| **INPUT**                    | **PROCESS**                                                           | **OUTPUT**                            |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Number of vehicles `n`       | Set `A = 0`, `B = 0`, `C = 0`                                         | Invalid input message                 |
| Vehicle type `C / B / V`     | Set `capA = 20`, `capB = 40`, `capC = 15`                             | Vehicle assigned to Zone A            |
| Vehicle category `F / S / G` | Set `accepted = 0`, `rejected = 0`                                    | Vehicle assigned to Zone B            |
| Permit `Y / N`               | Set `cars = 0`, `bikes = 0`, `vans = 0`                               | Vehicle assigned to Zone C            |
| Emergency `Y / N`            | Set `assigned = False`                                                | Remaining capacity of Zone A          |
|                              | Process vehicles using `For i = 1 to n`                               | Remaining capacity of Zone B          |
|                              | Input vehicle type, category and permit                               | Remaining capacity of Zone C          |
|                              | Check whether the vehicle input is valid                              | Vehicle rejected with reason          |
|                              | If input is invalid, ask the user to re-enter it                      | Total accepted vehicles               |
|                              | Check whether `Permit = Y`                                            | Total rejected vehicles               |
|                              | If `Permit = Y`, input emergency status                               | Total vehicles processed              |
|                              | Check whether `Emergency = Y`                                         | Cars successfully parked              |
|                              | If permit/emergency conditions are not satisfied, reject the vehicle  | Bikes successfully parked             |
|                              | If `Category = F`, check Zone A                                       | Vans successfully parked              |
|                              | If `Category = S`, check Zone C                                       | Zone A occupancy                      |
|                              | If `Category = G`, check Zone B                                       | Zone B occupancy                      |
|                              | For a van, check for 2 available spaces                               | Zone C occupancy                      |
|                              | For a car or bike, check for 1 available space                        | Zone with maximum occupancy           |
|                              | For Zone A: check `A + 2 <= capA` for a van                           | Total parking occupancy               |
|                              | For Zone A: check `A + 1 <= capA` for a car/bike                      | Total parking capacity                |
|                              | For Zone B: check `B + 2 <= capB` for a van                           | Parking summary                       |
|                              | For Zone B: check `B + 1 <= capB` for a car/bike                      | Entire parking facility full/not full |
|                              | For Zone C: check `C + 2 <= capC` for a van                           |                                       |
|                              | For Zone C: check `C + 1 <= capC` for a car/bike                      |                                       |
|                              | If space is available in Zone A, update `A` and set `assigned = True` |                                       |
|                              | If space is available in Zone B, update `B` and set `assigned = True` |                                       |
|                              | If space is available in Zone C, update `C` and set `assigned = True` |                                       |
|                              | If no space is available, store the appropriate rejection reason      |                                       |
|                              | If `assigned = True`, increase `accepted` by 1                        |                                       |
|                              | If `assigned = False`, increase `rejected` by 1                       |                                       |
|                              | If vehicle is a car, increase `cars` by 1                             |                                       |
|                              | If vehicle is a bike, increase `bikes` by 1                           |                                       |
|                              | If vehicle is a van, increase `vans` by 1                             |                                       |
|                              | Calculate `totalOccupancy = A + B + C`                                |                                       |
|                              | Calculate `totalCapacity = capA + capB + capC`                        |                                       |
|                              | Compare `A`, `B`, and `C` to find maximum occupancy                   |                                       |
|                              | Check whether `totalOccupancy = totalCapacity`                        |                                       |

##### PAC Chart:
| **P — Problem**                                            | **A — Analysis**                                                         | **C — Conditions / Calculations**                                                               |
| ---------------------------------------------------------- | ------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------- |
| Process the vehicles entering the campus parking facility. | The program takes the total number of vehicles `n` as input.             | `For i = 1 to n`                                                                                |
| Validate the information entered for each vehicle.         | Vehicle type is entered as `C / B / V`.                                  | Vehicle type must be `C`, `B`, or `V`.                                                          |
| Check the vehicle category.                                | Category is entered as `F / S / G`.                                      | Category must be `F`, `S`, or `G`.                                                              |
| Check the permit status of the vehicle.                    | Permit is entered as `Y / N`.                                            | Permit must be `Y` or `N`.                                                                      |
| Check the emergency status when required.                  | Emergency status is entered as `Y / N`.                                  | Emergency must be `Y` or `N`.                                                                   |
| Handle invalid input.                                      | If the entered information is invalid, the input is entered again.       | Display: **"Invalid Input. Please re-enter."**                                                  |
| Check whether the vehicle has a valid permit.              | If `permit = Y`, the emergency status is checked.                        | If `permit = N`, the vehicle is rejected.                                                       |
| Check emergency status.                                    | If the permit is valid, emergency information is entered.                | If `emergency = Y`, the vehicle proceeds for allocation.                                        |
| Reject a vehicle when it cannot be assigned.               | The vehicle is marked as not assigned.                                   | `assigned = False`                                                                              |
| Assign vehicles to the appropriate parking zone.           | Vehicles are assigned according to their category.                       | `F → Zone A`, `S → Zone C`, `G → Zone B`                                                        |
| Allocate a Category F vehicle.                             | Category `F` vehicles are checked for Zone A.                            | Van: `A + 2 <= capA`; Other vehicle: `A + 1 <= capA`                                            |
| Allocate a Category S vehicle.                             | Category `S` vehicles are checked for Zone C.                            | Van: `C + 2 <= capC`; Other vehicle: `C + 1 <= capC`                                            |
| Allocate a Category G vehicle.                             | Category `G` vehicles are checked for Zone B.                            | Van: `B + 2 <= capB`; Other vehicle: `B + 1 <= capB`                                            |
| Check the available space in Zone A.                       | The current occupancy of Zone A is compared with its capacity.           | `capA = 20`                                                                                     |
| Check the available space in Zone B.                       | The current occupancy of Zone B is compared with its capacity.           | `capB = 40`                                                                                     |
| Check the available space in Zone C.                       | The current occupancy of Zone C is compared with its capacity.           | `capC = 15`                                                                                     |
| Update Zone A occupancy.                                   | If space is available, the vehicle is assigned to Zone A.                | `A = A + 1` or `A = A + 2`                                                                      |
| Update Zone B occupancy.                                   | If space is available, the vehicle is assigned to Zone B.                | `B = B + 1` or `B = B + 2`                                                                      |
| Update Zone C occupancy.                                   | If space is available, the vehicle is assigned to Zone C.                | `C = C + 1` or `C = C + 2`                                                                      |
| Mark the vehicle as successfully assigned.                 | After successful allocation, the assigned status is changed.             | `assigned = True`                                                                               |
| Store the reason when space is unavailable.                | If the required space is not available, a rejection reason is stored.    | `reason = "no available space"`                                                                 |
| Store the reason for Zone B.                               | If Zone B has no available space, the reason is specified.               | `reason = "no available space in zone B"`                                                       |
| Store the reason for Zone C.                               | If Zone C has no available space, the reason is specified.               | `reason = "no available space in zone C"`                                                       |
| Count accepted vehicles.                                   | When a vehicle is successfully assigned, the accepted count increases.   | `accepted = accepted + 1`                                                                       |
| Count rejected vehicles.                                   | When a vehicle is not assigned, the rejected count increases.            | `rejected = rejected + 1`                                                                       |
| Count successfully parked cars.                            | If the assigned vehicle is a car, the car count increases.               | `cars = cars + 1`                                                                               |
| Count successfully parked bikes.                           | If the assigned vehicle is a bike, the bike count increases.             | `bikes = bikes + 1`                                                                             |
| Count successfully parked vans.                            | If the assigned vehicle is a van, the van count increases.               | `vans = vans + 1`                                                                               |
| Display the assigned parking zone.                         | After successful allocation, the assigned zone is displayed.             | Display **"Vehicle assigned to Zone A/B/C"**                                                    |
| Display remaining capacity of Zone A.                      | Remaining capacity is calculated by subtracting occupancy from capacity. | `capA - A`                                                                                      |
| Display remaining capacity of Zone B.                      | Remaining capacity is calculated by subtracting occupancy from capacity. | `capB - B`                                                                                      |
| Display remaining capacity of Zone C.                      | Remaining capacity is calculated by subtracting occupancy from capacity. | `capC - C`                                                                                      |
| Display rejected vehicle information.                      | If the vehicle is not assigned, its rejection reason is displayed.       | Display **"Vehicle rejected: reason"**                                                          |
| Calculate total parking occupancy.                         | The occupancy of all three zones is added.                               | `totalOccupancy = A + B + C`                                                                    |
| Calculate total parking capacity.                          | The capacities of all three zones are added.                             | `totalCapacity = capA + capB + capC`                                                            |
| Display the parking summary.                               | The program displays the overall parking information.                    | Accepted, rejected, processed, cars, bikes and vans                                             |
| Display Zone A information.                                | Zone A occupancy and remaining capacity are displayed.                   | `A`, `capA - A`                                                                                 |
| Display Zone B information.                                | Zone B occupancy and remaining capacity are displayed.                   | `B`, `capB - B`                                                                                 |
| Display Zone C information.                                | Zone C occupancy and remaining capacity are displayed.                   | `C`, `capC - C`                                                                                 |
| Find the zone with maximum occupancy.                      | The occupancy of Zones A, B and C is compared.                           | Compare `A`, `B` and `C`                                                                        |
| Handle equal maximum occupancy.                            | If the maximum occupancy is equal between zones, a tie is displayed.     | **"There is a tie for Max Occupancy"**                                                          |
| Check whether the entire parking facility is full.         | Total occupancy is compared with total capacity.                         | If `totalOccupancy = totalCapacity`                                                             |
| Display the final parking status.                          | The program displays whether the entire facility is full or not.         | **"Entire Campus Parking Facility is Full"** / **"Entire Campus Parking Facility is Not Full"** |



