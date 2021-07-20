from cyaron import *
from random import *
from cyaron.graders import CYaRonGraders
test = 1
while True:
    io = IO(file_prefix="data")
    n = randint(2, 6)
    k = randint(1, n)
    io.input_writeln(n, k)
    for i in range(n):
        io.input_writeln(randint(0, 5), randint(0, 5))
    
    Compare.program("164D.exe",input=io,std_program="164Dstd.exe")
    print("Passed Test", test)
    test += 1
