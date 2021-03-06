### release 1.0.1

- 修复了中途退出后屏蔽屏幕未隐藏的bug
- 屏蔽了暂停状态下的暂停请求

### release 1.0.0

- fallingMode下暂停后将屏蔽屏幕以防止作弊
- 更新getUpdate.py中的下载链接

### beta 2.2.0

- 修复无法正常调用getUpdate的bug
- 添加设置界面
- 删除主界面layout，修复小bug

### beta 2.1.0

- 为endlessmode添加背景图片
- 删除debug代码
- 为endlessmode和stagemode添加暂停功能
- 版本号从配置文件读取
- 多项游戏数据从配置文件读取
- 修改完善README
- 为fallingMode下文字添加了描边
- 修改了logo
- 添加了自动检查版本更新

### beta 2.0.1

- 将升级要求通过配置文件读取

### beta 2.0.0

- 添加了新游戏模式：falling mode
- 修改readme
- 修改了窗口大小以及键盘尺寸

### beta 1.1.0

- 重构游戏模式代码

### beta 1.0.0

- 美化了界面
- 删除了TopStanding界面
- 优化了endless模式计分规则
- 添加了教程按钮

### alpha 2.1.0

- 添加了About界面
- 部分窗口设置从.ini读入
- 修正了Endless模式下按错按键时间未恢复的bug

### alpha 2.0.0

- 添加了Endless模式
- 重构部分代码
- 更新README

### alpha 1.0.3

- 添加按错按键的警告提示

### alpha 1.0.2

- 删除Label固定大小以适应在某些环境下文字显示不全的问题

### alpha 1.0.1

- 更改了默认显示字体
- 修正了计时器问题

### 2020.11.18 11:00(UTC+8) Chen Yiming

- 添加了界面刷新线程与计时器
- 添加了记录游戏状态的gamestate变量与枚举
- 添加了游戏结束后的cleanUp操作
- 内测alpha1.0.0发布

### 2020.11.18 1:45(UTC+8) Chen Yiming

- 完成了Stage模式的关卡选择界面
- 完成了基本的游戏功能
- 添加了生命值系统

### 2020.11.17 13:40(UTC+8) Chen Yiming

- 完善了keyboard设计
- 为堆叠窗口添加了枚举变量
- 添加了闯关模式文件夹，初步设计闯关模式

### 2020.11.16 17:40(UTC+8) Chen Yiming

- 将ui_mainWidget.h中声明与实现分离
- 更改了changelog与README编码为utf-8
- 添加了模式选择界面
- 添加了key类与keyboard类

### 2020.11.16 13:47(UTC+8) Chen Yiming

- 添加了主菜单