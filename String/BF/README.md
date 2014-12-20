###BF算法
#####Brute-Force算法的基本思想是：

1. 从目标串s 的第一个字符起和模式串t的第一个字符进行比较，若相等，则继续逐个比较后续字符，否则从串s 的第二个字符起再重新和串t进行比较。

1. 依此类推，直至串t 中的每个字符依次和串s的一个连续的字符序列相等，则称模式匹配成功，此时串t的第一个字符在串s 中的位置就是t 在s中的位置，否则模式匹配不成功。

Brute-Force算法的实现
![](https://github.com/312998164/DataStructure/blob/master/Images/brute_force.jpg)
