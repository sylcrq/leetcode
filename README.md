leetcode
========

对[leetcode算法题](https://oj.leetcode.com/problems/)的C++实现

1. **通过Git Submodule管理依赖的两个子项目gmock和gtest**

  * 项目clone完成后运行下面两行命令

  * git submodule init

  * git submodule update

2. **开发环境**

  * Ubuntu 14.04 LTS

  * gcc version 4.8.2

3. **目录结构**

  * **abstract_data_types/** 目录下是一些公共数据结构(链表, 二叉树等)的实现

  * **other/** 目录下是其他一些算法问题(快速排序, 并查集等)的实现

  * **unit_test/** 目录下是单元测试代码([google test](http://code.google.com/p/googletest/), [google mock](http://code.google.com/p/googlemock/))

PS: 在刷题过程中, 很多题目的解题思路和方法都参考了这位大神的博客:[水中的鱼](http://fisherlei.blogspot.com)（需要翻墙）, 在此表示感谢!

By syl
