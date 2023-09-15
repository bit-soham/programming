
scores = []
for i in range(3):
    score = int(input("Scores: "))
    scores += [score]

average = sum(scores) / len(scores)
print(f'Average: {average:.10f}')