from fixedpoint import FixedPoint
from random import random
from tqdm import tqdm

output_file = "tests.txt"

NUM_TESTS = 1e2
MIN_BOUND = -1000
MAX_BOUND = 1000

# Let's say that every line in the file will be a test
# If the line starts with #, it means it is an assignment test
# If the line starts with a +, it means it is an addition test
# If the line starts with a -, it means it is a subtraction test
# If the line starts with a *, it means it is a multiplication test
# If the line starts with a /, it means it is a division test
# If the line starts with a --, it is a unary minus test
# If the line starts with a ==, it is an equality test
# If the line starts with a <, it is a less than test
# If the line starts with a >, it is a greater than test

# If the line starts with a !, it means the next two numbers are the new integer and fractional bits
# Do I need anything else?

def assignment_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        # fixed_num = FXnum(num, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"# {num} {float((FixedPoint(num, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')))}\n")

def addition_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FixedPoint(num1, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        fixed_num2 = FixedPoint(num2, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        summ = float(FixedPoint(float(fixed_num1 + fixed_num2), True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore'))
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"+ {num1} {num2} {summ}\n")

def subtraction_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FixedPoint(num1, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        fixed_num2 = FixedPoint(num2, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        sub = float(FixedPoint(float(fixed_num1 - fixed_num2), True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore'))
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"- {num1} {num2} {sub}\n")

def multiplication_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FixedPoint(num1, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        fixed_num2 = FixedPoint(num2, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        mult = float(FixedPoint(float(fixed_num1 * fixed_num2), True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore'))
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"* {num1} {num2} {mult}\n")

def division_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FixedPoint(num1, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        fixed_num2 = FixedPoint(num2, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        if(fixed_num2 == 0):
            continue
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"/ {num1} {num2} {fixed_num1 / fixed_num2}\n")

def unary_minus_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num =float( FixedPoint(num, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore'))
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"-- {num} {-fixed_num}\n")

def equality_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FixedPoint(num1, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        fixed_num2 = FixedPoint(num2, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"== {num1} {num2} {fixed_num1 == fixed_num2}\n")

def less_than_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FixedPoint(num1, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        fixed_num2 = FixedPoint(num2, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"< {num1} {num2} {fixed_num1 < fixed_num2}\n")

def greater_than_test(n, m):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FixedPoint(num1, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        fixed_num2 = FixedPoint(num2, True, m, n, overflow='wrap', rounding='down', overflow_alert='ignore')
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"> {num1} {num2} {fixed_num1 > fixed_num2}\n")


def test_num(N, M):
    with open(output_file, 'a') as f:
        f.write(f"! {N} {M}\n")
    assignment_test(N, M)
    addition_test(N, M)
    subtraction_test(N, M)
    multiplication_test(N, M)
    #division_test(N, M)
    unary_minus_test(N, M)
    equality_test(N, M)
    less_than_test(N, M)
    greater_than_test(N, M)


#N=6
#custom_fxpt = FXfamily(n_bits=32, n_intbits=N)
for N in tqdm(range(8, 9)):
    for M in tqdm(range(8, 9)):
        #print("N: ", N, "M: ", M)
        test_num(N, M)


"""
# FAIL -130.622 + -211.598 == 125.379 + 44.406 == -86.215 != 169.785
# example
custom_fixed = FixedPoint(-130.622, True, m=8, n=8, overflow='wrap', rounding='down', overflow_alert='ignore')
print(float(custom_fixed))
num2 = FixedPoint(-211.598, True, m=8, n=8, overflow='wrap', rounding='down', overflow_alert='ignore')
print(float(num2))
print(float(FixedPoint(float(custom_fixed + num2), True, m=8, n=8, overflow='wrap', rounding='down', overflow_alert='ignore')))
"""
