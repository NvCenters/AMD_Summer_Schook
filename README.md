# AMD_Summer_School
## 简介
本项目为2022AMD暑期学校的HLS作业。使用HLS实现在PYNQ上的DFT加速。
## 优化
1. 循环交换：我们将内外侧循环交换,这样可以除去数据依赖。
2. 循环展开：将内循环通过Unroll展开，增加吞吐量。
## 优化结果
将Latency从42.363ms提高到了10.762ms
## 可改进处
1. 将接口转化为stream，并将DFT拆分成多个函数，使用dataflow来进行优化，提高吞吐量
2. 尝试将数组通过array_partition进行展开，以提高循环展开的并行性，但是效果不明显，有可能是数据接口问题？
3. 数据类型优化，可以将float转化成定点数进行计算，可以将位宽控制在32位。
## tips
1. 由于考研压力较大，故也没有更多时间能够再进一步优化，也是蛮遗憾的。
2. 希望能够多讲一讲如何查看分析Vitis HLS的Synthesis log。
## 文件树
Before_optimization文件夹中是优化前的文件  
DFT_optimize是优化后的文件  
```
│  README.md  
│    
├─Before_optimization  
│  │  Readme.md  
│  │    
│  ├─jupyter  
│  │      DFT_1.ipynb  
│  │        
│  ├─overlay  
│  │      DFT.bit  
│  │      DFT.hwh  
│  │        
│  ├─report  
│  │      dft_csynth.rpt  
│  │        
│  └─src  
│          coefficients1024.h  
│          DFT.cpp  
│          DFT.h  
│          dft_test.cpp  
│          out.gold.dat  
│            
└─DFT_optimize  
    │  Readme.md  
    │    
    ├─jupyter  
    │      DFT.ipynb  
    │      
    ├─overlay  
    │      DFT.bit  
    │      DFT.hwh  
    │        
    ├─report  
    │      dft_cosim.rpt  
    │      dft_csynth.rpt  
    │        
    └─src  
            coefficients1024.h  
            dft.cpp  
            dft.h  
            dft_test.cpp  
            out.gold.dat  
            script.tcl  
```
