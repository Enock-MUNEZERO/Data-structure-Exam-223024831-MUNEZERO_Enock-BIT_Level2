import heapq

class Freelancer:
    def __init__(self, priority, name):
        self.priority = priority
        self.name = name

    def __lt__(self, other):
        return self.priority < other.priority

def heap_sort(freelancers):
    heap = []
    for freelancer in freelancers:
        heapq.heappush(heap, freelancer)
    
    sorted_freelancers = []
    while heap:
        sorted_freelancer = heapq.heappop(heap)
        sorted_freelancers.append(sorted_freelancer)
    
    return sorted_freelancers

freelancers = [
    Freelancer(3, 'Alice - Frontend Developer'),
    Freelancer(1, 'Bob - Backend Developer'),
    Freelancer(4, 'Charlie - Graphic Designer'),
    Freelancer(2, 'Dave - Writer')
]

sorted_freelancers = heap_sort(freelancers)

print('Sorted freelancers by priority:')
for freelancer in sorted_freelancers:
    print(f'{freelancer.name} with priority {freelancer.priority}')
