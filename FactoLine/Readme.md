# factoLine

## 简介
这是一个沙盒游戏，在这个世界中有矿物，通过采矿机、熔炉等物品来进行自动化生产

矿物： 铁矿、铜矿
物品： 采矿机、熔炉、传送带



## 制作思路
界面 采用tick和渲染同步 
#ScreenHandler
Screen << ScreenHandler

GameBody 、TextWindow 和 ItemWindow 通过 ScreenHandler 排版渲染渲染

GameBody 、TextWindow 和 ItemWindow 继承 Renderable

ScreenHandler 通过多态渲染Renderable子类

注：最开始的时候要手动调整界面大小


### World
这是个类
需要存储: 矿物位置、机器位置、物品位置


世界大小初步定在和窗口等大

### GenerateWorld
通过随机生成的方法 来生成矿物的位置

矿物生成思路：先随机找点 然后

# WorldHandler
两个静态函数
分别存和读世界

# Player
这个类要存储玩家位置 存储物品栏 物品栏静态

## Utils
### Location
struct 存坐标

