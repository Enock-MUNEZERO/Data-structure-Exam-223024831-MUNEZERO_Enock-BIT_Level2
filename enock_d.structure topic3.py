import heapq

class FreelancerTask:
    def __init__(self, priority, task):
        self.priority = priority
        self.task = task

    def __lt__(self, other):
        return self.priority < other.priority
    
task_queue = []
heapq.heappush(task_queue, FreelancerTask(2, 'Task A'))
heapq.heappush(task_queue, FreelancerTask(1, 'Task B'))
heapq.heappush(task_queue, FreelancerTask(3, 'Task C'))

while task_queue:
    task = heapq.heappop(task_queue)
    print(f'Processing {task.task} with priority {task.priority}')
