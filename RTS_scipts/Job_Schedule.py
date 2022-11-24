import math

# jobs = [(8,2,10), (6,2,6), (24,3,24), (16,2,16)]
# jobs = [(10,2,7), (20,1.5,14), (30,0.5,21), (40,1.5,28)]
# jobs = [(3,1), (5,1.5), (7,1.25),(9,0.5)]
jobs = [(2,1), (5,2.5)]

# print(f'Question: {jobs}')

abs_jobs = []
execution_time = []
periods = []

for task in jobs:
    length = len(task)
    if length < 2:
        print("Job Feed Error")
    elif length == 2:
        phase = 0
        period = task[0]
        execution = task[1]
        deadline = period
        abs_jobs.append((phase, period, execution, deadline))
    elif length == 3:
        phase = 0
        period = task[0]
        execution = task[1]
        deadline = task[2]
        abs_jobs.append((phase, period, execution, deadline))
    else:
        phase = task[0]
        period = task[1]
        execution = task[2]
        deadline = task[3]
        abs_jobs.append((phase, period, execution, deadline))
    execution_time.append(execution)
    periods.append(period)

print(f'(\u03C6i, Pi, ei, Di): {abs_jobs}')
print("***************************************")


def sched_test(jobs:list):
    print("Schedulability test:")
    print("1. EDF:")
    U = 0
    for j in jobs:
        U +=( j[2]/min(j[3], j[1]))
    print(f"    Utilisation: {U}")
    if U <= 1:
        print("    EDF Schedulable")
    else: 
        print("    EDF Non-schedulable")
    print("2. RM:")
    m = len(jobs)
    Urm = m * ((2 ** (1/m)) - 1)
    print(f"    Urm: {Urm}")
    if U < Urm:
        print("    RM Test Passed as Urm > U")
    else:
        print("    RM Test Failed as Urm < U")
        print("3. Performng Lehoczky’s Schedulability Test ")
        sorted_jobs = sorted(jobs, key = lambda x: x[1])
        print(f'    Sorted Jobs: {sorted_jobs}')
        for idx, job in enumerate(sorted_jobs):
            if idx == 0:
                if job[2] < job[1]:
                    print("    Job 0 is schedulable")
                else:
                    print("    Job 0 is not schedulable")
                    break
            else:
                sum_l = 0
                ei = job[2]
                for id in range(0, idx):
                    pk = sorted_jobs[id][1]
                    ek = sorted_jobs[id][2]
                    x = math.ceil(job[1]/pk) * ek
                    sum_l += x
                sum_l += ei
                if sum_l <= job[3]:
                    print(f"    Job {idx} is schedulable, sum = {sum_l}")
                else:
                    print(f"    Job {idx} is not schedulable, sum = {sum_l}")
  

sched_test(abs_jobs)
print("***************************************")

c1_op = max(execution_time)

# Constrain 1
print(f"Max Execution time = {c1_op}, hence:")
print(f"Constrain 1: f >= {c1_op}")
print("***************************************")

# Constrain 2
c2_op = []

for f in range(1, max(periods) + 1):
# for f in range(c1_op, max(periods) + 1):
    for p in periods:
        if p % f == 0:
            c2_op.append(f)
            break
print(f"Frame size should divide atlease one period")
print(f"Constrain 2: f ~={c2_op}")
print("***************************************")

# Constrain 3

def GCD(x, y):
    while(y):
        x, y = y, x % y
    return abs(x)

def C3_eq(f_list, abs_jobs):
    abs_task_itr_list = []
    print("2f - gcd(f,Pi) <= Di")
    for job in abs_jobs:
        task_itr_list = []
        print( f"<= {job[3]}")
        for f in f_list:
            c3 = ((2 * f) - GCD(f, job[1]))
            if (c3 <= job[3]):
                task_itr_list.append(f)
                print(f"2x({f})-gcd(({f}), {job[1]}) = {c3}")
        abs_task_itr_list.append(task_itr_list)

    return abs_task_itr_list

def IntersecOfSets(arr):
    # Converting the arrays into sets
    sets = []
    for a in arr:
        x = set(a)
        sets.append(x)
    leng = len(sets)
    res_set = sets[0]
    i = 1
    while(i < leng):
        res_set = res_set.intersection(sets[i])
        i += 1
    ret_list = []
    for i in list(res_set):
        if i >= c1_op:
            ret_list.append(i)

    return ret_list


c3_op = C3_eq(c2_op, abs_jobs)

print(f"Constrain 3: {c3_op}")
print("***************************************")

intersection = IntersecOfSets(c3_op)

print(f"From Constrain 1, 2 and 3: {intersection}")

if len(intersection) != 0:
    print(f"min: {min(intersection)}")