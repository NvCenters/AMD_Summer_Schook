# AMD_Summer_School
## 简介
本项目为2022AMD暑期学校的HLS作业。使用HLS实现在PYNQ上的DFT加速。
## 优化
1. 循环交换：为了实现循环流水，我们将内外侧循环交换。
2. 循环展开：将内循环通过Unroll展开，增加吞吐量。
## 优化结果
将0.17s提高到0.03s
## 目录结构
│  README.md
│  
├─jupyter
│$\qquad$ DFT.ipynb
│      
├─overlay
│$\qquad$DFT.bit
│$\qquad$DFT.hwh 
│      
├─report
│$\qquad$dft_cosim.rpt
│$\qquad$dft_csynth.rpt
│      
└─src
$\qquad$coefficients1024.h
$\qquad$dft.cpp
$\qquad$dft.h
$\qquad$dft_test.cpp
$\qquad$out.gold.dat
$\qquad$script.tcl
