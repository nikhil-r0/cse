from itertools import permutations

teachers = ['T1', 'T2', 'T3', 'T4', 'T5']
classes = ['C1', 'C2', 'C3', 'C4', 'C5']

# Mapping of teacher to disallowed classes
not_allowed = {
    'T1': {'C1', 'C2'},
    'T2': {'C1', 'C2'},
    'T3': {'C4', 'C5'},
    'T4': {'C4', 'C5'},
    'T5': {'C3', 'C4', 'C5'},
}

count = 0
for perm in permutations(classes):  # Each permutation is an assignment
    valid = True
    for t, c in zip(teachers, perm):
        if c in not_allowed.get(t, set()):
            valid = False
            break
    if valid:
        count += 1

print(count)  # Output should be 8
