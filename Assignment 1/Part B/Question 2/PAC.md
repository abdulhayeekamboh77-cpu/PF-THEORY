# Elevator Stimulation
## PAC Chart
| Given Data | Processing Required | Required Result |
| ---------------------------- | --------------------------------------------------------------------- | ------------------------------------- |
| Current floor `0` | Initialise `currentFloor = 0`. | Elevator starts at Floor 0 |
| Number of requests `n` | Set loop to process `n` floor requests. | All floor requests processed |
| Requested floor | Compare requested floor with `currentFloor`. | Direction determined |
| Requested floor `> currentFloor` | Display `Moving Up`. | `Moving Up` |
| Requested floor `< currentFloor` | Display `Moving Down`. | `Moving Down` |
| Requested floor `= currentFloor` | Display `Doors Opening`. | `Doors Opening` |
| Current floor + requested floor | After each stop, set `currentFloor = requestedFloor`. | Updated current floor |
| Next floor request | Repeat the comparison using the updated current floor. | Movement message for next request |
| All `n` requests | Continue the loop until all requests are processed. | Complete elevator simulation |
