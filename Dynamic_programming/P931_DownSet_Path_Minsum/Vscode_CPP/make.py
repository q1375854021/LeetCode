
import sys
import os
import subprocess

# 检查是否有足够的参数传入
if len(sys.argv) >= 2:
    # 第一个参数是脚本自身的名称，因此我们从第二个参数开始获取输入
    input_value = sys.argv[1]
else:
    print("请在命令行中提供一个参数。")
    
match input_value:
    case "clean": os.system("rm -rf build bin")
    case "cmake": os.system("cmake . -B build -G \"MinGW Makefiles\" -DCMAKE_C_COMPILER=D:/Software/Extensions/Mingw/mingw64/bin/gcc.exe -DCMAKE_CXX_COMPILER=D:/Software/Extensions/Mingw/mingw64/bin/g++.exe")
    case "build": os.system("cmake --build build --config Debug")
    case "release": os.system("cmake --build build --config Release")
    case "exe" : os.system(os.path.abspath("./bin/main.exe > result.txt"))  #相对路径转化为绝对路径
    case _: print("请输入正确的指令")
