# Question No 2: Elevator Simulation
## IPO Chart:
| **Input** | **Process** | **Output** |
|---|---|---|
| Requested Floor | Set `i = 0` as current floor | Moving Up |
| Number of Floors `n` | Check `i ≤ n` | Moving Down |
|  | Compare Requested Floor with Current Floor | Going Floor / Floor Reached |
|  | If Requested Floor > Current Floor → move up |  |
|  | If Requested Floor < Current Floor → move down |  |
|  | If Requested Floor = Current Floor → floor reached |  |
|  | Increment `i = i + 1` |  |
