# AMD_Summer_School
## 简介
本项目为2022AMD暑期学校的HLS作业。使用HLS实现在PYNQ上的DFT加速。
## 优化
1. 循环交换：我们将内外侧循环交换,这样可以除去数据依赖。
2. 循环展开：将内循环通过Unroll展开，增加吞吐量。
## 优化结果
将Latency从42.363ms提高到了10.762ms
