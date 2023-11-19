正点原子cmake项目
===
### 简介
移植正点原子的代码过来
使用cmake
### 烧录
1. B0连接到3.3V

2. 烧录程序

   ```
   sudo stm32flash -w build/src/Core/Src/stm32proj.hex /dev/ttyUSB0  -b 115200
   ```

   

3. 清除程序

   ```
   sudo stm32flash -o  /dev/ttyUSB0
   ```

4. 启动
1. B0连接到GND