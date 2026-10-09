percentages = []

def selection_sort(a):
    for i in range(len(a)-1):
        m = i
        for j in range(i+1, len(a)):
            if a[j] < a[m]:
                m = j
        a[i], a[m] = a[m], a[i]
    return a


def quick_sort(a):
    if len(a) <= 1:
        return a

    p = a[0]
    left = []
    right = []

    for x in a[1:]:
        if x <= p:
            left.append(x)
        else:
            right.append(x)

    return quick_sort(left) + [p] + quick_sort(right)


n = int(input("Enter number of students: "))

for i in range(n):
    percentages.append(float(input("Enter percentage: ")))

print("Original:", percentages)

print("Selection Sort:", selection_sort(percentages.copy()))

percentages = quick_sort(percentages)

print("Quick Sort:", percentages)
print("Top Five Scores:", percentages[-5:][::-1])