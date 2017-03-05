#!/usr/bin/env python
# -*- coding: utf-8
# Обработка массивов
A = [5, 14, 3, 0, 27, 2, -11, 5, -9, -6]
s = 0
for j in range(10):
    if A[j] <= A[3] * 2:
        s = s + j
print(s)

# Круги Эйлера
x = 200

P = 1650
M = 1900
L = 1800
PM = 350
PL = 450
ML = 400
OM = M - (PM + ML - x)
SUMMA = P + M + L - PM - PL - ML + x
print(SUMMA)
