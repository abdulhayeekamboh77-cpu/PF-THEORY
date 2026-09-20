# Smart Campus Parking and Access Management System
## PAC Chart
| Given Data | Processing Required | Required Result |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Number of vehicles `n` | Set the loop to process each vehicle one at a time. | Total vehicles to be processed |
| Vehicle type `C / B / V` | Validate vehicle type. Accept only Car, Bike or Van. | Valid vehicle type / Invalid input |
| User category `F / S / G` | Validate category. Accept only Faculty, Student or Visitor/Guest. | Valid category / Invalid input |
| Parking permit `Y / N` | Validate permit value. | Valid permit / Invalid input |
| Emergency status `Y / N` | Validate emergency status. | Valid emergency status / Invalid input |
| Vehicle type + category + permit | Check whether the entered combination is valid before processing. | Vehicle accepted for processing / Re-enter information |
| Emergency status | If emergency = `Y`, allow vehicle to enter regardless of permit status. | Emergency vehicle allowed |
| Non-emergency + permit `N` | Reject vehicle because it does not have a valid permit. | `Rejected — Invalid Permit` |
| Faculty + valid permit | Assign Faculty vehicle to Zone A if sufficient space is available. | Vehicle assigned to Zone A |
| Student + valid permit | Assign Student vehicle to Zone B if sufficient space is available. | Vehicle assigned to Zone B |
| Visitor + valid permit | Assign Visitor vehicle to Zone C if sufficient space is available. | Vehicle assigned to Zone C |
| Student + Van | If Zone B is unavailable, check Zone C for available space. | Zone B assignment / Zone C redirection / Rejection |
| Faculty + Van | Check whether sufficient space is available in Zone A. | Zone A assignment / Rejection |
| Student + Bike | Check Zone B capacity. | Bike assigned to Zone B / Rejection |
| Faculty + Bike | Check Zone A capacity. | Bike assigned to Zone A / Rejection |
| Visitor + Car/Bike | Check Zone C capacity. | Vehicle assigned to Zone C / Rejection |
| Visitor + Van | Check whether at least 2 spaces are available in Zone C. | Van assigned to Zone C / Rejection |
| Vehicle type `V` (Van) | Required parking capacity = 2 spaces. | 2 spaces reserved |
| Vehicle type `C / B` | Required parking capacity = 1 space. | 1 space reserved |
| Zone A capacity | Compare required spaces with available Zone A capacity. | Vehicle can / cannot use Zone A |
| Zone B capacity | Compare required spaces with available Zone B capacity. | Vehicle can / cannot use Zone B |
| Zone C capacity | Compare required spaces with available Zone C capacity. | Vehicle can / cannot use Zone C |
| Vehicle successfully assigned | Increase occupied spaces according to vehicle type. | Updated zone occupancy |
| Vehicle successfully assigned | Decrease remaining capacity according to required spaces. | Remaining capacity of assigned zone |
| Accepted vehicle | Increase accepted vehicle counter. | Updated accepted count |
| Rejected vehicle | Increase rejected vehicle counter. | Updated rejected count |
| Accepted Car | Increase successfully parked car counter. | Updated car count |
| Accepted Bike | Increase successfully parked bike counter. | Updated bike count |
| Accepted Van | Increase successfully parked van counter. | Updated van count |
| No suitable space/zone | Reject vehicle and record the reason. | `Rejected — No Available Space / No Suitable Zone` |
| All vehicles | Continue loop until all `n` vehicles are processed. | Complete parking processing |
| Final occupancy of Zones A, B and C | Compare occupied spaces of all zones. | Zone with highest occupancy |
| Zone capacities + final occupancy | Check whether all available parking spaces are occupied. | Campus parking full / Not full |
| Final counters and zone data | Generate parking summary. | Total processed, accepted, rejected, cars, bikes, vans, occupancy and remaining capacity |
