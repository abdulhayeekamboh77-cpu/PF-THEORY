# Question No 3: Class Result Processing
## IPO Chart:
| **Input** | **Process** | **Output** |
|---|---|---|
| `n` = Number of students | Set `i = 1` | **Distinction** |
| `m1, m2, m3, m4, m5` = 5 subject marks | Calculate `Avg = (u1+u2+u3+u4+u5) / 5` | **Pass** |
|  | Check `Avg > 80` | **Fail** |
|  | Check `Avg ≥ 60` | **Fail due to Subject Deficiency** |
|  | Check whether any subject mark `< 33` | **Result** |
|  | Increment `i = i + 1` |  |
|  | Repeat until `i > n` |  |
