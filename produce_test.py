#import numpy as np
#from FixedPoint import FXfamily, FXnum
from spfpm.FixedPoint import FXfamily, FXnum
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

def assignment_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        # fixed_num = FXnum(num, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"# {num} {FXnum(num, fxpt)}\n")

def addition_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FXnum(num1, fxpt)
        fixed_num2 = FXnum(num2, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"+ {num1} {num2} {fixed_num1 + fixed_num2}\n")

def subtraction_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FXnum(num1, fxpt)
        fixed_num2 = FXnum(num2, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"- {num1} {num2} {fixed_num1 - fixed_num2}\n")

def multiplication_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FXnum(num1, fxpt)
        fixed_num2 = FXnum(num2, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"* {num1} {num2} {fixed_num1 * fixed_num2}\n")

def division_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FXnum(num1, fxpt)
        fixed_num2 = FXnum(num2, fxpt)
        if(fixed_num2 == 0):
            continue
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"/ {num1} {num2} {fixed_num1 / fixed_num2}\n")

def unary_minus_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num = FXnum(num, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"-- {num} {-fixed_num}\n")

def equality_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FXnum(num1, fxpt)
        fixed_num2 = FXnum(num2, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"== {num1} {num2} {fixed_num1 == fixed_num2}\n")

def less_than_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FXnum(num1, fxpt)
        fixed_num2 = FXnum(num2, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"< {num1} {num2} {fixed_num1 < fixed_num2}\n")

def greater_than_test(fxpt):
    # use tqdm for loop
    for _ in range(int(NUM_TESTS)):
        # produce a random number
        num1 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        num2 = (random() * (MAX_BOUND - MIN_BOUND)) + MIN_BOUND
        # convert to fixed point
        fixed_num1 = FXnum(num1, fxpt)
        fixed_num2 = FXnum(num2, fxpt)
        # write to file
        with open(output_file, 'a') as f:
            f.write(f"> {num1} {num2} {fixed_num1 > fixed_num2}\n")


def test_num(fxpt, N, M):
    with open(output_file, 'a') as f:
        f.write(f"! {N} {M}\n")
    assignment_test(fxpt)
    addition_test(fxpt)
    subtraction_test(fxpt)
    multiplication_test(fxpt)
    division_test(fxpt)
    unary_minus_test(fxpt)
    equality_test(fxpt)
    less_than_test(fxpt)
    greater_than_test(fxpt)


#N=6
#custom_fxpt = FXfamily(n_bits=32, n_intbits=N)
for N in tqdm(range(1, 33)):
    for M in tqdm(range(1, 33)):
        #print("N: ", N, "M: ", M)
        custom_fxpt = FXfamily(n_bits=N, n_intbits=M)
        test_num(custom_fxpt, N, M)


"""
custom_fixed = FXfamily(n_bits=1, n_intbits=1)
num1 = FXnum(-2689879756739741, custom_fixed)
print(num1)
num2 = FXnum(0.5, custom_fixed)
print(num2)
"""

