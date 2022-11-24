P_JOBS = [(4, 1), (6, 1.5)]
S_JOBS = [(0,8,2), (2,7,0.5), (4,14,1), (9,13,2)]

abs_jobs = []
execution_time = []
periods = []
delta = 0
deltas = []
for task in P_JOBS:
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
    delta_i = (execution/(deadline-phase))
    deltas.append(delta_i)
    delta = delta + delta_i

print(f'(\u03C6i, Pi, ei, Di) of P_JOBS: {abs_jobs}')
print('Density = ei/di-ri')
print(f'\u0394 = SUM({deltas}) = {delta}')
print(f'=> 1-\u0394 = {1-delta} ')
print("***************************************")

release_times = []
abs_deadlines = []
s_execution_times = []
for idx, jobs in enumerate(S_JOBS):
    release_times.append(jobs[0])
    abs_deadlines.append(jobs[1])
    s_execution_times.append(jobs[2])
    delta_i = (s_execution_times[-1]/(abs_deadlines[-1]-release_times[-1]))
    print(f'For Rel Time {jobs[0]} (SJ{idx+1}): {delta_i}')

