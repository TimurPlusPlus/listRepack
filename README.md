﻿# List repack
![](http://savepic.ru/8559048.png)
Проанализируем сложность алгоритма:  
В первом цикле перебираем n элементов: Т(n).  
Далее, несколько операций по Т(1).  
И последний цикл – проходим из центра к краю, т.е. имеем T(n/2).  

Итого T(n + n/2) = T(3n/2) = O(n). 
