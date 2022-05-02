# FactoLine
一个拉生产线的游戏

## 游戏方法


z:放置传送带

x:放置矿机

c:放置虚空洞

v:放置机械臂

f:放置熔炉

## 游戏玩法

采矿机可采出铁矿，通过熔炉烧制后可产生铁板

机械臂可将机器内的物品拿出来，或者放进去

传送带可运输各种货物

## 游戏目标
合成2000个铁板 将铁板输入进虚空洞

## 游戏方法

按下键盘对应机器按键 后按方向键 机器就会朝向你所移动的方向

当按下大写锁定后 会一直放置相同的机器 直到取消锁定（方便放置传送带）

## 游戏结构

每个机器都是继承的Placeable纯虚基类

首先生成World类

World类中有通过多态存储类Placeable的vector

World类中会循环进行tickAll操作

不同的机器在执行tick操作后会有不同的效果

传输物品是通过callAction这个方法，由World类调控物品
