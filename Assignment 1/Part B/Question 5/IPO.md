# Question No 5: Smart Campus Parking And Access Management System
## IPO Chart:
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

