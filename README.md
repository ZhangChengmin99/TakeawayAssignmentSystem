# TakeawayAssignmentSystem version 1.0 项目要求书

## 一 课题任务概述
* 你运行一家外卖快递服务店,负责一个区域内的外卖订单接收和餐食快递.
* 你有一笔启动资金,可以招募外卖骑手帮你送餐,来赚取快递费。
* 但你也会面临风险,本区域的订单你都有义务接收,不能拒绝，若拒单就会被工商部门吊销营业执照;
* 但如果接收多个订单后，因为骑手来不及送达，导致某个订单超时未送达，客户会投诉，你会被罚款。
* 因此,你的任务就是制定聪明的调度策略，避免拒单被吊销营业执照（人工调度在订单高峰期可能会来不及接收），避免因为罚款而破产，并且尽可能赚更多的钱。

## 二 派送区域假设及约定
* 约定1：你负责的外卖派送区域如图所示，该区域包含9*9的房间，每格是一个房间，既可以是下订单的食客家，也可以是接单的餐馆。为了记录每个房间的位置，约定左上角的房间逻辑坐标为(0,0)，右下角房间的逻辑坐标为(8，8)。

* 约定2: 方格之间的8*8条街道是骑手唯一可走的道路；骑手停在方格的上下左右街道，即算抵达。

* 约定3: 每个方格的宽高都一样，即骑手走过每个方格的距离一样，速度也一样，约定为骑手每走过一个方格花费1个时间单位。

