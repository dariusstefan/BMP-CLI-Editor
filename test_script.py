import os

os.system('mkdir -p output');

for i in range(1, 5):
    cmd = 'mkdir -p output/Task{}'.format(i)
    os.system(cmd)

os.system('./bmp_editor < ./input/Task1/input0.txt')

for i in range(2, 5):
    for j in range(0, 4):
        cmd = './bmp_editor < ./input/Task{}/input{}.txt'.format(i,j);
        os.system(cmd)
