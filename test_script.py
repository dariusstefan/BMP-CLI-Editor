import os

option = input("Choose between:\n\t1. all tests\n\t2. single test\n\t3. delete output and executable\n")

if option == 1:
    os.system('make')
    print("\n")
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
            print("\n")

elif option == 2:
    task = input("Choose what task to do:\n")
    os.system('make')
    print("\n")
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
            print("\n")

else:
    cmd = "rm -r ./output"
    os.system(cmd)
    print("All output deleted!")

    os.system("make clean")
