# AMD_Summer_School
## About The Project
Using HLS to to achieve discrete Fourier variations.  

**Directory structure**
│  **README.md**  - introduce the project
│  
├─**ipython/**  -  Run on PYNQ 
│      DFT.ipynb
│      
├─**overlay/** -  bitstream from vivado 
│      DFT.bit
│      DFT.hwh
│      
└─**src/** - source files for HLS project 
        coefficients1024.h
        DFT.cpp
        DFT.h
        dft_test.cpp
        out.gold.dat
