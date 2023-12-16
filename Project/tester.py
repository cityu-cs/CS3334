import os
import time
import matplotlib.pyplot as plt

PROGRAMS = 4
TESTS = 7

def main():
    os.system("mkdir output")
    result = [[0 for _ in range(TESTS + 1)] for _ in range(PROGRAMS + 1)]

    for program in range(1, PROGRAMS + 1):
        os.system(f"g++ -std=c++11 -O2 {program}.cpp -o output\\{program}.exe")
        for test in range(1, TESTS + 1):
            start = time.time()
            os.system(f"output\\{program}.exe < tests\\{test}.in > output\\{program}_{test}.out")
            end = time.time()
            result[program][test] = end - start
    
    with open("result.csv", "w") as f:
        f.write("Program\\Test")
        for test in range(1, TESTS + 1):
            f.write(f",{test}")
        f.write("\n")
        for program in range(1, PROGRAMS + 1):
            f.write(f"{program}")
            for test in range(1, TESTS + 1):
                f.write(f",{result[program][test]:.6f}")
            f.write("\n")
    
    x = list(range(1, TESTS + 1))
    y = [[result[program][test] for test in range(1, TESTS + 1)] for program in range(1, PROGRAMS + 1)]
    legend = [f"Approach {program}" for program in range(1, PROGRAMS + 1)]
    colors = ["red", "blue", "green", "orange"]
    for i in range(PROGRAMS):
        plt.plot(x, y[i], color=colors[i], label=legend[i])
    plt.ylim(bottom=0)
    plt.xlabel("Tests")
    plt.ylabel("Time (s)")
    plt.legend()
    plt.title("Running Time of Different Approaches on Different Tests")
    plt.savefig("result.png")

if __name__ == '__main__':
    main()
