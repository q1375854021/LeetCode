import sys
import os
import subprocess

def build(options, filename):
    # 拼接 g++ 命令
    command = f"g++ {options} {filename}.cpp -o {filename}"
    
    # 检查文件是否存在
    if not os.path.exists(f"{filename}.cpp"):
        print(f"Error: {filename}.cpp does not exist.")
        return

    # 执行编译命令
    try:
        print(f"Running: {command}")
        result = subprocess.run(command, shell=True, check=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"Compilation failed:\n{e.stderr}")

# 检查输入参数
if len(sys.argv) < 2:
    print("Usage: python make.py [-O0 | -O3] [-g] <filename>")
    sys.exit(1)

# 获取参数
args = sys.argv[1:]

# 检查优化选项和调试选项
options = []
filename = None

for arg in args:
    if arg in ("-O0", "-O1", "-O2", "-O3"):  # 优化级别
        options.append(arg)
    elif arg == "-g":  # 调试信息
        options.append(arg)
    else:  # 文件名
        filename = arg

# 如果没有提供优化选项，默认使用 -O3
if not any(opt in options for opt in ("-O0", "-O1", "-O2", "-O3")):
    options.append("-O3")

# 检查文件名是否存在
if not filename:
    print("Error: Please provide a file name to compile.")
    sys.exit(1)

# 拼接编译选项
options_string = " ".join(options)

# 调用编译函数
build(options_string, filename)