![](https://ws2.sinaimg.cn/large/006tNc79ly1g2bi8xy4paj30da0c6jt0.jpg)

## 三 运营规则及约束
* 约束-1：系统开始运营时，你有1000$作为运营资本；
* 约束-2：你必须有骑手才能接单，招聘一位骑手需投资300$; 只要你有钱，骑手数量不限；在系统运营的整个期间，你都可以随时招聘骑手，但必须有足够的钱，不能拖欠；
* 约束-3：你负责的外卖派送区域内，发起的任何订单都必须接收；如果订单发起后，3个时间单位内没有派单给现有骑手，则视为拒单，你将被吊销营业执照，运营终止。
* 约束-4：派单的方式只能是将其按顺序派给指定骑手。派单的操作可以是人工派单，也可以是程序按调度策略自动派单。人工派单的操作比较复杂，需要用鼠标逐个选中现有未处理订单，将其分配给某个骑手。
* 约束-5：所有骑手的初始位置必须是同一位置；但起始位置需要在你的程序中自行设定。骑手初始位置的设定可以在程序中写死，也可以在系统启动时修改设置。注意：如果骑手初始在左上角，那么立刻接到一个(右下角>左上角)的订单时，可能超时。
* 约束-6：每个订单从下单时间开始，要求在30个时间单位内完成服务（先后抵达餐馆和食客家），否则算超时。
* 约束-7：每完成一单且不超时，可收入10$; 若超时完成，客户会投诉导致罚款50$;
* 约束-8：无须考虑骑手负载限制，一位骑手可以带无限外卖；但超时未达要按约束-6条处罚；
* 约束-9：负债即破产！一旦破产，即刻停止运营，系统盘点每位骑手的接单数、完成数、超时数。
* 约束-10：系统运营期间，至少每个时间单位更新一次，显示当前钱数、每位骑手的位置、接单数、完成数、超时数。

## 四 基础派单策略
* 策略x-1：首先按下单时间顺序，将新订单放入待处理队列。
* 策略x-2：根据骑手数量，将区域划分为几个子区域，分给每个骑手，注意预先保留一个跨子区域订单骑手。
* 策略x-3：派单时，从待处理队列取出队首订单，判断属于哪个子区域，就分给哪个骑手，分派后此单出待处理队列，加入对应骑手的待送达队列；餐馆和食客不在一个区域的订单，分给跨子区域骑手。
* 策略x-4：当跨区域骑手的待派送队列中元素超过预警值时（例如10个），再分出一个骑手作跨区域骑手，剩下骑手重新划分区域，更改仅对后续订单生效，已分配订单不受影响。注意：预警值是你自己在程序中设定的，根据经验设置。
* 策略x-5：所有单派完后，开始轮流对所有骑手的待派送队列进行优化。优化策略是：取出队首订单，作为当前目标点；计算骑手当前位置和当前目标点的区域范围，然后扫描队列后续订单中的所有可达目标点（见后续解释），筛选出属于此区域内的，设计出合理的行走路线，只要按此路线当前目标点不超时，即可插入到队首目标点之前。

## 五 订单格式及输入输出方式
* 1: 订单的数据格式是一个四元组：(n序号,t下单时间,餐馆坐标,食客坐标);
具体格式规范如下，必须按此规范执行。（注：/表示前后数据分隔的含义，实际中不出现）
/N序号分隔符, / t下单时间分隔符,餐馆坐标x分隔符-餐馆坐标y分隔符,食客坐标x分隔符-食客坐标y回车符/n/

* 2: 订单的输入方式：要求一套程序支持以文本文件格式的输入方式，和鼠标操作的输入方式两种。两种方式不会同时生效。

文件输入方式：系统启动后检查当前目录下是否有标准文件名“sales.txt”,若有则自动进入订单强制文件输入方式。sales.txt文件必须遵从规定的订单数据格式。

a.从文件输入
每个订单一行输入，格式为：
订单编号<空格>下单时间<空格>餐馆横坐标<空格>餐馆纵坐标<空格>食客横坐标<空格>食客纵坐标
在软件系统开发期间，老师会提供几组测试数据（输入文件和参照结果）给同学们，便于大家测试。最后验收的时候，老师会现场给定新的输入文件，来验证各组程序的算法优劣。
![](https://ws2.sinaimg.cn/large/006tNc79ly1g2bi31udfjj30y00iatau.jpg)

b.从键盘输入
格式同文件输入
在控制台用Ctrl-Z键入EOF
读取输入的示例代码

C：while(scanf(“%d%d%d%d%d%d”,&index,&time,&x1,&y1,&x2,&y2)!=EOF)

C++：while(cin>>index>>time>>x1>>y1>>x2>>y2)

![](https://ws1.sinaimg.cn/large/006tNc79ly1g2bi323tfhj30y00hqq3l.jpg)

c．图形界面输入（动画版本）
订单输入均通过点击对应的界面按钮（鼠标）实现。

* 3: 结果输出方式

a.文件输出
文件名为output.txt，每个时间单位更新一次，显示：
1.当前账户金额数
2.每位骑手的位置
3.接单数
4.完成数
5.超时数 
![](https://ws2.sinaimg.cn/large/006tNc79ly1g2bi32c00tj30y00iagq6.jpg)

b.命令行输出
可用纯文字输出，也可用字符图形的效果代替文字形式的骑手坐标输出。力求直观。
![](https://ws2.sinaimg.cn/large/006tNc79ly1g2bi31yr5ij30y00i80uf.jpg)

c.动画输出
在图形窗口中用绘制房间、道路、骑手
动态（状态转移及变化）

## 六 其他重点的规则（补充）
* 1 餐馆和食客的位置是随机出现，可以互相转变；
* 2 派单仅指将任务分配给骑手；
* 3 委派和接收订单不耗时；
* 4 客户下单30个单位时间内派送结束，超时最多60个时长；
* 5 一个订单仅由一个骑手完成，骑手可以重叠；
* 6 文件格式一次性得到所有数据，全局性优化，图形界面不考察全局考虑；
* 7 骑手一个时间单位走过相当于两个单位（十字路口不算时间）；
* 8 不得辞退骑手，最终计算资产不算骑手价值；

## 七 版本要求与结果评比
* 版本一：文件版本
目标1：设计订单数据结构和队列数据结构；实现文件读取模块；选定两种调度算法，实现并比较；实现文件命令行输出模块。（第12周）。
目标2：集成测试，形成完整的第一版本；比对各个测试数据的结果并调优（第13周验收）。
* 版本二：动画版本
在版本一基础上，新增功能：图形界面输入，动画输出。形成完整的第二版本（*第16周验收*）
* 结果评比
所有参与此课题开发的小组将会得到结果：
外卖运营运行时间（不破产、不被吊销执照）、完成的订单数（送达）、收益资金，三个值按一定权重进行评比，形成一个排行榜。
成绩会基于这个排行榜得分。另外再综合软件的扩展功能、程序代码结构、小组协作度等附加项，形成最终分数。

