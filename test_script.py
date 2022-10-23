import os

option = input("Choose between:\n\t1. all_tests\n\t2. single_test\n\t3. delete_output\n")

if option == 1:
    os.system('make')
    os.system('mkdir -p output')

    for i in range(1, 6):
        cmd = 'mkdir -p output/Task{}'.format(i)
        os.system(cmd)

    os.system('./bmp_editor < ./input/Task1/input0.txt')
    print("\n")

    for i in range(2, 6):
        for j in range(0, 5):
            cmd = './bmp_editor < ./input/Task{}/input{}.txt'.format(i, j)
            os.system(cmd)

elif option == 2:
    task = input("Choose what test to do:\n")
    os.system('make')
    os.system('mkdir -p output')

    cmd = 'mkdir -p output/Task{}'.format(task)
    os.system(cmd)

    if task == 1:
        cmd = './bmp_editor < ./input/Task{}/input{}.txt'.format(task, 0)
        os.system(cmd)
    else:
        for j in range(0, 5):
            cmd = './bmp_editor < ./input/Task{}/input{}.txt'.format(task, j)
            os.system(cmd)

else:
    cmd = "rm -r ./output"
    os.system(cmd)
    print("All output deleted!")
